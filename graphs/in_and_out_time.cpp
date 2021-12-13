//in and out time of nodes: helps in solving query based questions where you will be asked questions such as "find whether a node exists in the subtree of another node".
const ll N = 101;
vll in_time(N), out_time(N);
vll visited(N);
vvll adj(N);
ll timer = 1;
void dfs(ll u){
  //you enter the parent vertex
  in_time[u] = timer++;
  visited[u] = 1;
  for(auto v : adj[u]){
    //before taking action on the child node
    if(visited[v]) continue;
    dfs(v);
  }
  //before leaving the parent vertex
  out_time[u] = timer++;
}
void Rasengan(){
 //full chakra | Chunking, DP
  ll n, e; cin >> n >> e;
  FOR(i,0,e){
    ll a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  //We find the in and out time of the nodes using DFS
  //Start a dfs from the root of the tree always.
  dfs(1);
  ll q; cin >> q;
  while(q--){
    ll child, parent; cin >> child >> parent;
    //Condition: 
    if(in_time[parent] < in_time[child] && out_time[parent] > out_time[child]){
      cout << "YES" << nline;
    }
    else{
      cout << "NO" << nline;
    }
  }
}//no chakra
