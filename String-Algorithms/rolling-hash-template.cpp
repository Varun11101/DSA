struct rollingHash {
  //Built by Varun11101
  long long B, n, mod;
  string s;
  vector<long long> pref, revpref, modpow, modinv;

  rollingHash(string str, long long base){
    mod = 1e9 + 7;
    n = str.size();
    s = str;
    B = base;
    // B = getRandomNumber(31, 69); //not for leetcode 
    pref.resize(n);
    modpow.resize(n+1);
    modinv.resize(n+1);

    if(n > 0) modpow[0] = 1;
    for(long long i = 1; i <= n; i++){
      modpow[i] = (modpow[i - 1] * B) % mod;
    }

    modinv[n] = modulo_inv(modpow[n]);
    for(long long i = n - 1; i >= 0; i--){
      modinv[i] = ((modinv[i + 1] % mod) * (B % mod)) % mod;
    }
    //generate the prefix array
    long long mul = 1;
    for(long long i = 0; i < n; i++){
      pref[i] = ((s[i] + 1) * (mul % mod)) % mod;
      if(i != 0){
        pref[i] = (pref[i - 1] + pref[i]) % mod;
      }
      mul = ((mul % mod) * B ) % mod;
    }
  }

  long long binpow(long long a, long long b, long long m) {
      a %= m;
      long long res = 1;
      while (b > 0) {
          if (b & 1)
              res = res * a % m;
          a = a * a % m;
          b >>= 1;
      }
      return res;
  }

  long long modulo_inv(long long n){
    return binpow(n, mod-2, mod);
  }

  long long subHash(long long l, long long r){
    long long ans = pref[r] % mod;
    if(l != 0) ans = (ans - pref[l - 1] + mod) %mod; 
    // ans = ((ans % mod) * (modulo_inv(binpow(B, l, mod)) % mod))% mod;
    ans = ((ans % mod) * (modinv[l] % mod)) % mod;
    return ans;
  }

  void buildPalindromeMode(){
    revpref.resize(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    long long mul = 1;
    for(long long i = 0; i < n; i++){
      revpref[i] = ((rev[i] + 1) * (mul % mod)) % mod;
      if(i != 0){
        revpref[i] = (revpref[i - 1] + revpref[i]) % mod;
      }
      mul = ((mul % mod) * B ) % mod;
    }
  }

  long long revSubHash(long long l, long long r){
    long long ans = revpref[r] % mod;
    if(l != 0) ans = (ans - revpref[l - 1] + mod) %mod; 
    // ans = ((ans % mod) * (modulo_inv(binpow(B, l, mod)) % mod))% mod;
    ans = ((ans % mod) *  (modinv[l] % mod))% mod;
    return ans;
  }

  bool isPalindrome(long long l, long long r){
    long long d = r - l, newL = n - 1 - r, newR = newL + d;
    if(subHash(l, r) == revSubHash(newL, newR)) return true;
    return false;
  }
};

