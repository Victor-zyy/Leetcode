#include <vector>
using namespace std;

/**
 * METHOD1: Greedy Algorithem
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
       int rightmost = 0;
       int n = nums.size();
       for( int i = 0; i < n; i++ ){
            if( i <= rightmost ){
                rightmost = max(rightmost, i + nums[i]);
                if( rightmost >= n - 1){
                    return true;
                }
            }
       } 
       return false;
    }
};