#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int maxprofit = 0;
        int minprice = inf;
        for( const int & price : prices ){
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }    
        return maxprofit;
    }
};