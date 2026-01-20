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
vector<int> facts(25);
void compute() { // compute() fn only runs once.
  facts[0]=1;
  for(int f=1;f<=20;f++){
    facts[f]=f*facts[f-1];
    // cout<<f<<" "<<facts[f]<<endl;
  }
}

void solve() {	
  int op,n;cin>>op>>n;
  if(op==1){
    int k;cin>>k;
    vector<int> p(n);
    vector<bool> used(n+1,false);
    for(int i=0;i<n;i++){
      int sz=n-i-1;
      int cnt=facts[sz];
      for(int x=1;x<=n;x++){
        if(used[x]==true)
          continue;
        if(k>cnt){
          k-=cnt;
          continue;
        }
        p[i]=x;
        used[x]=true;
        break;
      }
    }
    for(auto x:p)
      cout<<x<<" ";
    cout<<endl;
  }else{
    vector<int> p(n);
    vector<bool> used(n+1,false);
    for(int i=0;i<n;i++)
      cin>>p[i];
    int ans=1;
    for(int i=0;i<n;i++){
      int sz=n-i-1;
      int cnt=facts[sz];
      for(int x=1;x<=n;x++){
        if(used[x]==true)
          continue;
        if(p[i]==x){
          used[x]=true;
          break;
        }
        ans+=cnt;
      }
      // cout<<ans<<endl;
    }
    cout<<ans<<endl;

  }

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