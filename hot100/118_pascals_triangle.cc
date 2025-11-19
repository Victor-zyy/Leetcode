#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);    
        ans[0].emplace_back(1);
        if(numRows <= 1){
            return ans;
        }
        ans[1].emplace_back(1);
        ans[1].emplace_back(1);
        for (int i = 2; i < numRows; i++)
        {
            ans[i].emplace_back(1);
            for( int j = 1; j <= i - 1; j++ ){
                int temp = ans[ i - 1 ][j - 1] + ans[i-1][j];
                ans[i].emplace_back(temp);
            }
            ans[i].emplace_back(1);
        }
        return ans;
    }
};


int main(){
    Solution mysolve;
    auto vec = mysolve.generate(5);
}