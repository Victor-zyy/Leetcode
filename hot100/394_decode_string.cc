#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: stack is a thing method not a realization
 * using vector to simulate the first in last out method
 * for vector is great for reverse and iterate from begin and end
 */
class Solution {
private:
    string getDigit(string &s, size_t &ptr){
        string ret = "";
        while (isdigit(s[ptr]))
        {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }
    string getString(vector<string> &v){
        string ret = "";
        for(const auto &s: v ){
            ret += s;
        }
        return ret; 
    }
public:
    string decodeString(string s) {
        string ans;
        vector<string> stk;
        size_t ptr = 0;
        while ( ptr < s.size() )
        { 
            if( isdigit(s[ptr]) ) {
                string digits = getDigit(s, ptr);
                stk.push_back(digits);
            }else if ( isalpha(s[ptr]) || s[ptr] == '[' )
            {
                stk.push_back(string(1, s[ptr++])); // construct function : size char
            }else{
                ++ptr;
                vector<string> sub;
                while ( stk.back() != "[" )
                {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end()); 
                stk.pop_back(); // '[' is pop out of the stack
                int reptime = stoi(stk.back());stk.pop_back();
                string t,o = getString(sub); // t = "", o = getSting
                while (reptime--) // if reptime equals 1
                {
                    t += o;
                }
                stk.push_back(t); 
            }
        }
        return getString(stk);
    }
};
#elif METHOD2
/**
 * METHOD2: recursive compiler theory
 * BNF expression 
 */


class Solution {
private:
    string src;
    size_t ptr;
    int getDigit(){
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr]))
        {
            ret = ret * 10 + src[ptr ++] - '0';
        }
        return ret;
    }
    string getString(){
        if( ptr == src.size() || src[ptr] == ']' ){
            return "";
        }
        char cur = src[ptr]; int reptime = 1;
        string ret;
        if(isdigit(cur)){
            reptime = getDigit();
            ++ ptr; //'['
            string str = getString();
            ++ ptr; // ']'
            // construct string
            while (reptime--)
            {
                ret += str;
            }
        }else if(isalpha(cur)){
            ret = string(1, src[ptr++]);
        }

        return ret + getString();
    }
public:
    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};
#endif


int main()
{
    Solution mysolve;
    mysolve.decodeString("3[a]2[bc]");
}