#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long int 
#define pb push_back
#define SIZE 1000005
#define pp pair<int,int>
using namespace std;
vector <int> nodes[SIZE];
int main() {
  int n,m,k,v,num;
  while (cin>>n>>m){
    for (int i=1;i<=SIZE;i++) nodes[i].clear();
    
    for (int i=1;i<=n;i++){
      cin>>num;
      nodes[num].pb(i);
    }
    
    for (int i=1;i<=m;i++){
      cin>>k>>v;
      int l,r,mid,temp=-1;
      l=0,r=nodes[v].size()-1;
      // cout<<l<<" "<<r<<"\n";
      while (l<=r){
        mid=((l+r)>>1);
        
        if (mid+1==k){
          temp=mid;
          // cout<<"NIGGA"<<nodes[v][temp]<<"\n";
          break;
        }else if (mid+1<k) l=mid+1;
        else r=mid-1;
      }
      
      if (temp!=-1) cout<<nodes[v][temp]<<"\n";
      else cout<<"0\n";
    }
  }
  return 0;
}
