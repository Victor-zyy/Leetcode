#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define METHOD1 0
#define METHOD2 0
#define METHOD3 1

#if METHOD1
/**
 * METHOD1: DFS method
 */
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nc = grid.size();
        int vc = grid[0].size();
        grid[r][c] = 0;
        if( r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if( r + 1 < nc && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if( c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if( c + 1 < vc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nc = grid.size();
        if( !nc )
            return 0;    
        int vc = grid[0].size();
        int num_islands = 0;
        for( int r = 0; r < nc; r++ ){
            for(int c = 0; c < vc; c++ ){
                if(grid[r][c] == '1'){
                    num_islands ++;
                    dfs(grid, r, c ); 
                }
            }
        }
        return num_islands;
    }
};
#elif METHOD2

/**
 * METHOD2: BFS -- Breadth First Search -- queue
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nv = grid.size();
        if(!nv) return 0;
        int vc = grid[0].size();
        int num_islands = 0;
        for(int r = 0; r < nv; r++){
            for(int c = 0; c < vc; c++){
                if(grid[r][c] == '1'){
                    num_islands ++;
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = '0';
                    while(!q.empty()){
                        auto [ row, col ] = q.front();q.pop(); //unpack pair
                        if( row - 1 >= 0 && grid[row-1][col] == '1' ){
                            grid[row-1][col] = '0';
                            q.push({row-1, col});
                        }
                        if( row + 1 < nv && grid[row+1][col] == '1' ){
                            grid[row+1][col] = '0';
                            q.push({row+1, col});
                        }

                        if( col - 1 >= 0 && grid[row][col-1] == '1' ){
                            grid[row][col-1] = '0';
                            q.push({row, col-1});
                        }

                        if( col + 1 < vc && grid[row][col+1] == '1' ){
                            grid[row][col+1] = '0';
                            q.push({row, col+1});
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};
#elif METHOD3 
/**
 * METHOD3: Disjoint-Set data Structure
 * 
 */
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) { // root parent two different sets
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx; // root parent
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1; // if rank equals then add one
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};

#endif

int main()
{
    vector<vector<char>> vc;
    vector<char> ts1;
    vector<char> ts2;
    vector<char> ts3;
    vector<char> ts4;
    ts1.push_back('1');
    ts1.push_back('1');
    ts1.push_back('1');
    ts1.push_back('1');
    ts1.push_back('0');
    vc.push_back(ts1);

    ts2.push_back('1');
    ts2.push_back('1');
    ts2.push_back('0');
    ts2.push_back('1');
    ts2.push_back('0');

    vc.push_back(ts2);

    ts3.push_back('1');
    ts3.push_back('1');
    ts3.push_back('0');
    ts3.push_back('0');
    ts3.push_back('0');

    vc.push_back(ts3);

    ts4.push_back('0');
    ts4.push_back('0');
    ts4.push_back('0');
    ts4.push_back('0');
    ts4.push_back('0');

    vc.push_back(ts4);

    for( auto it : vc ){
        for( auto i : it ){
            cout << i << " " ;
        }
        cout << endl;
    }
    Solution mysolve;
    cout << mysolve.numIslands(vc) << endl;

}