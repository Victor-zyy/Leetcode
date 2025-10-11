#include <vector>
#include <iostream>
using namespace std;
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

ostream& operator << (ostream &os, const vector<int>& v);

// method 1 using auxiliary array
// formula is 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      auto auxiliary = matrix;
      for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  matrix[i][j] = auxiliary[n - 1 - j][i];
	}
      }
    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      // n = 4 ; n = 5;
      for(int i = 0; i < n / 2; i++) {
	for(int j = 0; j < (n + 1) / 2; j++) {
	  int temp = matrix[i][j];
	  matrix[i][j] = matrix[n - 1 - j][i];
	  matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
	  matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
	  matrix[j][n - 1 - i] = temp; //// FIXME: matrix[i][j];
	}
      }
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
