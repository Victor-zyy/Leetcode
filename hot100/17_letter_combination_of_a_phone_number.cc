#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * 2: abc
 * 3: def
 * 4: ghi
 * 5: jkl
 * 6: mno
 * 7: pqrs
 * 8: tuv
 * 9: wxyz
 * 
 */

 /**
  * METHOD1: backtrace with hash map
  */
class Solution {
private:
    unordered_map<char, string> map = {
        {'2',"sasa"}
    };
public:
    void backtrace(vector<string>& ans, string& digits, int index, string& combinations){
        if( index == digits.size() ){
            ans.emplace_back( combinations );
            return;
        }
        char digit = digits[index];
        string str = map[digit];
        for(int i = 0; i < str.size(); i++ ){
            combinations.push_back(str[i]);
            backtrace(ans, digits, index + 1, combinations);
            combinations.pop_back();
        }
         
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string combinations;
        map['2'] =  "abc" ;
        map['3'] =  "def" ;
        map['4'] =  "ghi" ;
        map['5'] =  "jkl" ;
        map['6'] =  "mno" ;
        map['7'] =  "pqrs" ;
        map['8'] =  "tuv" ;
        map['9'] =  "wxyz" ;
        backtrace(ans, digits, 0, combinations);
        return ans;
    }
};