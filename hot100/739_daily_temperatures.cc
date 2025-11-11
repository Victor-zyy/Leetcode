#include <vector>
#include <stack>
using namespace std;


/**
 * METHOD1: monotonic Stack
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for (size_t i = 0; i < n; i++)
        {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()])
            {
                int prevIndex = stk.top();
                ans[prevIndex] = i - prevIndex;
                stk.pop();
            }
            stk.push(i); 
        }
        return ans;        
    }
};


int main()
{
    Solution myslove;
    vector<int> v = {73,74,75,71,69,72,76,73};
    myslove.dailyTemperatures(v);
}