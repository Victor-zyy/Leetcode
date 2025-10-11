#include <vector>
#include <iostream>
using namespace std;
/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/


ostream& operator << (ostream &os, const vector<int>& v);


// method1  use visited matrix to documents each position that must be set zero
// but it occupies (m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      //vector<vector<int>> visited(m, vector<int>(n)); // how to initialize an matrix
      vector<int> rows(m);
      vector<int> cols(n);
      for(int i = 0 ; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  if(matrix[i][j] == 0){
	    rows[i] = cols[j] = 1;
	  }
	}
      }

      for(int i = 0 ; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  if(rows[i] || cols[j]){
	    matrix[i][j] = 0;
	  }
	}
      }
    }
};

class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      if(matrix.size() == 0)
	return;
      int m = matrix.size();
      int n = matrix[0].size();
      int flag_row0 = 0;
      int flag_col0 = 0;
      // check row0
      // check col0
      for(int i = 0; i < m ; i++) {
	if(matrix[i][0] == 0)
	  flag_row0 = 1;
      }

      for(int i = 0; i < n ; i++) {
	if(matrix[0][i] == 0)
	  flag_col0 = 1;
      }

      for(int i = 1; i < m; i++) {
	for(int j = 1; j < n; j++) {
	  if(matrix[i][j] == 0) {
	    matrix[0][j] = matrix[i][0] = 0;
	  }
	}
      }

      for(int i = 1; i < m; i++) {
	for(int j = 1; j < n; j++) {
	  if(matrix[0][j] == 0 || matrix[i][0] == 0){
	    matrix[i][j] = 0;
	  }
	}
      }

      for(int i = 0; i < m; i++){
	if(flag_row0)
	  matrix[i][0] = 0;
      }

      for(int i = 0; i < n; i++){
	if(flag_col0)
	  matrix[0][i] = 0;
      }
    }
};

class Solution3 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int flag_col0 = 0;
      if(matrix.size() == 0)
	return;
      int m = matrix.size();
      int n = matrix[0].size();

      for(int i = 0; i < m; i++){
	if(matrix[i][0] == 0)
	  flag_col0 = 1;
	for(int j = 1; j < n ; j++) {
	  if(matrix[i][j] == 0)
	    matrix[i][0] = matrix[0][j] = 0;
	}
      }
      // [[0,1,2,0]
      // ,[3,4,5,2]
      // ,[1,3,1,5]]
      for(int i = m - 1; i >= 0; i--) {
	for(int j = 1; j < n; j++){
	  if(matrix[i][0] == 0 || matrix[0][j] == 0)
	    matrix[i][j] = 0;
	}
	if(flag_col0){
	  matrix[i][0] = 0;
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

int main(){
  Solution3 solve;
  vector<vector<int>> matrix{
    { 0 , 1 , 2 , 0 },
    { 3 , 4 , 5 , 2 },
    { 1 , 3 , 1 , 5 },
  };
  cout << matrix;
  solve.setZeroes(matrix);
  cout << matrix;
  return 0;
}
