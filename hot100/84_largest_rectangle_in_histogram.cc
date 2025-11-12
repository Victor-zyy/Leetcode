#include <vector>
#include <stack>

using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * Method1: monotonic stack
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;    
        vector<int> right(heights.size());
        vector<int> left(heights.size());
        int ans = 0;

        // left
        for( int i = 0; i < heights.size(); i++){
            while ( !stk.empty() && heights[i] <= heights[stk.top()])
            {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        // right
        stk = stack<int>();
        for( int i = heights.size() - 1; i >= 0; i-- ){
            while (!stk.empty() && heights[i] <= heights[stk.top()])
            {
                stk.pop();
            }
            right[i] = stk.empty() ? heights.size() : stk.top(); 
            stk.push(i);
        }
        for(int i = 0; i < heights.size(); i++ ){
            ans = max(ans, (right[i] -left[i]-1) * heights[i]);
        }
        return ans;
    }
};

#elif METHOD2
/**
 * METHOD2: optimize monotonic stack
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;    
        vector<int> right(heights.size(), heights.size());
        vector<int> left(heights.size());
        int ans = 0;

        // left
        for( int i = 0; i < heights.size(); i++){
            while ( !stk.empty() && heights[i] <= heights[stk.top()])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        for(int i = 0; i < heights.size(); i++ ){
            ans = max(ans, (right[i] -left[i]-1) * heights[i]);
        }
        return ans;
    }
};
#endif

int main(){
    Solution mysolve;
    vector<int> v = {2, 1, 5, 6, 2, 3};
    mysolve.largestRectangleArea(v);
}