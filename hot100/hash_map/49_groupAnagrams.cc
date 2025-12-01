#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

#define FIRST_TIME 0
#define SECOND_TIME 1
#if FIRST_TIME
/*
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      // key and value
      // key must be sorted
      vector<vector<string>> ans;
      unordered_map<string, vector<string>> map_;
      for(auto& str_ : strs){
	string str_t = str_;
	sort(str_t.begin(), str_t.end());
	map_[str_t].emplace_back(str_);
      }
      // rearrage to 
      for(auto it = map_.begin(); it != map_.end(); it++)
	ans.emplace_back(it->second);
      return ans;
    }

};
ostream&
operator << (ostream &os, const vector<int>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}

ostream&
operator << (ostream &os, const vector<string>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}
#elif SECOND_TIME

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      //sort       
      unordered_map<string, vector<string>> _map;
      for( auto str: strs ){
        string temp = str;
        sort(temp.begin(), temp.end());
        _map[temp].emplace_back(str);
      }

      vector<vector<string>> ans;
      for(auto it = _map.begin(); it != _map.end(); it++ ){
        ans.emplace_back(it->second);
      }
      return ans;
    }
};

#if METHOD2
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
#endif

#endif

int main(){
  return 0;
}
