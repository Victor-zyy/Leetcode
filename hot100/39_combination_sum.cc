#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
private:
    unordered_map<int, int> visited;
public:
    void backtrace( vector<vector<int>>& ans, vector<int>& canditates, vector<int>&combinations, int target, int index){
        if( target == 0 ){
            ans.push_back(combinations);
            return;
        }else if ( target < 0 )
        {
            return;
        }else if ( index > canditates.size() )
        {
            return;
        }

        backtrace(ans, canditates, combinations, target, index + 1);

        if( index < canditates.size() ){
            target -= canditates[index];
            combinations.push_back(canditates[index]);
            backtrace(ans, canditates, combinations, target, index);
            target += canditates[index];
            combinations.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /**
         * Initial the map
         */

        vector<vector<int>> ans;
        vector<int> comb;
        backtrace(ans, candidates, comb, target, 0);     
        return ans;
    }
};