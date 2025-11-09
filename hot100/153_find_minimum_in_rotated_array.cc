#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int min = __INT32_MAX__;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if( nums[0] <= nums[mid] ){
                if( min > nums[0] && min > nums[mid] ){
                    min = nums[0];
                }
                left = mid + 1;
            }else{
                if( min > nums[mid] ){
                    min = nums[mid];
                }
                right = mid - 1;
            }
        }

        return min;
    }
};
#elif METHOD2

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int pivot = left + ((right - left) >> 1);
            if( nums[pivot] < nums[right] ){
                right = pivot;
            }else{
                left = pivot + 1;
            }
        }
        return nums[left]; 
        /**
         * 1. why left < right not left <= right ? that is beacause we wanna return nums[left]
         * 2. why right = pivot not pivot - 1; the minimum number is in there we can't skip on it
         * 3. why left = pivot + 1; actually we are in-order and each element in the array is different
         */
    }
};
#endif

int main(){

    Solution mysolve;
    vector<int> v = { 4, 5, 1, 2, 3};
    mysolve.findMin(v);
}