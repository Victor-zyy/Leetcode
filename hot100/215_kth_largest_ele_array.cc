#include <vector>
#include <queue>

using namespace std;
#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
/**
 * METHOD1: priority_queue innner sight is heap
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
        }      
        while (--k)
        {
            q.pop();
        }
        return q.top(); 
    }
};
#elif METHOD2

/**
 * METHOD2: quick-sort
 */
class Solution {
public:
    int quickselect(vector<int>& nums, int l, int r, int k){
        if( l == r )
            return nums[k];
        int partition = nums[l];
        int i = l - 1;
        int j = r + 1;
        while (i < j)
        {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if( i < j)
                swap(nums[i], nums[j]); 
        }
        if( k<= j) return quickselect(nums, l, j, k);
        else return quickselect(nums, j+1, r, k);
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
};

#elif METHOD3

/**
 * METHOD3: heap-sort
 */
class Solution {
public:
    void maxHeapify(vector<int> &a, int i, int heapsize){
        int l = 2 * i + 1; // left child
        int r = 2 * i + 2; // right child
        int largest = i;
        if( l < heapsize && a[l] > a[largest] ){
            largest = l;
        }
        if( r < heapsize && a[r] > a[largest] ){
            largest = r;
        }

        if( largest != i ){
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapsize);
        }
    }

    void buildMaxHeap(vector<int> &a, int &heapsize){
        for(int i = heapsize / 2 - 1; i >= 0; --i){
            maxHeapify(a, i, heapsize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for(int i = nums.size() - 1; i >= nums.size() - k + 1; --i ){
            swap(nums[0],nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

#endif



int main(){
    Solution mysolve;
    vector<int> v = {3,2,1,5,6,4};
    mysolve.findKthLargest(v, 2);
}