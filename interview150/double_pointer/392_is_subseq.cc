#include <string>
using namespace std;

#define METHOD1  1
#define METHOD2  0

#if METHOD1
/**
 * Double-Pointer
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();     
        int m = t.size();
        int pos = -1;
        int j = 0;
        for (int i = 0; i < n; i++) {
            for (j = pos + 1; j < m; j++) {
                if (s[i] == t[j]) {
                    pos = j;
                    break;
                }
            }
            if ( j == m ) { return false; }
        }
        return true;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();     
        int m = t.size();
        int i = 0; int j = 0;
        while ( i < n && j < m )
        {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;    
    }
};

#elif METHOD2
/**
 * Dp: Dynamic Programming is hard to understand
 */


#endif