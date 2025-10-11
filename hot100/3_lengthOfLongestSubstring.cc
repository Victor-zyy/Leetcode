#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
/*
Given a string s, find the length of the longest
without duplicate characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

// Case Sensitive?
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> map_;
      int len = 0;
      int left = 0;
      int right = 0;
      for(right = 0; right < s.size(); right++){
	if( (++map_[s[right]]) > 1){
	  while(map_[s[right]] > 1){
	    --map_[s[left++]];
	  }
	}else{
	  int temp = right - left + 1;
	  len = len > temp ? len : temp;
	}
      }
      return len;
    }
};


#if 0
// method hashtable + slide unit
// when we use hashtable the thing we need to confirm is
// <key + value>
// slide unit of two pointers like
// |------------|
// |------------|
// what we find is the substring which is consecutive
// pwdkwabp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> map_;
      // left and right are viewed as indeies
      int left = 0;
      int right = 0;
      int maxlen = 0;
      
      for(int i = 0; i < s.size(); i++){
	auto it = map_.find(s.at(i));
	// which we don't find the value the map_,
	right = i;
	if(it == map_.end()){
	  map_.insert(std::pair<char, int>(s.at(i),1));
	  maxlen = (right - left + 1) > maxlen ? right - left + 1: maxlen;
	}else{
	// which we find the value the map_,
	  while(left <= right && map_.find(s.at(left)) != it){
	    map_.erase(s.at(left++));
	  }
	  map_.erase(s.at(left++));
	  map_.insert(std::pair<char, int>(s.at(right),1));
	  maxlen = (right - left + 1) > maxlen ? right - left + 1: maxlen;
	}
      }
        
      return maxlen;
    }
};
#endif
ostream&
operator << (ostream &os, const vector<int>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}

int main(){
  Solution solve;
  string s1("abcabcbb");
  string s2("bbbbbb");
  string s3("pwwkew");
  string s4("pwdkwabp");
  string s5("aab");
// pwdkwabp
  cout << "LongestSubstring of \" " << s1 << " \"  " << solve.lengthOfLongestSubstring(s1) << endl;
  cout << "LongestSubstring of \" " << s2 << " \"  " << solve.lengthOfLongestSubstring(s2) << endl;
  cout << "LongestSubstring of \" " << s3 << " \"  " << solve.lengthOfLongestSubstring(s3) << endl;
  cout << "LongestSubstring of \" " << s4 << " \"  " << solve.lengthOfLongestSubstring(s4) << endl;
  cout << "LongestSubstring of \" " << s5 << " \"  " << solve.lengthOfLongestSubstring(s5) << endl;
  return 0;
}
