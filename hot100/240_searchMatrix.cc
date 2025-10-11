#include <vector>
#include <iostream>
using namespace std;
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.
*/

ostream& operator << (ostream &os, const vector<int>& v);
// method 1 iterate for the whole array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  if(matrix[i][j] == target)
	    return true;
	}
      }
      return false;
    }
};

// binary-search
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      for(auto &row : matrix){
	// to find the first element that is greater the target
	// it means that we have to check again of the value
	auto it = lower_bound(row.begin(), row.end(), target);
	if(it != row.end() && *it == target)
	  return true;
      }
      return false;
    }
};


class Solution3 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      int x = 0; int y = n - 1;
      while(x < m && y >= 0) {
	if(matrix[x][y] == target)
	  return true;
	if(matrix[x][y] > target)
	  y--;
	else
	  x++;
      }
      return false;
    }
};
ostream&
operator << (ostream &os, const vector<int>& v)
{
  os << "{ ";
  for(auto it : v)
    os << it << ' ';
  return os << "} ";
}

ostream&
operator<<( ostream& os, const vector<vector<int>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  os << "{" << endl;
  for( int i = 0; i < m ; i++) {
    os << "[ ";
    for( int j = 0; j < n ; j++) {
      os << matrix[i][j] << " ";
    }
    os << "]" << endl;
  }
  os << "}" << endl;
  return os;
}

class Solution3 {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      for(int i = 0; i < n/2; i++) {
	for(int j = 0; j < n; j++) {
	  swap(matrix[i][j], matrix[n - i - 1][j]);
	}
      }

      for(int i = 0; i < n; i++) {
	for(int j = 0; j < i; j++) {
	  swap(matrix[i][j], matrix[j][i]);
	}
      }
    }
};

int main(){
  Solution2 solve;
  vector<vector<int>> matrix {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  for(int i = 0; i < (4 + 1) / 2; i++)
    cout << i << endl;
  return 0;
}
