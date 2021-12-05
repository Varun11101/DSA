//To find whether cycle exists in an undirected graph or not
const ll N = 1e5+5;
vector<vector<ll>> adj_list(N);
vector<ll> visited(N);
bool dfs(ll cur_node, ll parent){
  bool cycleExists = false;
  visited[cur_node] = 1;
  for(auto &connected_node : adj_list[cur_node]){
    if(visited[connected_node] && connected_node != parent){
      cycleExists = true;
    }
    if(visited[connected_node]) continue;
    cycleExists |= dfs(connected_node, cur_node);
  }
  return cycleExists;
}
void Rasengan(){
 //full chakra | Chunking, DP
  //Detect a cycle in an undirected graph
  ll n, e; cin >> n >> e;
  //Building the graph
  FOR(i,0,e){
    ll v1, v2; cin >> v1 >> v2;
    adj_list[v1].pb(v2);
    adj_list[v2].pb(v1);
  }
  //How do we find a cycle?
  /*
    - If the child node of a parent node has already
    been visited, and if that visited child node isn't
    the parent node's parent, then a cycle exists.

    - So, in order to find whether there exists a cycle,
    we must keep a track of the parent node.
  */
  bool cycleExists = false;
  for(int i=1; i<=n; i++){
    if(visited[i]) continue;
    cycleExists |= dfs(i,0LL);
    if(cycleExists) break;
  }
  cout << (cycleExists? "YES" : "NO") << nline;
}//no chakra
