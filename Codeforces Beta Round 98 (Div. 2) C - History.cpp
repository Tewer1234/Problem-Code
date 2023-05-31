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
pp ary[SIZE];
bool comp(pp a,pp b){
  if (a.first<b.first) return true;
  else if (a.first==b.first and a.second>b.second) return true;
  else return false;
}
int main() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i].first>>ary[i].second;
  }
  
  sort(ary+1,ary+n+1,comp);
  
  int ans=0;
  int l,r;
  l=ary[1].first, r=ary[1].second;
  for (int i=2;i<=n;i++){
    if (ary[i].first>=l and ary[i].second<=r) ans++;
    else{
      l=ary[i].first;
      r=ary[i].second;
    }
  }
  cout<<ans;
  return 0;
}
