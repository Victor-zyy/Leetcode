#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

/**
 * METHOD1:  BFS--Breadth First Search
 * 上下左右相邻的新鲜橘子就是该腐烂橘子尝试访问的同一层的节点，路径长度就是新鲜橘子被腐烂的时间
 * Breadth meaning not row for grap
 * 我们令其为超级源点
 */

class Solution {
private:
    int cnt;
    int dis[10][10];
    int dir_x[4] = { 0, 1, 0, -1};
    int dir_y[4] = { 1, 0, -1, 0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        memset(dis, -1, sizeof(dis));
        int ans = 0;
        int n = grid.size(); int m = grid[0].size();
        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < m; j++ ){
                if(grid[i][j] == 2){
                    Q.push({i, j});
                    dis[i][j] = 0;
                }else if(grid[i][j] == 1){
                    cnt+=1;
                }
            }
        }

        while (!Q.empty())
        {
            auto [r, c] = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++ ){
                int d_x = r + dir_x[i];
                int d_y = c + dir_y[i];
                // ~dis[d_x][d_y] means dis[d_x][d_y] == -1
                if( d_x < 0 || d_x >= n || d_y < 0 || d_y >= m || ~dis[d_x][d_y] || !grid[d_x][d_y]){
                    continue;
                }
                dis[d_x][d_y] = dis[r][c] + 1;
                Q.emplace(d_x,d_y);
                if( grid[d_x][d_y] == 1){
                    cnt--;
                    ans = dis[d_x][d_y];
                    if(!cnt)
                        break;
                }
            }
        }
        return cnt ? -1 : ans; 
    }
};


int main(){

    vector<vector<int>> grid;
    vector<int> v1 = { 2, 1, 1};
    vector<int> v2 = { 1, 1, 0};
    vector<int> v3 = { 0, 1, 1};

    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);

    Solution mysolve;
    cout << mysolve.orangesRotting(grid) << endl;
}