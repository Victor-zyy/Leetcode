#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (( right - left ) >> 1);
            if( target == nums[mid] ) return mid;
            if( nums[0] <= nums[mid] ){
                // left is in-order
                if( nums[0] <= target && target < nums[mid] ){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if( target > nums[mid] && target <= nums[nums.size() - 1]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }

            }
        }

        return -1;
    }
};


int main(){

    Solution mysolve;
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    mysolve.search(v, 0);
}
