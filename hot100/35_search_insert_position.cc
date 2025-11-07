#include <vector>
using namespace std;


#define METHOD1 0
#define METHOD2 1
/**
 * METHOD1: O(logn) time complexity
 * binary search sorted by accending order
 */
#if METHOD1
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int index, int n){
        if(index + 1 ==  n){
            if(nums[index] >= target)
                return index;
            else
                return index + 1;
        }
        int mid = ( index + n ) / 2;
        if( nums[mid] > target ){
            return binarySearch(nums, target, index, mid);
        }else{
            return binarySearch(nums, target, mid, n);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size());
    }
};
#elif METHOD2

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0; int right = n - 1; int ans = n;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 2);
            if( target <= nums[mid] ){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans; 
    }
};

#endif


int main(){
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 0;
    Solution mysolve;
    mysolve.searchInsert(nums, target);
}