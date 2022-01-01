/*
Course Schedule:

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

-> For example,
the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
1) 1 <= numCourses <= 105
2) 0 <= prerequisites.length <= 5000
3) prerequisites[i].length == 2
4) 0 <= ai, bi < numCourses
5) All the pairs prerequisites[i] are unique.

*/
class Solution {
public:
    bool checkCycle(int node,int numCourses, vector<vector<int>>& prerequisites,vector<int> &visited,vector<int>  &dfsvisited){
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto x:prerequisites[node]){
            if(!visited[x]){
                if(checkCycle(x,numCourses,prerequisites,visited,dfsvisited)) return true;
            }
            else if(dfsvisited[x]) return true;
            
        }
        dfsvisited[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses,0);
        vector<int> dfsvisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(checkCycle(i,numCourses,adj,visited,dfsvisited)) return false;
            }
        }
        return true;
    }
};
