const ll N = 101;
vll nodes(N), visited(N);
vvll adj(N);
ll dfs(ll u){
  visited[u] = 1;
  ll nn = 1;
  for(auto v : adj[u]){
    if(visited[v]) continue;
    nn += dfs(v);
  }
  nodes[u] = nn;
  return nn;
}
void Rasengan(){
 //full chakra | Chunking, DP
  //To calculate the number of nodes in a subtree/ every subtree
  //Perform a DFS from the root
  //Basic Logic: Number of nodes in a subtree = 
  //1 + Number of nodes present in subtrees rooted at it's child nodes
  ll n; cin >> n;
  FOR(i,0,n-1){
    ll a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  ll x = dfs(1);
  cout << "Number of nodes present in subtree rooted at: " << nline;
  FOR(i,1,n+1){
    cout << i << ": " << nodes[i] << " " << "nodes" << nline;
  }
}//no chakra
