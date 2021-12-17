//Refer: cp-algorithms

void Rasengan(){
 //full chakra | Chunking, DP
  //Segmented Sieve:
  //Why do we use it? To find primes in a range
  //especially when L, R > 1e7/8 
  //provided R-L+1 ~ 1e6

  //How does it work?
  //We know that, in a regular prime check, all we
  //need to do is iterate from 2 until root n and check
  //if it is divisible by any one of them or not. Similarly,

  //1) We generate all the primes until sqrt(R) using regular sieve.
        //this step can be skipped, but the time complexity will be higher.
  //2) For each prime, we can mark its multiples in the range of L,R as composite.
  //3) The remaining unmarked elements are primes numbers.

  //Note:
  //How do you find the first multiple of a number that is greater than or equal to L?
  //- Divide L by the number to get a some integer k
  //- Multiply k with the number to get the closest multiple of the number to L
  //- However, this number can be lesser than L
  //- So, if ans < L : ans += num

  //Problem: Generate all primes between 5 and 19 (inclusive)
  ll L, R; cin >> L >> R;
  vll primes;
  vll sieve(R+1, 1);
  sieve[0] = sieve[1] = 0;
  for(int i=2; i*i*1LL <= R; i++){
    if(!sieve[i]) continue;
    for(int j=i*i; j<=R; j+=i){
      sieve[j] = 0;
    }
  }
  FOR(i,2,R+1){
    if(i*i>R) break;
    if(sieve[i]) primes.pb(i);
  }
  vll isPrime(R-L+1, 1);
  for(ll i : primes){
    //Find the first multiple of i that is >= L
    ll fm = (L/i) * i;
    if(fm<L) fm+=i;
    for(ll j = fm; j<=R; j+=i){
      isPrime[j-L] = 0;
    }
  }

  cout << "List of primes numbers between L and R are: " << nline;
  for(ll i=L; i<=R; i++){
    if(isPrime[i-L]){
      cout << i << nline;
    }
  }
  
  //Time complexity:
  //For generating primes upto root R:  O(sqrt(R)*loglog(sqrt(R)))
  // + O(R-L+1loglog(R))
}//no chakra
