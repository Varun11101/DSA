//TO FIND THE CONNECTED COMPONENTS IN A GIVEN UNDIRECTED GRAPH
const ll N = 1e5+5;
vector<ll> components, visited(N);
vector<vll> adj_list(N);
vector<vll> final_cc;
void dfs(ll cur_node){
  //After entering the parent vertex
  visited[cur_node] = 1;
  components.pb(cur_node);
  for(auto &connected_node : adj_list[cur_node]){
    if(visited[connected_node]) continue;
    dfs(connected_node);
  }
}
void Rasengan(){
 //full chakra | Chunking, DP
  ll n, e; cin >> n >> e;
  //Step 1: Take the input of edges i.e build the graph
  FOR(i,0,e){
    ll v1, v2; cin >> v1 >> v2;
    adj_list[v1].pb(v2);
    adj_list[v2].pb(v1);
  }
  //Step 2: Find the connected components
  for(int i=1; i<=n; i++){
    if(visited[i]) continue;
    components.clear();
    dfs(i);
    final_cc.pb(components);
  }
  //Print the number of connected components and the connected components:
  cout << "Number of connected components: " << final_cc.size() << nline;
  for(auto &c : final_cc){
    for(auto &vertex : c){
      cout << vertex << " ";
    }
    cout << nline;
  }
}//no chakra
