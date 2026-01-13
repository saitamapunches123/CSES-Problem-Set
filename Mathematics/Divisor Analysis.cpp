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
int mod1=mod-1;
void compute() { // compute() fn only runs once.

}
//Binary exponeantation
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
ll sumGPMod(ll a, ll r, ll n) {
    if (n == 0) return 0;

    a %= mod;
    r %= mod;

    if (r == 1)
        return (a * (n % mod)) % mod;

    ll rn = mod_exp(r, n, mod);
    ll num = (rn - 1 + mod) % mod;
    ll inv = mod_exp(r - 1, mod - 2, mod); // mod must be prime

    return a * num % mod * inv % mod;
}
ll sum_n(ll n) {
    return n * (n + 1) / 2;
}
ll big_power_exponent(ll a,ll x,ll mod){
    x=x%mod1;
    return mod_exp(a,x,mod);
}
void solve() {	
  int n;cin>>n;
  int num_divisors=1,sum_divisors=1,prod_div=1,pref=1;
  for(int i=0;i<n;i++){
    int p,cnt;cin>>p>>cnt;
    int cnt1=cnt+1;
    num_divisors=(num_divisors*cnt1)%mod;
    sum_divisors=(sum_divisors*sumGPMod(1,p,cnt1))%mod;
    int tp=sum_n(cnt)%mod1;
    int y=big_power_exponent(p,pref*tp,mod);
    // cout<<prod_div<<endl;
    prod_div=big_power_exponent(prod_div,cnt1,mod);
    // cout<<prod_div<<endl;
    // cout<<p<<" "<<tp<<" "<<y<<endl;
    prod_div=(prod_div*y)%mod;
    pref=(pref*cnt1)%mod1;
  }
  cout<<num_divisors<<" "<<sum_divisors<<" "<<prod_div<<endl;
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