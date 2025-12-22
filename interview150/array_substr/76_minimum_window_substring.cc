#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


/**
 * s = "ADOBECODEBANC", t = "ABC"
 * METHOD1: using slide window + hashmap
 */
class Solution {
private:
    unordered_map<char, int> ori, cnt;
public:
    bool check(void) {
        for (const auto &p : ori){
            if (cnt[p.first] < p.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        for (const auto &ch : t)
        {
            ori[ch]++;
        }
        
        int l = 0, r = -1;
        int ansL = -1;
        int len = __INT_MAX__;
         
        while (r < m)
        {
            /* slide window right shift */
            if (ori.find(s[++r]) != ori.end()) { // move the right pointer --- cnt just contains 
                                                 // the information of t substring only r changes
                ++cnt[s[r]];
            }
            while (check() && l <= r) // why l <= r
            {
                /* update the len value */
                if ( r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                /* move the left pointer */
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};