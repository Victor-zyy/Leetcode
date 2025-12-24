#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * find all anagrams in a string -- is quite the same way
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        /**
         * m * n length of sub string
         */
        int m = words.size();
        int n = words[0].size();
        int ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; i++)
        {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; j++)
            {
                ++differ[s.substr(i + j * n, n)];
            }
            
            for (const string &word : words)
            {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }

            /**
             * remove left and add right
             */
            for (int start = i; start < ls - m * n + 1; start += n)
            {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n); // right next n size word
                    if (++differ[word] == 0){
                        differ.erase(word);
                    }
                    word = s.substr(start - n, n); // left one should be removed
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()){
                    res.push_back(start);
                }
            }
        }
        return res;
    }
};


int main()
{
    Solution mysolve;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    mysolve.findSubstring(s, words);
}