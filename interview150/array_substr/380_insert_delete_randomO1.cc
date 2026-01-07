#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * METHOD1: 
 * VLA --- O(1) time complexity to get random number
 * HashMap --- O(1) time complexity to insert and remove
 */
class RandomizedSet {
private:
    unordered_map<int, int> hmap;
    vector<int> vla;
public:
    RandomizedSet() {
        srand((unsigned int)time(NULL));
    }
    
    bool insert(int val) {
        if (hmap.count(val)) {
            return false;
        }
        int index = vla.size(); /* index -1 when first return is zero ?*/
        vla.emplace_back(val);
        hmap[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if (!hmap.count(val)) {
            return false;
        }
        int index = hmap[val];
        int last = vla.back();
        vla[index] = last;
        hmap[last] = index;
        vla.pop_back();
        hmap.erase(val);    /* erase ? only one element count */
        return true;
    }
    
    int getRandom() {
        int randomindex = rand() % vla.size();
        return vla[randomindex]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main()
{
    unordered_map<int, int> hmap;
    hmap[0] = 1;
    hmap[1] = 1;
    /* why index not index - 1 */
    vector<int> nums = { 1, 2, 9, 0, 2};
    srand((unsigned)time(NULL));
    cout << rand() % nums.size() << endl;

    return 0;
}