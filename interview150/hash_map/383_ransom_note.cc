#include <string>
#include <unordered_map>

using namespace std;


 /**
  * count returns the number of elements matching specific key 
  */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> _map;
        bool ans = true;
        for (const auto & ch : magazine ){
            _map[ch] += 1;
        }
        for (const auto &ch : ransomNote ){
            if (_map.count(ch) && _map[ch] > 0){
                _map[ch] -= 1;
            }else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};


int main()
{
    Solution mysolve;
    auto ans = mysolve.canConstruct("aa", "ab");
}