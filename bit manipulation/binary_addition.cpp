//A simple, straightforward program for addition of two numbers in binary

void PreCompute(){}
void Rasengan(){
 //full chakra
  ll a, b; cin >> a >> b;
  ll res = 0, carry = 0;
  FOR(i,0,64){
    ll tot = 0;
    tot += carry;
    if(a & (1LL << i)) tot++;
    if(b & (1LL << i)) tot++;
    if(tot == 1){
      res += (1LL << i);
      carry= 0;
    }
    else if(tot == 2){
      carry = 1;
    }
    else if(tot == 3){
      res += (1LL << i);
      carry = 1;
    }
  }
  cout << res << nl;
}//no chakra
