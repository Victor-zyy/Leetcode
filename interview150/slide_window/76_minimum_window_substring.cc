#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
private:
    unordered_map<char, int> s_map, t_map; /* pos - cnt */
public:
    bool check(void) {
        for (const auto &item : t_map)
        {
            if (s_map[item.first] < item.second)
                return false;
        }
        return true; 
    }

    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if ( n > m ){
            return string();
        }
        int left = 0;
        int right = 0;
        int minlen = __INT_MAX__;
        int ansR = 0;
        
        for (const auto &ch : t)
        {
            t_map[ch]++;
        }
        
        while (right < m)
        {
            if (!check())
            {
                s_map[s[right]]++;
            }
            while (check() && left <= right) // why equal ok? because out-of while we add the right pointer
            {
                if (right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    ansR = left;
                }
                s_map[s[left]]--;
                left++;
            }
            right++; 
        }
       
        return minlen == __INT_MAX__ ? string() : s.substr(ansR, minlen);
    }
};


int main()
{
    string s =  "ADOBECODEBANC";
    string t = "ABC";
    Solution mysolve;
    mysolve.minWindow(s, t);
}