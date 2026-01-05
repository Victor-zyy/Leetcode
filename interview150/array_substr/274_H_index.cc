#include <vector>
#include <algorithm>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1
/**
 *  This question is mainly about sort algorithem
 */
#if METHOD1
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());            
        int h_index = 0;
        int n = citations.size();
        int i = n - 1;
        while (i >= 0 && citations[i] > h_index)
        {
            h_index++;
            i--;
        }
        return h_index;
    }
};
#elif METHOD2

/**
 * METHOD2: calculation sort algorithem
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h_index = 0;
        int n = citations.size();
        vector<int> sortv(n + 1);
        for (int i = 0; i < n; i++)
        {
            if (citations[i] > n)
                sortv[n]++;
            else 
                sortv[citations[i]]++;
        }
        
        for (int i = n; i >= 0; i--)
        {
            h_index += sortv[i];
            if (h_index >= i)
                return i;
        }
        
        return 0;
    }
};
#elif METHOD3

/**
 * METHOD3: binary search -- 0-n dandiao de
 * 根据题目意思，H越大，那么发表的文章大于H被引用的数值越大，反之亦然，这样就具有单调性了，可以二分答案了。大于H的数值越多，那么H还能被提高，缩小左边界，否则右边界。
 */

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int left = 0, right = citations.size();
		while (left <= right) {
			int mid = left + ((right - left) >> 1);
			int cnt = 0;
			for (auto&& x : citations) {
				if (x >= mid) ++cnt;
			}
			if (cnt < mid) {
				right = mid - 1;
			}
			else left = mid + 1;
		}
		return right;
	}
};

#endif

int main()
{
    vector<int> nums = {3,0,6,1,5};
    Solution mysolve;
    mysolve.hIndex(nums);
}
