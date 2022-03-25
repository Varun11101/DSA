//Task: Given width, length of the rectangle and the number of rectangles, find the minimmum side of the square that can fit in all the rectangles. No rotations allowed.
//here, we binary search on the answer, in this case, we binary search on the side of the square.

//We declare the following invariants.
// good(l) = 0, good(r) = 1

ll w, h, n;
bool good(ll x){
  return (x/w)*(x/h) >= n;
}
void Rasengan(){
  //full chakra
  //Binary search on the answer:

  //Binary search on the side of the square (x)
  cin >> w >> h >> n;
  ll l = 0, r = 1;

  while(!good(r)) r*=2; //this is done to prevent overflow

  //Invariants: 
  //good(l) = false
  //good(r) = true;

  while(r > l+1){
    ll m = (l+r)/2;
    if(good(m)) r = m;
    else l = m;
  }

  cout << r;
}//no chakra

