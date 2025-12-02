#include <string>
#include <unordered_map>

using namespace std;

/**
 * METHOD: Using Two HashTables 
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();         
        if( m != n ) return false;
        
        unordered_map<char, int> s_map; 
        unordered_map<char, int> t_map; 
        for (int i = 0; i < n; i++ ) {
            if (s_map.count(s[i]) && s_map[s[i]] != t[i] || t_map.count(t[i]) && t_map[t[i]] != s[i]) {
                return false;
            }else{
                s_map[s[i]] = t[i]; 
                t_map[t[i]] = s[i]; 
            }
        }

        return true;
    }
};