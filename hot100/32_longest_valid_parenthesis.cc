#include <vector>
#include <string>
#include <stack>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1


#if METHOD1
/**
 * METHOD1: dynamic programming
 * dp[i] 表示以下标 i 字符结尾的最长有效括号的长度。
 * dp[i]=dp[i−2]+2 ( dp[i] = ')' dp[i-1] = '('
 * dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2
 * s[i] = '(' or ')'
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if( n <= 1)
            return 0;    
        vector<int> dp(n + 1, 0);
        int maxvalid = 0;
        for(int i = 1; i <= n; i++ ){
            if( s[i] == ')' ){
                if( s[i -1] == '(' ){
                    dp[i] = (i >= 2) ? dp[i-2] + 2 : 2;
                }else if( i -dp[i-1] > 0 && s[i - dp[i-1] -1] == '(' ){
                    dp[i] = dp[i-1] + (i - dp[i-1] >= 2 ? dp[i- dp[i-1] - 2] + 2 : 2 );
                }
            }
            maxvalid = max(maxvalid, dp[i]);
        } 

        return maxvalid;
    }
};
#elif METHOD2

/**
 * METHOD2: Using Stack
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxvalid = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < s.size(); i++ ){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    maxvalid = max(maxvalid, i - stk.top());
                }
            }
        }
        return maxvalid;
    }
};

#elif METHOD3

/**
 * METHOD3:  left and right from left->right and then from right->left
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0,maxlength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                left ++;
            else   
                right++;
            if( left == right ){
                maxlength = max(maxlength, right * 2);
            }else if( right > left){
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; --i){
            if( s[i] == '(' ){
                left++;
            }else
                right++;
            if( left == right )
                maxlength = max(maxlength, right * 2);
            else if( left > right ){
                right = left = 0;
            }
        } 
        return maxlength;
    }
};
#endif



int main(){
    Solution mysolve;
    string s = "(()";
    mysolve.longestValidParentheses(s);
}