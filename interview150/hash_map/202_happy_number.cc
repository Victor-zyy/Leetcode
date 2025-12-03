#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define METHOD1 0
#define METHOD2 1

#if METHOD1
/**
 * METHOD1: HashMap
 */
class Solution {
public:
    bool isHappy(int n) {
       int sum = 0;
       unordered_set<int> _set;
       _set.insert(n);
       while ( n != 1 )
       {
            int t = n % 10; 
            sum += t * t;
            n = n / 10;
            if ( n < 10 ){
                n = n * n + sum;
                if ( _set.count(n) ){
                    return false;
                }
                _set.insert(n);
                sum = 0;
            }
       }
       return true;
    }
};


#elif METHOD2
/**
 * METHOD2: fast-slow pointer
 */

class Solution {
private:
    int getnext( int n ){
        int total_num = 0;
        while ( n > 0 )
        {
            int temp = n % 10;
            total_num += temp * temp;
            n = n / 10;
        }
        return total_num;
    }
public:
    bool isHappy(int n) {
       int slowRunner = n;
       int fastRunner = getnext(n);
       while ( fastRunner != 1 && fastRunner != slowRunner )
       {
            fastRunner = getnext(getnext(fastRunner));
            slowRunner = getnext(slowRunner);
       }
       return fastRunner == 1;
    }
};

#endif



int main()
{
    Solution mysolve;
    mysolve.isHappy(19);
}