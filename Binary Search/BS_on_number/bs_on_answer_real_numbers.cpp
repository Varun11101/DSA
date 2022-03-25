//Binary search on answer -> real numbers
//Reference: Codeforces EDU Step 2, problem 3
void PreCompute(){}
ll n, k;
bool good(lld x, vector<ll> &v){
  ll cnt = 0;
  FOR(i,0,n){
    cnt += floor((lld)v[i]/x);
  }
  return cnt >= k;
}
void Rasengan(){
 //full chakra
  //Binary search for answer on real numbers
  cin >> n >> k;
  vll v(n); cin >> v;
  lld l = 0, r = (lld)(maxv(v)+1);
  ll temp = 100;
  while(temp--){
    //Invariants
    //good(l) = 1, good(r) = 0
    lld m = (lld)(l+r)/(lld)2;
    if(good(m, v)) l = m;
    else r = m;
  }
  cout << fixed << setprecision(6);
  cout << l << nl;
}//no chakra
