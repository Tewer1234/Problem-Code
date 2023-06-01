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
#define pb push_back()
using namespace std;
ll ary[SIZE];
ll bry[SIZE];
ll dif[SIZE];
int main() {
  ll n,k1,k2,k;
  priority_queue <ll> pq;
  cin>>n>>k1>>k2;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=n;i++) cin>>bry[i];
  
  k=k1+k2;
  
  ll ans=0,cur;
  for (int i=1;i<=n;i++){
    pq.push(abs(ary[i]-bry[i]));
  }
  
  while (k>0){
    cur=pq.top();
    pq.pop();
    pq.push(abs(cur-1));
    k--;
  }
  
  while (!pq.empty()){
    cur=pq.top();
    pq.pop();
    ans+=(cur*cur);
  }
  cout<<ans;
  return 0;
}
