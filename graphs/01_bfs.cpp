//REVERSE - Graph in Codechef - Uses 0-1 BFS
const ll N = 1e5+1;
vector<vector<pair<ll,ll>>> adj(N);
vector<ll> dist(N,INF);

void bfs(){
  deque<ll> q;
  ll start = 1;
  q.pb(start);
  dist[start] = 0;
  while(!q.empty()){
    ll cur_node = q.front();
    q.pop_front();
    for(auto child : adj[cur_node]){
      ll child_node = child.ff;
      ll wt = child.ss;
      if(dist[cur_node]+wt < dist[child_node]){
        //then push it into the queue
        if(wt==0){
          q.push_front(child_node);
        }
        else{
          q.push_back(child_node);
        }
        dist[child_node] = dist[cur_node] + wt;
      }
    }
  }
}
void Rasengan(){
 //full chakra | Chunking, DP
  //SSSP - Using 0-1 BFS
  ll n, e; cin >> n >> e;
  FOR(i,0,e){
    ll a, b; cin >> a >> b;
    if(a==b) continue; //Self Loops
    adj[a].pb({b,0LL});
    adj[b].pb({a,1LL});
  }
  bfs();
  cout << (dist[n]==INF? -1 : dist[n]) << nline;
}//no chakra
