#include <vector>
#include <string>
#include <memory>


using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
class Solution {
public:
    void backtrace( vector<string>& ans, string& str, int n, int left, int right){
        if( str[0] == '(' && ( left == right ) && ( left == n ) ){
            ans.push_back( str );
            return;
        }else{
            if( left < n ){
                str.push_back('(');
                backtrace(ans, str, n, left + 1, right);
                str.pop_back();
            }
            if( right < left ){ // most important
                str.push_back(')');
                backtrace(ans, str, n, left, right + 1);
                str.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str; 
        backtrace( ans, str, n, 0, 0 );
        return ans;
    }
};
#elif METHOD2

class Solution {
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr)
            return cache[n];
        if (n == 0) {
            cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        } else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts)
                    for (const string& right : *rights)
                        result -> push_back("(" + left + ")" + right);
            }
            cache[n] = result;
        }
        return cache[n];
    }
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};

#endif


int main(){

    Solution mysolve;
    mysolve.generateParenthesis(3);
}