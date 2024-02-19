#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define ll long long int 
#define pb push_back
#define SIZE 400005
#define pp pair<int,int>
using namespace std;
ll ans[SIZE];
ll ary[SIZE];
priority_queue <pp,vector<pp>,greater<pp>>pq;
int main() {
  int n;
  while (cin>>n){
    for (int i=1;i<=n;i++){
      cin>>ans[i];
    }
    
    sort(ans+1,ans+n+1);
    
    for (int i=2;i<=n;i++){
      for (int j=1;j<=n;j++) cin>>ary[j];
      
      sort(ary+1,ary+n+1);
      
      for (int j=1;j<=n;j++) pq.push(make_pair(ans[j]+ary[1],1));
      
      for (int j=1;j<=n;j++){
        pp cur=pq.top();
        pq.pop();
        ans[j]=cur.first;
        if (cur.second+1<=n){
          pq.push(make_pair(cur.first-ary[cur.second]+ary[cur.second+1],cur.second+1));
        }
      }
      
      while (!pq.empty()) pq.pop();
    }
    
    for (int i=1;i<=n;i++){
      cout<<ans[i];
      if (i!=n) cout<<" ";
      else cout<<"\n";
    }
  }
  return 0;
}
