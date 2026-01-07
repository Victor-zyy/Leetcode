#include <vector>
using namespace std;

/**
 * METHOD: Greedy
 * 一句话概括：如果x到达不了y+1，那么x-y之间的点也不可能到达y+1，
 * 因为中间任何一点的油都是拥有前面的余量的，所以下次遍历直接从y+1开始
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int n = gas.size();        
        while (i < n)
        {
            int cnt = 0;
            int sumofGas = 0;
            int sumofCost = 0;
            while (cnt < n)
            {
                int j = (i + cnt) % n;
                sumofCost += cost[j];
                sumofGas += gas[j];
                if (sumofCost > sumofGas)
                    break;
                cnt++;
            }
           
            if (cnt >= n) return i;
            else i = i + cnt + 1;
        }
        
    }
};