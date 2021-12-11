/*
Course Schedule II: Implemented using DFS (Leetode) -> A question on whether a cycle exists in a directed graph or not.
Logic: Check whether there exists a cycle in this directed graph. If it exists, then it forms a state of deadlock i.e solution doesn't exist. Simply return an empty vector.
The question that arises now is that how do you detect a cycle in directed graph?
In order to find the cycle, you simply have to find whether any of the child node of a currently being processed node is also being processed at the same time.
We make use of the visited array to check whether a node is being processed or not.

If a cycle doesnt exist, there always exists a solution. Start a DFS from any node,
and mark it as visited i.e 1. Perform the DFS on children nodes if they aren't visited.
If they are visited, and if the child is also being processed, then return true i.e cycle exists.
After you are done performing dfs on all the children node, mark the parent node as processed i.e visited[parent] = 2 and push it into the answer.
*/

//Code:

class Solution {
public:
    bool dfs(int u, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans){
        bool cycle = false; 
        //0 -> unvisited, 1 -> being processed, 2 -> finished processing
        visited[u] = 1;
        for(auto v : adj[u]){
            if(visited[v]){
                if(visited[v]==1){
                    cycle = true; break;
                }
            }
            else{
                cycle |= dfs(v, adj, visited, ans);
                if(cycle) break;
            }
        }
        visited[u] = 2;
        ans.push_back(u);
        return cycle;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> visited(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto edge : prerequisites){
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
        }
        int e = prerequisites.size();
        bool cycle = false;
        for(int i=0; i<numCourses; i++){
            if(visited[i]) continue;
            cycle |= dfs(i,adj,visited,ans);
            if(cycle) break;
        }
        if(cycle){
            ans.clear();
            return ans;
        }
        //return the order in which you need to finish the courses
        return ans;
    }
};
