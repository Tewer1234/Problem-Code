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
map <int,int> mp1;
map <int,int> c;
struct node{
  int num,occ,change;
};
node cards[SIZE];
bool comp(node a,node b){
  if (a.change<b.change) return true;
  else return false;
}
int main() {
  int a,b,n,req,total,cnt=0;
  cin>>n;
  req=(n/2)+(n%2);
  for (int i=1;i<=n;i++){
    cin>>a>>b;
    mp1[a]++;
    if (a!=b){
      mp1[b]++;
      c[b]++;
    }
  }
  
  for (auto it1:mp1){
    int change;
    auto it2=c.find(it1.first);
    if (it2!=c.end()) change=c[it1.first];
    else change=0;
    
    if (it1.second-change>=req) change=0;
    else change=(req-(it1.second-change));
    if (it1.second>=req){
      cnt++;
      cards[cnt].num=it1.first;
      cards[cnt].occ=it1.second;
      cards[cnt].change=change;
    }
  }
  
  sort(cards+1,cards+cnt+1,comp);
  // for (int i=1;i<=cnt;i++){
  //   cout<<cards[i].num<<" "<<cards[i].occ<<" "<<cards[i].change<<"\n";
  // }
  int l,r,mid,ans=INT_MAX;
  l=1,r=cnt;
  while (l<=r){
    mid=((l+r)>>1);
    if (cards[mid].occ<req) l=mid+1;
    else{
      ans=cards[mid].change;
      r=mid-1;
    }
  }
  if (ans==INT_MAX) cout<<-1;
  else cout<<ans;
  return 0;
}
