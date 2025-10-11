#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
      vector<int> winFreq(128);
      vector<int> tFreq(128);

      int pos = 0;
      int len = s.size();
      
      if(s.size() < t.size())
	return {};
      
      for(int i = 0 ; i < t.size(); i++){
	tFreq[t[i]]++;
      }


      int left  = 0;
      int right = 0;

      int distance = 0;
      bool flag = false;

      while(right < s.size()){
	if(tFreq[s[right]] == 0){
	  right++;
	  continue;
	}

	if(winFreq[s[right]] < tFreq[s[right]])
	  distance++;

	winFreq[s[right]] ++;
	right++;
	// [left, right)
	// [0 1 2 3 4 5]
	while(distance == t.size()){
	  if(right - left <= len){
	    len = right - left;
	    pos = left;
	    flag = true;
	  }

	  if(tFreq[s[left]] == 0){
	    left++;
	    continue;
	  }
	  
	  if(winFreq[s[left]] == tFreq[s[left]]){
	    distance--;
	  }


	  winFreq[s[left]]--;
	  left++;
	}
      }
      cout << "len " << len << " pos " << pos << endl;
      if(len == s.size() && !flag)
	return {};
      return s.substr(pos, len);
    }
};





#if 0
// Given two strings s and t of lengths m and n respectively, return the minimum window
// of s such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".
// The testcases will be generated such that the answer is unique.

// cover not sequential equals -> distance of each FreqArray
// hashtable -> diff to decrease the time overhead
// method  sliding window
// global solution -> partial solution

class Solution {
public:
    string minWindow(string s, string t) {

      if(s.size() < t.size())
	return {};

      //if(s.size() == t.size())
	//return s == t ? s : string(); // FIXME: typename object

      //int diff = 0; // // FIXME: diff 
      int distance = 0; //
      // Sliding Window
      int left = 0;
      int right = 0;
      vector<int> winFreq(128);
      vector<int> tFreq(128);

      int begin = 0; // to doc the substring begin
      int minlen = s.size(); // to doc the substring length
      // statistic the freq of tstring
      bool flag = false;
      for(int i = 0; i < t.size(); i++)
	tFreq[t[i]] ++;

      // [left, right)
      while(right < s.size()){
	if(tFreq[s[right]] == 0) {
	  right ++;
	  continue;
	}

	if(winFreq[s[right]] < tFreq[s[right]])
	  distance++;

	winFreq[s[right]] ++;
	right++;

	while(distance == t.size()){
	  // the index has coverd up the tstring
	  if(right - left <= minlen){
	    flag = true;
	    begin = left;
	    minlen = right - left;
	  }

	  if(tFreq[s[left]] == 0){
	    left++;
	    continue;
	  }
	  
	  if(winFreq[s[left]] == tFreq[s[left]])
	    distance--;

	  winFreq[s[left]] --;
	  left++;
	}
      }
      if(minlen == s.size() && !flag)
	return "";
      return s.substr(begin, minlen);
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
  string s1 = "ADOBECODEBANC";
  string p1 = "ABC";

  string s2 = "a";
  string p2 = "a";
  cout << "s1 : " << s1 << " p : " << p1 << " minSubstring " << solve.minWindow(s1, p1) << endl;
  cout << "s2 : " << s2 << " p : " << p2 << " minSubstring " << solve.minWindow(s2, p2) << endl;
  cout << p1.substr(0, p1.size()) << endl;
  return 0;
}
