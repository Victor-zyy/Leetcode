#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0; 
        int index = 0;
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) == map.end()) {
                maxlen = (i - left + 1) > maxlen ? (i - left + 1) : maxlen;
                map[s[i]] = i;
            }else {
                left = map[s[i]] + 1;
                //map.erase(s[i]);
                while (index < left)
                {
                    map.erase(s[index]);
                    index++;
                }
                
                map[s[i]] = i;
            }
        }
        return maxlen;
    }
};

#elif METHOD2

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set_;
        int ans = 0;
        int rk = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (i != 0) {
                set_.erase(s[i - 1]);
            }
            while (rk + 1 < s.size() && !set_.count(s[rk + 1]))
            {
                set_.insert(s[rk + 1]);
                rk++;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
#endif

int main()
{
    string s = "tmmzuxt";
    Solution myslove;
    myslove.lengthOfLongestSubstring(s);
}