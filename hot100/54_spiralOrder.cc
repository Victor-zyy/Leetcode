#include <vector>
#include <iostream>
using namespace std;
/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

ostream& operator << (ostream &os, const vector<int>& v);
// use a visited matrix method to avoid duplicate access
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<vector<int>> direction { { 0 , 1 }, { 1 , 0 }, { 0 , -1 }, { -1 , 0 } };
      if(matrix.size() == 0)
	return {};
      int m = matrix.size();
      int n = matrix[0].size();
      int row = 0;
      int col = 0;
      int pos = 0;
      vector<int> order;
      vector<vector<int>> visited(m, vector<int>(n));
      for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  order.push_back(matrix[row][col]);
	  visited[row][col] = 1;
	  int temp_r = row + direction[pos][0];
	  int temp_c = col + direction[pos][1];
	  if(temp_r >= m || temp_c >= n || temp_r < 0 || temp_c < 0 || visited[temp_r][temp_c]) {
	    pos = ( pos + 1 ) % 4;
	  }
	  row += direction[pos][0];
	  col += direction[pos][1];
	}
      }
      return order;
    }
};


class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      if(matrix.size() == 0 || matrix[0].size() == 0)
	return {};
      int m = matrix.size();
      int n = matrix[0].size();
      int left = 0;
      int right = n - 1;
      int top = 0;
      int bottom = m - 1;
      vector<int> order;
      while(left <= right && top <= bottom) {
	// (top,left)-----------------> (top,right)
	for(int i = left ; i <= right; i++) {
	  order.push_back(matrix[top][i]);
	}
	// (top,right)-----------------> (bottom,right)
	for(int i = top + 1; i <= bottom; i++) {
	  order.push_back(matrix[i][right]);
	}
	// condition
	// 
	// { [3]
	//   [3] }
	if (left < right && top < bottom) {
	  // (bottom,right)-----------------> (bottom,left)
	  for(int i = right - 1; i > left; i--) {
	    order.push_back(matrix[bottom][i]);
	  }
	  // (bottom,left)-----------------> (top,left)
	  for(int i = bottom; i > top; i--) {
	    order.push_back(matrix[i][left]);
	  }
	}

	left++;
	right--;
	top++;
	bottom--;
      }
      return order;
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

int main(){
  Solution2 solve;
  vector<vector<int>> matrix {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  cout << matrix;
  auto vec = solve.spiralOrder(matrix);
  cout << vec;
  return 0;
}
