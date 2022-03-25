//Reference: CF EDU Module 1: Question 1

void PreCompute(){}
void Rasengan(){
 //full chakra

  //Q1) Standard binary search algorithm:
  //To find whether the element exists in the array or not
  // ll n, k; cin >> n >> k;
  // vll a(n); cin >> a;
  // FOR(j,0,k){
  //   ll x; cin >> x;
  //   ll l = 0, r = n-1;
  //   bool found = false;
  //   while(l <= r){
  //     ll m = (l+r)/2;
  //     if(a[m] == x){
  //       found = true;
  //       break;
  //     }
  //     else if(a[m] < x){
  //       l = m+1;
  //     }
  //     else if(a[m] > x){
  //       r = m-1;
  //     }
  //   }
  //   cout << (found? "YES" : "NO") << nl;
  // }

  //Q1: Using a modified binary search where l and r pointers
  //    have an invariant

  ll n, k; cin >> n >> k;
  vll v(n); cin >> v;
  FOR(j,0,k){
    ll x; cin >> x;
    //Invariants for l and r to be maintained:
    //a[l] <= x
    //a[r] > x

    ll l = -1, r = n;
    //We assume that a[-1] = -INF and a[n] = INF (just assume),
    //then our initial invariant always holds true.

    //If we had done l = 0, r = n-1, our invariant might not 
    // necessarily hold true.

    //Ex: If all the elements in our array were to be > x,
    //then a[l] <= x property would be false.

    //We keep performing the binary search algo until l and r 
    //are adjacent to each other.

    while(l+1 < r){
      ll m = (l+r)/2;
      if(v[m] <= x) l = m;
      else if(v[m] > x) r = m;
    }

    //Now, if the element is indeed present in the array, then it must
    //be in the a[l].

    if(l >= 0 && l<n && v[l] == x){
      cout << "YES" << nl;
    }
    else{
      cout << "NO" << nl;
    }
  }
}//no chakra
