#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <stack>
#define SIZE 400005
#define ll long long int
#define pp pair<int,int>
#define pb push_back
using namespace std;
vector <pp> nodes;
int qq[SIZE*4];
int used[SIZE];
bool bfs(int st,int ed,int n){
  int pos;
  pp cur,nxt;
  memset(used,0,sizeof(used));
  qq[0]=st;
  used[st]=1;
  for (int i=0,j=1;i<j;i++){
    pos=qq[i];
    cur=nodes[pos];
    if (pos==ed){
      return true;
    }else{
      for (int k=0;k<n;k++){
        nxt=nodes[k];
        if (!used[k] and ((nxt.first<cur.first and cur.first<nxt.second) or (nxt.first<cur.second and cur.second<nxt.second))){
          used[k]=1;
          qq[j]=k;
          j++;
        }
      }
    }
  }
  return false;
}
int main() {
  int n,op,a,b;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>op>>a>>b;
    if (op==1){
      nodes.pb(make_pair(a,b));
    }else{
      a--,b--;
      if (bfs(a,b,nodes.size())) cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
  return 0;
}
