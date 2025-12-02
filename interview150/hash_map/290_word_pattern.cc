#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        int s_n = s.size();
        vector<string> v_s; 
        int index = 0;
        while ( index < s_n )
        {
            auto pos = s.find(' ', index);
            if( pos == s.npos ) break;
            v_s.emplace_back(s.substr(index, pos - index));
            index = pos + 1;
        }
        v_s.emplace_back(s.substr(index, s.size() - index));
        if( n != v_s.size() ) return false;
        unordered_map<char, string> p_map;
        unordered_map<string, char> s_map;    
        for (int i = 0; i < n; i++ ) {
            if( p_map.count(pattern[i]) && p_map[pattern[i]] != v_s[i] || s_map.count(v_s[i]) && s_map[v_s[i]] != pattern[i] )
            {
                return false;
            }else{
                p_map[pattern[i]] = v_s[i];
                s_map[v_s[i]] = pattern[i];
            }
        }
        return true;
    }
};


int main()
{
    Solution mysolve;
    mysolve.wordPattern("aabb", "abc abc zha adaw");
}