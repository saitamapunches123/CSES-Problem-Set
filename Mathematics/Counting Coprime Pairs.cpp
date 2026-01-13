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
vector<int> spf;
int max_x=1e6;
vector<int> build_spf(int n){ //SIMILLAR TO SIEVE but here spf[i] is the smallest prime factor of i
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
  return spf;
}
void compute() { // compute() fn only runs once.
  spf=build_spf(max_x);
}
vector<int> prime_factorize(int x){
  set<int> ans;
  while(x>1){
    ans.insert(spf[x]);
    x=x/spf[x];
  }
  return vector<int>(ans.begin(),ans.end());
}
void solve() {	
  int n;cin>>n;
  vector<int> a(n),div_cnt(max_x+1);
  for(int i=0;i<n;i++)
    cin>>a[i];
  int ans=0;
  for(int i=0;i<n;i++){
    vector<int> facts=prime_factorize(a[i]);
    // cout<<a[i]<<":"<<endl;
    int m=facts.size();
    int subsets=1<<m,rem=0;
    for(int mask=1;mask<subsets;mask++){
      int val=1,cnt=0;
      for(int j=0;j<m;j++){
        int rep=1<<j;
        if(rep&mask){
          cnt++;
          int f=facts[j];
          val=val*f;
        }
      }
      // cout<<mask<<" "<<cnt<<" "<<val<<endl;
      if(cnt%2)
        rem+=div_cnt[val];
      else
        rem-=div_cnt[val];
      div_cnt[val]++;
    }
    // cout<<a[i]<<" "<<rem<<endl;
    ans+=i-rem;
  }
  cout<<ans<<endl;

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