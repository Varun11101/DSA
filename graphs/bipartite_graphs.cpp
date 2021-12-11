/*
Bipartite graphs are those where you can split the nodes into two groups such that each node in a group isn't connected to any other node in the same group.
We use bipartite graph coloring to find out whether there exists a cycle having odd number of nodes or not.
Good problem to practice: CSES Problemset - Building teams
*/
const int N = 1e5+1;
vector<vector<ll>> adj(N);
vector<ll> vis(N), col(N,-1);
int n, e; 
bool dfs(int u, int c){
  bool ok = true;
  vis[u] = 1;
  col[u] = c;
  for(auto v : adj[u]){
    if(vis[v]){
      if(col[v]==col[u]){
        ok = false; break;
      }
    }
    else{
      ok &= dfs(v, c^1);
      if(!ok) break;
    }
  }
  return ok;
}
