#include <vector> 
using namespace std;

// Greedy Algorithem -- Partial Solution to get the global Solution

#define METHOD1 0
#define METHOD2 1
#if METHOD1
/**
 * METHOD1: Reverse Search
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int position = nums.size() - 1;
        int steps = 0;
        while (position > 0)
        {
            for( int i = 0; i < position; i++ ){
                if( i + nums[i] >= position ) // the leftest from the position
                {
                    steps++;
                    position = i;
                    break;;
                }
            }
        }
        return steps; 
    }
};
#elif METHOD2


/**
 * METHOD2: 
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int max_far = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if( max_far >= i ){
                max_far = max(max_far, i + nums[i]);
                if( i == end ){ // actaully jump is not what we think real jump
                    end = max_far;
                    steps++;
                }
            }
        }
        return steps; 
    }
};

#endif