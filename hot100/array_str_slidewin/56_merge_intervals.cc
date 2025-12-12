#include <vector>
#include <algorithm>

using namespace std;

#define METHOD1 0
#define METHOD2 1
#define METHOD3 0

#if METHOD1
/**
 * METHOD1: Using Iteration and Sort
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first sort the intervals using the first element is that ok?
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i = 0; int j = 0;
        while ( i < intervals.size() )
        {
            j = i + 1;
            int lmin = intervals[i].front();
            int rmax = intervals[i].back();
            while (j < intervals.size())
            {
                if (intervals[j].front() >= lmin && 
                    intervals[j].front() <= rmax ) 
                {
                    lmin = min(lmin, intervals[j].front());
                    rmax = max(rmax, intervals[j].back());
                    j++;
                    continue;
                }
                break;
            }
            i = j;
            ans.push_back({lmin, rmax});
        }
        return ans; 
    }
};
#elif METHOD2

/**
 * METHOD2: divide and conquer --- Take a superfluous action
 */

class Solution {
public:
    vector<vector<int>> mergetwo(vector<vector<int>>& left, vector<vector<int>>& right)
    {
        vector<vector<int>> result;
        // 将两个列表合并
        vector<vector<int>> merged = left;
        merged.insert(merged.end(), right.begin(), right.end());

        // 对合并后的列表进行区间合并 -- 
        for (auto& interval : merged) {
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
    }

    vector<vector<int>> divconquer(vector<vector<int>>& intervals, int l, int r)
    {
        if ( l == r ){
            return {intervals[l]};
        }
        int m = ( l + r ) >> 1;
        vector<vector<int>> left = divconquer(intervals, l, m);
        vector<vector<int>> right = divconquer(intervals, m + 1, r);
        return mergetwo(left, right);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first sort the intervals using the first element is that ok?
        sort(intervals.begin(), intervals.end());
        return divconquer(intervals, 0, intervals.size() - 1); 
    }
};
#elif METHOD3


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first sort the intervals using the first element is that ok?
        if (intervals.size() == 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++)
        {
            int L = intervals[i][0]; int R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

#endif


int main()
{
    vector<vector<int>> intervals = {{2,6},{1,3},{8,10},{15,18}};
    Solution mysolve;
    mysolve.merge(intervals);
}