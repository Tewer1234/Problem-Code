//Uva 336 - A Node Too Far
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <map>
#define ll long long int 
using namespace std;
struct data{
  string val;
  int path;
};
data qq[1000000];
int check[10000];
vector <int> nodes[100000];
map <string,int> mp;
map <int,string> key;
int bfs(string q,int ttl){
  int ans=0;
  data cur,next;
  qq[0].val=q;
  qq[0].path=0;
  check[mp[q]]=1;
  ans++;
  for (int i=0,j=1;i<j;i++){
    cur=qq[i];
    // cout<<cur.val<<":\n";
    for (int k=0;k<nodes[mp[cur.val]].size();k++){
      int t=nodes[mp[cur.val]][k];
      if (!check[t] and cur.path+1<=ttl){
        // cout<<key[t]<<" ";
        ans++;
        check[t]=1;
        qq[j].val=key[t];
        qq[j].path=cur.path+1;
        j++;
      }
    }
    // cout<<"\n";
  }
  // cout<<"\n";
  return ans;
}
int main() {
  int n,cnt,ttl,cases=1;
  string from,to,q;
  while (cin>>n and n){
    cnt=0;
    mp.clear();
    key.clear();
    for (int i=0;i<=100;i++){
      nodes[i].clear();
    }
    for (int i=1;i<=n;i++){
      cin>>from>>to;
      auto it1=mp.find(from),it2=mp.find(to);
      if (it1==mp.end()){
        cnt++;
        mp[from]=cnt;
        key[cnt]=from;
      } 
      if (from!=to and it2==mp.end()){
        cnt++;
        mp[to]=cnt;
        key[cnt]=to;
      }
      if (from!=to){
        nodes[mp[from]].push_back(mp[to]);
        nodes[mp[to]].push_back(mp[from]);
      }
      // cout<<nodes[mp[from]][nodes[mp[from]].size()-1]<<"\n";
      // cout<<mp[from]<<" "<<mp[to]<<"\n";
    }
    // cout<<cnt<<"\n";
    while (cin>>q>>ttl){
      memset(check,0,sizeof(check));
      if (q=="0" and !ttl) break;
      int temp=0;
      auto it3=mp.find(q);
      if (it3!=mp.end()) temp=bfs(q,ttl);
      cout<<"Case "<<cases<<": "<<cnt-temp<<" nodes not reachable from node "<<q<<" with TTL = "<<ttl<<".\n";
      cases++;
    }
  }
  return 0;
}
