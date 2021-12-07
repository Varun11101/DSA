const ll N = 1e5+1;
vector<ll> visited(N);
queue<ll> q;
vector<vector<ll>> adj_list(N);
vector<ll> dist(N, INF);

void bfs(ll source){
  visited[source] = 1;
  dist[source] = 0;
  q.push(source);
  while(!q.empty()){
    ll cur_node = q.front();
    cout << cur_node << " ";
    q.pop();
    for(auto child : adj_list[cur_node]){
      if(visited[child]) continue;
      //Three steps!
      //1) Push the child into the queue
      //2) Update the distance of the child from source
      //3) Mark the child as visited
      q.push(child);
      dist[child] = dist[cur_node] + 1;
      visited[child] = 1;
    }
  }
}

void Rasengan(){
 //full chakra | Chunking, DP
  //BFS traversal
  //Task: 
  //1) To print the BFS traversal of a given graph
  //2) Find the level/distance from the source to
  //   all the othe nodes in the graph i.e shortest path in an undirected graph
 
  //Requirements:
  // 1) adj_list 2) distance/level array 
  // 3) queue 4) visited array (not mandatory, you can just check if dist[i]==INF)

  //Build the graph
  ll nodes, edges; cin >> nodes >> edges;
  FOR(i,0,edges){
    ll node1, node2; cin >> node1 >> node2;
    adj_list[node1].pb(node2);
    adj_list[node2].pb(node1);
  }
  //Nodes are numbered from 1 to nodes
  ll source = 8;
  bfs(source);
  cout << nline << "Distance of every node from the source is: ";
  for(int i=1; i<=nodes; i++){
    cout << i << ": " << dist[i] << nline;
  }

/*
Sample input:
12 12
8 4
8 3
3 10 
9 4
3 7
1 9
7 6
1 11
6 12
12 11
1 2
2 5

Output:
8 4 3 9 10 7 1 6 11 2 12 5 
Distance of every node from the source is: 1: 3
2: 4
3: 1
4: 1
5: 5
6: 3
7: 2
8: 0
9: 2
10: 2
11: 4
12: 4
*/
}//no chakra
