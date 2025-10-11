#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
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
int main(){
  Solution solve;
  vector<string> test {"eat", "tea", "tan", "ate", "nat", "bat"};
  cout << test << endl;
  vector<vector<string>> ans = solve.groupAnagrams(test);
  for(auto &it : ans)
    cout << it << endl;
  return 0;
}
