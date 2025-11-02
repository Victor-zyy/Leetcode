#include <vector>
#include <queue>
using namespace std;


#define METHOD1 0
#define METHOD2 1
/**
 * Topological Sorting leetcode 210
 */

#if METHOD1
 /**
  * METHOD1: DFS--Depth First Search Using Stack Data Structure
  * Stack to store the sorting order result
  */

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u){
        visited[u] = 1;

        /**
         * visited[x] = 0
         * visited[x] = 1
         * visited[x] = 2
         */

        for(int v : edges[u]){
            if( visited[v] == 0 ){
                dfs(v);
                if(!valid)
                    return;
            }else if( visited[v] == 1 ){
                valid = false;
                return;
            }
        }

        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /**
         * edges and visited
         */
        edges.resize( numCourses );
        visited.resize( numCourses );

        for( const auto & info : prerequisites ){
            edges[info[1]].push_back(info[0]); // [1, 0] ---> 0->1   [2, 3] --> 3->2
        }  
        for (int i = 0; i < numCourses && valid; i++)
        {
            if(!visited[i]){
                dfs(i);
            }
        }
        return valid; 
    }
};
#elif METHOD2

/**
 * METHOD2:  BFS -- Breadth First Search Using Queue Data Structure
 * In-Degree Status
 */

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indgee;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize( numCourses );
        indgee.resize( numCourses );
        for( const auto &info : prerequisites ){
            edges[info[1]].push_back(info[0]);
            indgee[info[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++ ){
            if(indgee[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty())
        {
            ++visited;
            int u = q.front();
            q.pop();
            for(int v : edges[u] ){
                --indgee[v];
                if(indgee[v] == 0 ){
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
        
    }
};

#endif