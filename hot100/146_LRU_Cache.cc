/**
 * LRU--Least Recently Used
 * get and put O(1) time complexity
 */
#include <unordered_map>
using namespace std;

struct DLinkedNode
{
    int key, val;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode (): key(0), val(0), prev(nullptr), next(nullptr){}
    DLinkedNode (int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int , DLinkedNode*> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;
public:
#if 1
    void moveToHead( DLinkedNode *pos ){
        /**
         * 
         */
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
        /**
         * 
         */
        pos->next = head->next;
        pos->prev = head;
        head->next->prev = pos;
        head->next = pos;
    }
    void addToHead( DLinkedNode *pos ){
        pos->next = head->next;
        pos->prev = head;
        head->next->prev = pos;
        head->next = pos;
    }
    DLinkedNode *removeTail( void ){
        DLinkedNode *end = tail->prev;
        end->prev->next = end->next;
        end->next->prev = end->prev;
        return end;
    }
#endif

    LRUCache(int capacity) {
       size = 0;
       this->capacity = capacity;
       head = new DLinkedNode(); 
       tail = new DLinkedNode(); 
       head->next = tail;
       tail->prev = head;
    }
    
    int get(int key) {
       if( !cache.count(key) ){ //cache.count(key)
            return -1;
       } 
       DLinkedNode *pos = cache[key];
       moveToHead( pos );
       return pos->val;
    }
    
    void put(int key, int value) {
        // no exist
        if(!cache.count(key)){
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if( size > this->capacity ){
                DLinkedNode *mov = removeTail();
                cache.erase(mov->key);
                delete mov;
                --size;
            } 
        }else{
            DLinkedNode *pos = cache[key];
            pos->val = value;
            moveToHead( pos );
        }
    }
};

/**
 * Double-Linked List
 * 
 * remove node
 * 
 * pos->prev->next = pos->next;
 * pos->next->prev = pos->prev;
 * 
 * 
 * hash_map
 * count / at [] totally different things
 */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */