//To find the height and depth of a tree
const int N = 101;
vector<vector<int>> adj(N);
vector<int> height(N), depth(N);
//Remember the 4 main parts of any dfs code
void dfs(int u, int parent){
  //after entering the parent vertex i.e u
  for(auto v : adj[u]){
    if(v == parent) continue;
    //before entering the child vertex i.e v
    depth[v] = depth[u] + 1;
    dfs(v, u);
    //after leaving the child vertex i.e v
    height[u] = max(height[u], height[v]+1);
  }
  //before leaving the parent vertex
}
void Rasengan(){
 //full chakra | Chunking, DP
  int n; cin >> n;
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  //Task: To find the depth and height of the nodes in the tree
  //Height of a node:
  //It is the the number of edges between the node and the farthest leaf node
  //h(u) = 1 + max(h(v1), h(v2)...h(vk))
  //Depth of a node:
  //It is the number of edges between the node and the root node
  dfs(1,0); //pass in the root node -> 1 is the root in this case
  for(int i=1; i<=n; i++){
    cout << depth[i] << " " << height[i] << nline;
  }
}//no chakra
