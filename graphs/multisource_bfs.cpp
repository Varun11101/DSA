//Mutlisource BFS on a grid
const ll N = 505;
ll n, m;
vector<vll> grid(N, vll(N)), visited(N, vll(N));
vector<vll> dist(N, vll(N,INF));

vector<pair<ll,ll>> movements = {
  {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}
};

void reset(){
  FOR(i,0,N){
    FOR(j,0,N){
      dist[i][j] = INF;
      visited[i][j] = 0;
      grid[i][j] = 0;
    }
  }
}

bool isValid(ll v_x, ll v_y){
  if(v_x<0 || v_x>=n || v_y<0 || v_y>=m) return false;
  return true;
}

ll bfs(){
  queue<pair<ll,ll>> q; //pair instead of int 
  //cuz you'll be storing the x and y coords (grid)
  ll mx = 0;
  FOR(i,0,N){
    FOR(j,0,N){
      mx = max(mx, grid[i][j]);
    }
  }
  FOR(i,0,N){
    FOR(j,0,N){
      if(grid[i][j]==mx){
        q.push({i,j});
        visited[i][j] = 1;
        dist[i][j] = 0;
      }
    }
  }
  ll ans = 0;
  while(!q.empty()){
    pair<ll,ll> cur_node = q.front();
    q.pop();
    for(auto movement : movements){
      ll v_x = cur_node.ff + movement.ff;
      ll v_y = cur_node.ss + movement.ss;
      if(!isValid(v_x,v_y)) continue;
      if(visited[v_x][v_y]) continue;
      q.push({v_x, v_y});
      dist[v_x][v_y] = dist[cur_node.ff][cur_node.ss] + 1;
      visited[v_x][v_y] = 1;
      ans = max(ans, dist[v_x][v_y]);
    }
  }
  return ans;
}

void Rasengan(){
 //full chakra | Chunking, DP
  //https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
  //Task: Is to find the total days needed to 
  //complete the transition
  //Concepts to be learned from this problem:
  // - Multisource BFS
  // - BFS on grid
  ll t; cin >> t;
  while(t--){
    cin >> n >> m;
    FOR(i,0,n){
      FOR(j,0,m){
        cin >> grid[i][j];
      }
    }
    cout << bfs() << nline;
    reset();
  }
}//no chakra
