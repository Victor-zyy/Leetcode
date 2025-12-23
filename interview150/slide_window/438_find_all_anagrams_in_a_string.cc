#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define METHOD1 0
#define METHOD2 1
        
#if METHOD1
/**
 * METHOD1: slide window + hashset
 */
class Solution {
private:
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(); 
        int k = p.size();
        if (n < k) {
            return {};
        }

        vector<int> s_map(26, 0);
        vector<int> p_map(26, 0);
        vector<int> ans;

        for (const auto &p_ch : p)
        {
            p_map[p_ch - 'a']++;
        }

        for (int i = 0; i < k; i++) {
            s_map[s[i] - 'a']++;
        }
        if (p_map == s_map){
            ans.push_back(0);
        }
        for (int i = 1; i <= n - k; i++)
        {
            s_map[s[i - 1] - 'a']--;
            s_map[s[i - 1 + k] - 'a']++;
            if (s_map == p_map){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
#elif METHOD2

/**
 * METHOD2: optimize the space complexity
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(); 
        int k = p.size();
        if (n < k) {
            return {};
        }
        vector<int> ans;
        vector<int> count(26,0);
        int differ = 0;
        for (int i = 0; i < k; i++)
        {
            ++count[s[i] - 'a'];    
            --count[p[i] - 'a'];    
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i]) {
                ++differ;
            }
        }
        
        if (differ == 0) {
            ans.push_back(0);
        }
        
        for (int i = 0; i < n - k; i++)
        {
            if (count[s[i] - 'a'] == 1) {
                --differ;
            } else if (count[s[i] - 'a'] == 0) {
                ++differ;
            }

            --count[s[i] - 'a'];

            if (count[s[i + k] - 'a'] == -1) {
                --differ;
            } else if (count[s[i + k] - 'a'] == 0) {
                ++differ;
            }
            
            ++count[s[i + k] - 'a'];

            if (differ == 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
#endif


int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution mysolve;
    mysolve.findAnagrams(s, p);

}