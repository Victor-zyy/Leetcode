#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 1

/**
 * METHOD1: binary search then search n times -- O(n) for the worst
 */
#if METHOD1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};        
        if( !nums.size() ){
            return ans;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if( target <= nums[mid] ){
                right = mid - 1;
                if( target == nums[mid] )
                    ans[0] = mid;
            }else if ( target > nums[mid] )
            {
                left = mid + 1;
            }
        }
        int index = ans[0];
        if( ans[0] != -1 ){
            while ( nums.size() > index && nums[ans[0]] == nums[index])
            {
                index++;
            }
            ans[1] = --index; 
        }
       
        return ans;
    }
};

#elif METHOD2

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower){
        int left = 0; int right = nums.size() - 1; int ans = nums.size();
        while (left <= right)
        {
            int mid = left + (( right - left ) >> 2);
            if( target < nums[mid] || ( lower && target <= nums[mid] )){
                right = mid - 1;
                ans = mid;
            }else {
                left = mid + 1;
            }
        }
        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false) - 1;
        if( leftIndex <= rightIndex && leftIndex < nums.size() && rightIndex < nums.size() && nums[leftIndex] == target && nums[rightIndex] == target){
            return vector<int>{leftIndex, rightIndex};
        }
        return vector<int>{-1,-1};
    }
};

#endif