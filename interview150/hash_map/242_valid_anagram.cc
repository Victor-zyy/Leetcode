#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if ( m != n ) return false;
        unordered_map<char, int> _map;
        for ( const auto &ch : s ){
            _map[ch]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (_map.count(t[i]) && _map[t[i]] > 0 ){
                _map[t[i]]--;
            }else{
                return false;
            }
        }
       
        return true;
    }
};