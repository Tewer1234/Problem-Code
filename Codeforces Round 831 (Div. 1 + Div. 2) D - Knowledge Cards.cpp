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
ll ary[SIZE*5];
int main() {
  ll t,r,c,k;
  cin>>t;
  while (t--){
    priority_queue <ll,vector<ll>> pq;
    cin>>r>>c>>k;
    for (int i=1;i<=k;i++) cin>>ary[i];
    ll block=r*c-4,temp=k,flag=1;
    for (int i=1;i<=k;i++){
      // cout<<temp<<" "<<pq.size()<<"\n";
      if (ary[i]!=temp){
        pq.push(ary[i]);
      }else{
        if (pq.size()>block){
          flag=0;
          break;
        }
        temp--;
        while (!pq.empty()){
          if (pq.top()==temp){
            pq.pop();
            temp--;
          }else{
            break;
          }
        }
      }
    }
    // cout<<temp<<" "<<pq.size()<<"\n";
    if (flag and (!pq.empty() or temp)) flag=0;
    // while (!pq.empty()){
    //   cout<<pq.top()<<"\n";
    //   pq.pop();
    // }
    // cout<<"\n";
    
    if (flag) cout<<"YA\n";
    else cout<<"TIDAK\n";
  }
  return 0;
}
