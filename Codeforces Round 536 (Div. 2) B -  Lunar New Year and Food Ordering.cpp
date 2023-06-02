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
#define pp pair<ll,int>
#define pb push_back
using namespace std;
ll ary[SIZE];
ll cost[SIZE];
struct cmp{
  bool operator()(pp a,pp b){
    if (a.first>b.first) return true;
    else if (a.first==b.first and a.second>b.second) return true;
    else return false;
  }
};
int main() {
  ll total=0;
  ll n,m,t,d,dif;
  priority_queue <pp,vector<pp>,cmp> pq;
  cin>>n>>m;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=n;i++) cin>>cost[i];
  
  for (int i=1;i<=n;i++) pq.push(make_pair(cost[i],i));
  
  for (int i=1;i<=m;i++){
    cin>>t>>d;
    total=0;
    if (pq.empty()) cout<<0<<"\n";
    else{
      if (ary[t]>0){
        dif=min(ary[t],d);
        d-=dif;
        ary[t]-=dif;
        total+=(cost[t]*dif);
      }
      while (d>0){
        // cout<<i<<": "<<total<<"total\n";
        if (pq.empty()) break;
        else{
          pp cur=pq.top();
          if (!ary[cur.second]){
            pq.pop();
          }else{
            pq.pop();
            dif=min(ary[cur.second],d);
            // cout<<cur.second<<" "<<dif<<"\n";
            d-=dif;
            ary[cur.second]-=dif;
            total+=(cost[cur.second]*dif);
            if (ary[cur.second]) pq.push(make_pair(cost[cur.second],cur.second));
          }
          // cout<<d<<" "<<pq.size()<<"fr\n";
        }
      }
      // cout<<ary[6]<<"mnn\n";
      if (d>0) cout<<0<<"\n";
      else cout<<total<<"\n";
    }
  }
  return 0;
}
