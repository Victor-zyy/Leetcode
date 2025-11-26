#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define METHOD1 0
#define METHOD2 1


#if METHOD1
/**
 * METHOD1: HashMap
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> _map;
        for(const auto num : nums){
            _map[num]++;
        }
        int ans;
        for(auto it = _map.begin(); it != _map.end(); it ++){
            if( it->second == 1 ){
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};
#elif METHOD2


/**
 * METHOD2: Exclusive OR (XOR)
 * a XOR a = 0
 * a XOR 0 = a
 * a XOR b XOR c  =  ( a XOR b ) XOR c = a XOR ( b XOR c )
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(const auto e : nums) ret ^= e;
        return ret;
    }
};
#endif