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
struct Combinatorics {
    vector<ll> facts, inv_facts;
    Combinatorics(int max_n) {
        facts.resize(max_n + 1);
        inv_facts.resize(max_n + 1);

        facts[0] = facts[1] = 1;
        for (ll i = 2; i <= max_n; i++) {
            facts[i] = (facts[i - 1] * i) % mod;
        }

        inv_facts[max_n] = mod_exp(facts[max_n], mod - 2, mod); //asuming mod to be prime else use extended euclidian
        for (ll i = max_n - 1; i >= 0; i--) {
            inv_facts[i] = (inv_facts[i + 1] * (i + 1)) % mod;
        }
    }

    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        ll num = facts[n];
        ll den = (inv_facts[r] * inv_facts[n - r]) % mod;
        return (num * den) % mod;
    }
    vector<ll> get_facts(){
      return facts;
    }
    ll nPr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        ll num = facts[n];
        ll den = inv_facts[n - r];
        return (num * den) % mod;
    }
    /*
    usefull to find the number of ways to distribute n identical items in k boxes
    OR
    number of solution to x1+x2+...xk=n for xi>=0
    ans=n+k-1 C n=n+k-1 C k-1
    */
    ll stars_and_bars(ll items,ll boxes){
      return nCr(items+boxes-1,items);
    }
};
Combinatorics obj(1);
void compute() { // compute() fn only runs once.
  obj = Combinatorics(1e6);
}

void solve() {	
  int n,r;cin>>n>>r;
  cout<<obj.nCr(n,r)<<endl;
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
  int t;cin>>t;
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