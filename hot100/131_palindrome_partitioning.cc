#include <vector>
#include <string>
using namespace std;

#define METHOD1     0
#define METHOD2     1

/**
 * SubString: 
 * Palindrome: a string reads the same from backword and endword
 */

/**
 * METHOD1: backtrace + DP pre-processing
 */
#if METHOD1
class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;
public:
    void backtrace(string &s, int index){
        if( index == s.size() ){
            ret.push_back(ans);
            return;
        }
        for(int j = index; j < n; j++ ){
            if(f[index][j]){
                ans.push_back(s.substr(index, j - index + 1));
                backtrace(s, j + 1);
                ans.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));
        /**
         * Initialize the DP
         */
        // from back to end to ensure f[i+1][j-1] has been calculated for( int i = n - 1; i >= 0; i-- ){
            for( int j = i + 1; j < n; j++ ){
                f[i][j] = ( s[i] == s[j] ) && f[i+1][j-1];
            }
        }
        backtrace(s, 0);
        return ret;
    }
};
#elif   METHOD2

/**
 * METHOD2: backtrace + memorize search( DP thinking )
 */
class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;
public:
    void backtrace(string &s, int index){
        if( index == s.size() ){
            ret.push_back(ans);
            return;
        }
        for(int j = index; j < n; j++ ){
            if( isPalindrome(s, index, j ) == 1 ){
                // j - i + 1 is used for substring
                ans.push_back(s.substr(index, j - index + 1));
                backtrace(s, j + 1);
                ans.pop_back();
            }
        }
    }
    // 记忆化搜索中，f[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
    int isPalindrome(string &s, int i, int j){
        if( f[i][j] ){
            return f[i][j];
        }
        if( i >= j ){
            f[i][j] = 1;
            return 1;
        }

        return f[i][j] = (s[i] == s[j])  ?  isPalindrome(s , i + 1, j - 1) : -1;
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n));
        /**
         * Initialize the DP
         */
        // from back to end to ensure f[i+1][j-1] has been calculated for( int i = n - 1; i >= 0; i-- ){
        backtrace(s, 0);
        return ret;
    }
};

#endif


int main(){

    Solution mysolve;
    string s("aab");
    mysolve.partition(s);
}