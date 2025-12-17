#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool placed = false;
        int left = newInterval[0];
        int right = newInterval[1];
        for (const auto inv : intervals){
            if ( inv[0] > right ){
                if ( !placed ){
                    ans.push_back({left, right});   // handle [0,0] [1,5] which newInterval is [0,0]
                    placed = true;
                }
                ans.push_back(inv);
            }else if (inv[1] < left) {
                ans.push_back(inv);
            } else {
                left = min(left ,inv[0]);
                right = max(right ,inv[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right}); // handle [0,0] [1,5] which newInterval is [1,5]
        }
        return ans;
    }
};