#include <vector>
#include <string>
#include <stack>

using namespace std;
#define BASIC 0
#define ADVANCED 1

#if BASIC 0

class Solution {
public:
    bool isValid(string s) {
        int n = s.size(); 
        if( n == 0 ){
            return true;
        }
        stack<char> stk;
        stk.push(s[0]);
        for (size_t i = 1; i < n; i++) // advanced  for( char ch : s )
        {
            if(!stk.empty())
            {
                char brace = stk.top();
                switch( brace ){
                    // advanced switch case using unordered_map -> 
                    case '(':   if(s[i] == ')'){ stk.pop(); } else stk.push(s[i]);
                    break;
                    case '{':   if(s[i] == '}'){ stk.pop(); } else stk.push(s[i]);
                    break;
                    case '[':   if(s[i] == ']'){ stk.pop(); } else stk.push(s[i]);
                    break;
                }
            }else{
                stk.push(s[i]);
            }
       }
       return stk.empty();
    }
};

#elif ADVANCED
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        int n = s.size(); 
        if( n == 0 ){
            return true;
        }
        stack<char> stk;
        stk.push(s[0]);
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for ( char ch : s ) // advanced  for( char ch : s )
        {
            if( mp.count(ch) ){
                if( stk.empty() || stk.top() != mp[ch]){
                    return false;
                }else{
                    stk.pop();
                }
            }else{
                stk.push(ch);
            }
       }
       return true;
    }
};

#endif