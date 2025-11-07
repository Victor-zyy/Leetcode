#include <vector>
using namespace std;

#define METHOD1 0
#define METHOD2 1

#if METHOD1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
         *  
         * Binary Search by row and then by column
         * 
         */    
        int r_up = 0;
        int r_down = matrix.size() - 1;
        int mid = 0;
        int index = 0;
        while (r_up <= r_down)
        {
            mid = r_up + ((r_down - r_up) >> 2);
            if( target < matrix[mid][0] ){
                r_down = mid - 1; 
            }else{
                index = mid;
                r_up = mid + 1;
            }
        }
        int left = 0; 
        int right = matrix[index].size() - 1;
        while (left <= right)
        {
            mid = left + ((right - left) >> 2);
            if(target < matrix[index][mid]){
                right = mid - 1;
            }else if( target > matrix[index][mid] ){
                left = mid + 1;
            }else{
                return true;
            }
        }
        return false; 
    }
};
#elif METHOD2

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n  - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 2);
            int val = matrix[mid / n][mid % n]; // mid / n and mid % n
            if( target < val ){
                high = mid - 1; 
            }else if( target > val ){
                low = mid + 1;
            }else
            {
                return true;
            }
            
        }
        
        return false; 
    }
};
#endif


int main(){
    Solution mysolve;
    vector<vector<int>> vv = {
        {1, 3, 5, 6},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    vector<vector<int>> vv2 = {{1}};
    mysolve.searchMatrix(vv2, 0);
}