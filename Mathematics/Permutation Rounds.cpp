#include <bits/stdc++.h>
using namespace std;
#include <algorithm> // sqrtl() __gcd() 
#include <numeric>
#include <cmath>
#include <iomanip>//to do setprecision(3)
#define int long long
#define ll long long 
#define ld long double
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
using tii=tuple<int,int,int>;
using pii=pair<int,int>;
//pow(2LL,n)
//float< double< long double
//10^9+7=1e9+7
//stoi, stoll(for long long)
/* 
1) You can do it!! because you have done it before.
2) Dont worry today might not be your day.
3) Start Fresh, Dry Run, Do Maths if you get stuck.
4) Re-Write full code if implementation gets lenghty.
*/


vector<int>spf;
void build_spf(int n){ //SIMILLAR TO SIEVE but here spf[i] is the smallest prime factor of i
  spf.assign(n+1,0);
  for(int i=1;i<=n;i++)
    spf[i]=i;
  for(int i=2;i*i<=n;i++){
    if(spf[i]==i){//i is prime
      for(int j=i*i;j<=n;j+=i){
        if(spf[j]==j)
          spf[j]=i;
      }
    }
  }
}
void compute() { // compute() fn only runs once.
  build_spf(1e6);
}
map<int,int> prime_factorize(int x){
  map<int,int> ans; // if we want distinct primes else use vector
  while(x>1){
    ans[spf[x]]++;
    x=x/spf[x];
  }
  return ans;
}
int mod=1e9+7;
ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
// PS: using pairwise gcd and finding lcm(a1,a2,a3)=> lcm(lcm(a1,a2),a3) under mod will not work as lcm(x,y)=x*y/gcd(x,y) but if x lcm till now is kept in mod gcd(x,y) will not work
// lcm of(a1,a2,a3...an) => p1^mx1*p2^mx2*p3^mx3 -> mx1 => max times p1 prime factor comes in any of the ai's.
int lcm_array_mod(vector<int> &arr){
  map<int,int> max_freq;
  for(auto x:arr){
    map<int,int> facts=prime_factorize(x);
    for(auto [x,f]:facts)
      max_freq[x]=max(max_freq[x],f);
  }
  int lcm=1;
  for(auto [x,f]:max_freq)
    lcm=(lcm*mod_exp(x,f,mod))%mod;
  return lcm;
}
void solve() {	
  int n;cin>>n;
  vector<int> p(n+1);
  for(int i=1;i<=n;i++)
    cin>>p[i];
  vector<bool> vis(n+1,false);
  vector<int> cycles;
  for(int i=1;i<=n;i++){
    if(vis[i])
      continue;
    int u=i,sz=0;
    while(vis[u]==false){
      vis[u]=true;
      u=p[u];
      sz++;
    }
    cycles.push_back(sz);
  }
  cout<<lcm_array_mod(cycles)<<endl;

}

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
}
signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fast();
  compute();
  int t=1;
  while (t--)
  {
    // cout << t;
    solve();
  }
  //int x=10,a=3;
  //double d =ceil((1.0*x)/a);
  //cout <<fixed<< setprecision(22) << d;
  //fixed keeps the data in numeric and not scientefic i.e (1e)
}
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣠⣶⡾⠏⠉⠙⠳⢦⡀⠀⠀⠀⢠⠞⠉⠙⠲⡀⠀
⠀⠀⠀⣴⠿⠏⠀⠀⠀⠀⠀⠀⢳⡀⠀  ⡏⠀⠀⠀⠀⠀⢷
⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀⣧⠀⢸⠀⠀⠀⠀⠀ ⡇
⠀⠀⢸⣯⡭ ⠸⣛⣟⠆⡴⣻⡲⣿⠀⣸⠀⠀OK⠀ ⡇
⠀⠀⣟⣿⡭⠀⠀⠀⠀⠀⢱⠀⠀⣿⠀ ⢹⠀⠀⠀⠀⠀ ⡇
⠀⠀⠙⢿⣯⠄⠀⠀⠀⢀⡀⠀⠀⡿⠀⠀⡇⠀⠀⠀ ⠀⡼
⠀⠀⠀⠀⠹⣶⠆⠀⠀⠀⠀⠀⡴⠃⠀⠀ ⠘⠤⣄⣠⠞⠀
⠀⠀⠀⠀⠀⢸⣷⡦⢤⡤⢤⣞⣁⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣤⣴⣿⣏⠁⠀⠀⠸⣏⢯⣷⣖⣦⡀⠀⠀⠀⠀⠀⠀
⢀⣾⣽⣿⣿⣿⣿⠛⢲⣶⣾⢉⡷⣿⣿⠵⣿⠀⠀⠀⠀⠀⠀
⣼⣿⠍⠉⣿⡭⠉⠙⢺⣇⣼⡏⠀⠀⠀⣄⢸⠀⠀⠀⠀⠀⠀
⣿⣿⣧⣀⣿.........⣀⣰⣏⣘⣆⣀⠀⠀
*/