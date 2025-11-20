#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

/**
 * METHOD1: Dynamic Programming
 * dp[i] = dp[j] && check(s[j..i-1])
 * dp[i] indicates 0 ~ i substring can find word in wordDict or not?
 * [0.....j......i]
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        for( const auto &word : wordDict ){
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++ ){
            for(int j = 0; j < i; j++ ){
                if(dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end() ){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};