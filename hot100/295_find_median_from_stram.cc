#include <vector>
#include <queue>
#include <set>

using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: priority_queue
 */
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;
public:
    MedianFinder() {
    }
    void addNum(int num) {
        if(queMin.empty() || num <= queMin.top()){
            queMin.push(num);
            // why this one?
            if( queMax.size() + 1 < queMin.size() ){
                queMax.push(queMin.top());
                queMin.pop();
            }
        }else{
            queMax.push(num);
            if(queMax.size() > queMin.size()){
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
       if( queMin.size() > queMax.size() ){
            return queMin.top();
       }else{
            return (queMax.top() + queMin.top()) / 2.0;
       }
    }
};
#elif METHOD2

/**
 *  METHOD2: multiset and double pointer
 *  multiset dynamically sort in order (ascending order)
 */
class MedianFinder {
private:
    multiset<int> nums;
    multiset<int>::iterator left,right;
public:
    MedianFinder(): left(nums.end()), right(nums.end()) {
    }
    void addNum(int num) {
        const size_t n = nums.size();
        nums.insert(num);
        if(!n){
            left = right = nums.begin();
        }else if( n & 1){ //odd
            if( num < *left ){
                left--;
            }else{
                right++;
            }
        }else{//even
            if( num > *left && num < *right){
                left++;
                right--;
            }else if( num >= *right ){
                left++;
            }else{
                right--;
                left = right;
            }
        }
    }
    
    double findMedian() {
        return (*left + *right) / 2.0;
    }
};
#endif

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */