//Concepts used: XOR sum + Contribution technique
//Problem link: https://atcoder.jp/contests/abc147/tasks/abc147_d

void PreCompute(){}
void Rasengan(){
 //full chakra
  ll n; cin >> n;
  vll v(n); cin >> v;
  ll ans = 0;
  for(ll bit= 0; bit < 63; bit++){
    ll z = 0, o = 0, total = 0;
    FOR(i,0,n){
      if(v[i] & (1LL << bit)){
        o++;
      }
      else z++;
    }
    total = z*o;
    total %= MOD;
    ans += ((((1LL << bit)%MOD)*total)%MOD);
    ans %= MOD;
  }
  cout << ans;
