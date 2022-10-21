#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int ary[1000005];
int used[1000005];
pp qq[1000005];
void bfs(int st,int ed,int l,int r,int n){
  pp cur,nxt;
  qq[0]=make_pair(st,0);
  used[0]=1;
  
  for (int i=0,j=1;i<j;i++){
    cur=qq[i];
    // cout<<cur.first<<"\n";
    if (cur.first==ed){
      cout<<cur.second;
      return;
    }else{
      nxt=cur;
      if (nxt.first-l>=0 and ary[nxt.first-l]!=n and !used[ary[nxt.first-l]]){
        used[ary[nxt.first-l]]=1;
        nxt.first=ary[nxt.first-l];
        nxt.second++;
        qq[j]=nxt;
        j++;
      }
      nxt=cur;
      if (nxt.first+r<=n and ary[nxt.first+r]!=n and !used[ary[nxt.first+r]]){
        used[ary[nxt.first+r]]=1;
        nxt.first=ary[nxt.first+r];
        nxt.second++;
        qq[j]=nxt;
        j++;
      }
    }
  }
  cout<<-1;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,st,ed,l,r;
  cin>>n>>ed>>l>>r;
  st=0;
  for (int i=0;i<n;i++){
    cin>>ary[i];
    if (ary[i]<0 or ary[i]>=n) ary[i]=n;
  }
  
  bfs(st,ed,l,r,n);
  return 0; 
}
