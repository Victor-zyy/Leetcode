#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
/**
 * METHOD1: Double Pointer
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftmax = 0;
        int rightmax = 0;
        int area = 0;
        while (left < right)
        {
            /**
             * First maintain two vars leftmax and rightmax
             */
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            /* */
            if (height[left] < height[right]) {
                area += leftmax - height[left]; 
                left++;
            } else {
                area += rightmax - height[right];
                --right;
            }
        }
        return area;
        
    }
};
#elif METHOD2
/**
 * METHOD2: monotonic stack
 */
#include <stack>
class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        if ( height.size() == 0 ) return area;
        stack<int> stk;
        for (int i = 0; i < height.size(); i++)
        {
            while (!stk.empty() && height[i] > height[stk.top()]) // handle the first element
            {
                int top = stk.top(); 
                stk.pop();
                if (stk.empty()) break;

                int left = stk.top();
                int curWidth = i - left - 1;
                int curHeigh = min(height[left], height[i]) - height[top]; // Three position
                area += curHeigh * curWidth;
            }
            stk.push(i);
        }
        return area;
    }
};

#elif METHOD3

/**
 * METHOD3: Dynamic Programming
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        vector<int> leftmax(height.size());
        vector<int> rightmax(height.size());
        leftmax[0] = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            leftmax[i] = max(leftmax[i-1], height[i]);
        }

        rightmax[height.size() - 1] = height[height.size()-1];
        for (int i = height.size() - 2; i >= 0; i-- ) {
            rightmax[i] = max(rightmax[i+1], height[i]);
        }
        
        for (int i = 0; i < height.size(); i++)
        {
            area += min(rightmax[i] , leftmax[i]) - height[i]; 
        }
        
        return area;
    }
};

#endif


int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution mysolve;
    mysolve.trap(height);
}