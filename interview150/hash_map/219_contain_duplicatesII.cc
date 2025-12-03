#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1 
/**
 * METHOD1: HashMap
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> _map;
        for( int i = 0 ; i < nums.size(); i++ ){
            if( _map.count(nums[i]) ){
                if ( abs(i - _map[nums[i]]) <= k ){
                    return true;
                }
            }
            _map[nums[i]] = i;
        }     
        return false;
    }
};

#elif METHOD2

/**
 * METHOD2: Slide Window
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> _set;
        for (int i = 0; i < nums.size(); i++ ){
            if( i > k ){
                _set.erase(nums[i - k - 1]);
            }
            if( _set.count(nums[i])) {
                return true;
            }
            _set.emplace(nums[i]);
        }

        return false;
    }
};

#endif


int main()
{
    Solution mysolve;
    vector<int> nums = { 1,2,3,1,2,3 };
    mysolve.containsNearbyDuplicate(nums, 2);
}