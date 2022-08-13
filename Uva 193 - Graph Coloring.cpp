#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#define ll long long int 
#define pb push_back
using namespace std;
typedef pair<int,int> pp;
map <int,int> mp;
vector <int> nodes[100000],blacked,check;
int used[100000],ans;
void dfs(int n,int N){
  int nxt,flag;
  // cout<<n<<": ";
  // for (int i=1;i<=N;i++) cout<<check[i]<<" ";
  // cout<<"\n";
  if (n>N){
    int temp=blacked.size();
    if (temp>ans){
      check=blacked;
      ans=temp;
    }
    return;
  }
  
  flag=1;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    if (used[nxt]){
      flag=0;
      break;
    }
  }
  if (flag){
    used[n]=1;
    blacked.pb(n);
    // for (int i=1;i<=N;i++) cout<<check[i]<<" ";
    // cout<<"\n"; 
    dfs(n+1,N);
    blacked.pop_back();
    used[n]=0;
  }
  dfs(n+1,N);
  
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t,n,k,x,y,temp;
  cin>>t;
  while (t--){
    cin>>n>>k;
    ans=temp=0;
    blacked.clear();
    check.clear();
    memset(used,0,sizeof(used));
    for (int i=1;i<=n;i++){
      nodes[i].clear();
    }
    for (int i=1;i<=k;i++){
      cin>>x>>y;
      nodes[x].pb(y);
      nodes[y].pb(x);
    }
    dfs(1,n);
    cout<<ans<<"\n";
    for (int i=0;i<check.size();i++){
      cout<<check[i];
      if (i!=check.size()-1) cout<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
