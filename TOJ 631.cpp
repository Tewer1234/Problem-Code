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
int indeg[1000005],outdeg[1000005],parent[1000005],child[1000005];
map <int,double> mp[1000005];
vector <int> qq;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N,E,a,b,r;
  double temp,total;
  cin>>N>>E;
  while (E--){
    cin>>a>>b>>r;
    indeg[b]++;
    outdeg[a]++;
    auto it=mp[a].find(b);
    if (it==mp[a].end()){
      parent[b]=a;
      child[a]=b;
      mp[a][b]=r;
    }else{
      outdeg[a]--;
      indeg[b]--;
      temp=mp[a][b];
      temp=(1.0/temp)+(1.0/r);
      temp=(1.0/temp);
      mp[a][b]=temp;
    }
  }
  
  
  // for (int i=1;i<=N;i++){
  //   cout<<i<<" "<<indeg[i]<<" "<<outdeg[i]<<":\n";
  //   for (auto it:mp[i]){
  //     cout<<i<<" --> "<<it.first<<": "<<it.second<<"\n";
  //   }
  // }
  // for (int i=1;i<=N;i++) cout<<parent[i]<<" ";
  // cout<<"\n";
  
  
  for (int i=1;i<=N;i++){
    if (indeg[i]==1 and outdeg[i]==1){
      qq.pb(i);
    }
  }
  
  for (int i=0;i<qq.size();i++){
    int cur,nxt,prev;
    cur=qq[i];
    nxt=child[cur];
    prev=parent[cur];
    // cout<<prev<<" "<<cur<<" "<<nxt<<"\n";
    // cout<<indeg[cur]<<" "<<outdeg[cur]<<"\n";
    if (indeg[cur] and outdeg[cur]){
      indeg[cur]--;
      outdeg[cur]--;
      total=mp[prev][cur]+mp[cur][nxt];
      mp[cur].erase(nxt);
      mp[prev].erase(cur);
      child[prev]=nxt;
      parent[nxt]=prev;
      auto it=mp[prev].find(nxt);
      if (it==mp[prev].end()){
        mp[prev][nxt]=total;
      }else{
        indeg[nxt]--;
        outdeg[prev]--;
        temp=(1.0/mp[prev][nxt])+(1.0/total);
        total=(1.0/temp);
        mp[prev][nxt]=total;
      }
      if (indeg[prev]==1 and outdeg[prev]==1){
        qq.pb(prev);
      }else if (indeg[nxt]==1 and outdeg[nxt]==1){
        qq.pb(nxt);
      }
    }
    // cout<<prev<<" "<<cur<<" "<<nxt<<": "<<mp[prev][nxt]<<"\n";
    // cout<<indeg[nxt]<<" "<<outdeg[nxt]<<"\n";
  }
  cout<<fixed<<setprecision(6)<<mp[1][2]<<"\n";
  return 0;
}

