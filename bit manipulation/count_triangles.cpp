//Given an undirected graph, count the total number of triangles form in it.

void PreCompute(){}
void Rasengan(){
  //Author: Varun11101
 //full chakra
  //Brute force solution:

  // ll n, e; cin >> n >> e;
  // map<pair<ll,ll>,ll> mp;
  // FOR(i,0,e){
  //   ll a, b; cin >> a >> b;
  //   mp[{a,b}] = 1;
  //   mp[{b,a}] = 1;
  // }
  // ll count = 0;
  // for(ll i=0; i<n; i++){
  //   for(ll j=i+1; j<n; j++){
  //     for(ll k=j+1; k<n; k++){
  //       if(mp[{i,j}] && mp[{j,k}] && mp[{i,k}]) count++;
  //     }
  //   }
  // }
  // cout << count << nl;

  //Time complexity: O(V^3)

  //-------------------------------------------
  //Using bitmasks to optimize it: 

  const ll N = 10;
  ll n, e; cin >> n >> e;
  vector<bitset<10>> adj(n);
  //adj[i] -> adjacency list of the node in the form of a bitset
  vector<pair<ll,ll>> edges;
  FOR(i,0,e){
    ll a, b; cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
    edges.pb({a,b});
  }
  ll cnt = 0;
  for(auto edge : edges){
    ll first_node = edge.ff;
    ll second_node = edge.ss;
    cnt += ((adj[first_node] & adj[second_node]).count());
  }
  cout << cnt/3 << nl;

  //Time complexity: O(E*(V/word_size)) approx -> O(E*V);

}//no chakra
