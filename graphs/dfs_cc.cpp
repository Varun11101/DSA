//To find the number of connected components in an undirected graph
void dfs(ll cur_node, vll &visited, vector<vll> &adj_list){
  visited[cur_node] = 1;
  for(auto &connected_node : adj_list[cur_node]){
    if(visited[connected_node]) continue;
    dfs(connected_node, visited, adj_list);
  }
}
void Rasengan(){
 //full chakra | Chunking, DP
  ll vertices, edges; cin >> vertices >> edges;
  vector<vector<ll>> adj_list(vertices+1); 
  //since the nodes/vertices start from 1 and end at number of vertices
  FOR(i,0,edges){
    ll node1, node2; cin >> node1 >> node2;
    adj_list[node1].pb(node2);
    adj_list[node2].pb(node1);
  }
  //Performing a DFS to find the number of connected components
  ll count = 0;
  vector<ll> visited(vertices+1,0); //Keep a track of visited nodes
  for(int i=1; i<=vertices; i++){
    if(visited[i]) continue;
    dfs(i,visited,adj_list);
    count++;
  }
  cout << count << nline;
}//no chakra
