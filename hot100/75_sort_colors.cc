#include <vector>

using namespace  std;

#define METHOD1 0
#define METHOD2 0   
#define METHOD3 1

#if METHOD1
/**
 * METHOD1: Single Pointer
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        for(int i = 0; i < nums.size(); i++ ){
            if( 0 == nums[i] ){
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        for(int i = 0; i < nums.size(); i++ ){
            if( 1 == nums[i] ){
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};

#elif METHOD2

/**
 * METHOD2: Double Pointer
 * 当 p0 < p1时，说明在 p0位置已经放置了一个1（因为p1指向1的边界，p0在p1前面）。
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0; int p1 = 0;
        for(int i = 0; i < nums.size(); i++ ){
            if( 1 == nums[i] ){
                swap(nums[i], nums[p1]);
                ++p1;
            }else if( 0 == nums[i] ){
                swap(nums[i], nums[p0]);
                if( p0 < p1 ){
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};

#elif METHOD3

/**
 * METHOD3: Double Pointer only focus on 1 and 2 number
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0;
        int p2 = n - 1;
        for(int i = 0; i <= p2; i++ ){
            while ( i <= p2 && nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};

#endif


int main()
{
    vector<int> num = {2,0,2,1,1,0};
    Solution mysolve;
    mysolve.sortColors(num);
}