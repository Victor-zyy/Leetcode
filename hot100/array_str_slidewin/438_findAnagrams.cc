#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
#define FIRST_TIME 0
#define SECOND_TIME 1

#if FIRST_TIME
/*
Given two strings s and p, return an array of all the start indices of p's
in s. You may return the answer in any order.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
// case sensitive only lower letters
class Solution{
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans;
      unordered_map<int, int> p_map(26);
      unordered_map<int, int> s_map(26);
      if(p.size() > s.size())
	return {};
      for(int i = 0; i < 26; i++){
	p_map[i] = 0;
	s_map[i] = 0;
      }
	
      for(auto & s_ : p)
	p_map[s_ - 'a'] ++;

      for(int i = 0; i < p.size(); i++)
	s_map[s[i] - 'a'] ++;

      if(s_map == p_map)
	ans.push_back(0);
      
      int right = p.size();
      int left = 0;
      while(left < s.size() - p.size()){
	++s_map[s[right++] - 'a'];
	--s_map[s[left++] - 'a'];

	if(s_map == p_map)
	  ans.push_back(left);

      }
      
      return ans;
    }
};
#if 0
// find the Anagrams of a string
// p is the substring
// Method hashtable + slide unit
// which is exceed the time limit O(n^2)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      //unordered_map<string, vector<int>> map_;
      vector<int> res{};
      sort(p.begin(), p.end());
      int left = 0;
      int right = p.size() - 1;
      int gap = p.size();
      if( s.size() < p.size())
	return {};
      
      while(right < s.size()){
	string sub(s.substr(left, gap));
	sort(sub.begin(), sub.end());
	if(sub == p)
	  res.push_back(left); 
	left++;
	right++;
	sub.clear();
      }
      return res; 
    }
};

// using the count number to speed up the iterationS

class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
      //unordered_map<string, vector<int>> map_;
      vector<int> res{};

      vector<int> scount(26);
      vector<int> pcount(26);

      int left = 0;
      int gap = p.size();
      if( s.size() < p.size())
	return {};
      
      for(int i = 0; i < p.size(); i++){
	scount[s[i] - 'a']++;
	pcount[p[i] - 'a']++;
      }

      if(scount == pcount){
	res.emplace_back(0);
      }

      // s "abcde" [0 1 2 3 4 ] size 5
      for(left = 0; left < s.size() - gap; left++){
	--scount[s[left] - 'a'];
	++scount[s[left + gap] - 'a'];// FIXME: ++right when equals to s.size will access the \0 value of the sting
	if(scount == pcount){
	  res.emplace_back(left + 1);
	}

      }
      return res; 
    }
};

class Solution3{
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);
        for (int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;
        for (int j = 0; j < 26; ++j) {
            if (count[j] != 0) {
                ++differ;
            }
        }

        if (differ == 0) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            if (count[s[i] - 'a'] == 1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            --count[s[i] - 'a'];

            if (count[s[i + pLen] - 'a'] == -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i + pLen] - 'a'] == 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            ++count[s[i + pLen] - 'a'];
            
            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
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
  string s1("cbaebabacd");
  string p1("abc");
  string s2("abab");
  string p2("ab");
  cout << "s1 : " << " p1 : " << " " << solve.findAnagrams(s1, p1) << endl;
  cout << "s2 : " << " p2 : " << " " << solve.findAnagrams(s2, p2) << endl;
  string s("abcde");
  cout << hex<<static_cast<int>(s[5]) << endl;
  return 0;
}

#elif SECOND_TIME

#include <unordered_set>

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
/**
 * Execeed the time limit
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();         
        sort(p.begin(),p.end());
        vector<int> ans; 
        int w_l = 0;
        int w_r = 0;
        for (int i = 0; i < s.size(); i++)
        {
            string t_s = s.substr(i, n);
            sort(t_s.begin(), t_s.end());
            if (t_s.size() != p.size()) {
                break;
            } else {
                int j;
                for (j = 0; j < p.size(); j++)
                {
                    if (t_s[j] != p[j]) break;
                }
                if (j == p.size()){
                    ans.emplace_back(i);
                }
            }
        }
        return ans;
    }
};
#elif METHOD2

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        
        if (slen < plen ) return {};

        vector<int> sCount(26);
        vector<int> pCount(26);
        vector<int> ans;

        for (int i = 0; i < plen; i++)
        {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }

        if (sCount == pCount)
        {
            ans.emplace_back(0);
        }
        
        for (int i = 0; i < slen - plen; i++)
        {
            --sCount[s[i] - 'a'];
            ++sCount[s[i+plen] - 'a']; // need to be considered a slide window
            if (sCount == pCount){
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};

#elif METHOD3

/**
 * OPTIMIZATION of Slide window space complexity
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        if (slen < plen)
        {
            return {};
        }

        vector<int> count(26);
        vector<int> ans;
        int diff = 0;

        for (int i = 0; i < plen; i++)
        {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0){
                diff++;
            }
        }
        
        if (diff == 0) ans.emplace_back(0);
        
        for (int i = 0; i < slen - plen; i++)
        {
            if (count[s[i] - 'a'] == 1){
                --diff;
            } else if (count[s[i] - 'a'] == 0)
            {
                ++diff;
            }
            --count[s[i] - 'a']; 

            if (count[s[i + plen] -'a' ]  == -1){
                --diff;
            } else if (count[s[i + plen] - 'a' ]  == 0)
            {
                ++diff;
            }
            
            ++count[s[i + plen] - 'a'];

            if (diff == 0) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};
#endif


int main()
{

    Solution mysolve;
    string s = "cbaebabacd";
    string p = "abc";
    mysolve.findAnagrams(s, p);
}

#endif