#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        // sort the vector by the rightmost border
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {return u[1] < v[1];});
        int ans = 1;;
        int pos = points[0][1];
        for (const auto point : points)
        {
            if (point[0] > pos){
                pos = point[1]; //  greedy the right-most position border
                ++ans;
            }
        }
        return ans;
    }
};


int main()
{
    Solution mysolve;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    mysolve.findMinArrowShots(points);
    
}