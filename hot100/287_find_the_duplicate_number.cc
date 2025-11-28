#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: Random exceed the time limit
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while (true)
        {
            /* code */
            int duplicate = nums[rand() % nums.size()];
            int cnt = 0;
            for( const auto & num : nums ){
                if( num == duplicate ){
                    cnt++;
                    if( 2 <= cnt ){
                        return num;
                    }
                }
            }
        }
        return -1; 
    }
};
#elif METHOD2

/**
 * METHOD2: Floyd - fast and slow pointer
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow; 
    }
};
#endif