#include <vector>
using namespace std;

/**
 *  The speciality of stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice  = min(minprice, prices[i]);
        }
        return maxprofit;    
    }
};