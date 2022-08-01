#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#define ll long long int 
using namespace std;
typedef pair<int,int> pp;
pp ary[1000000];
bool comp(pp a,pp b){
  if (a.first<b.first) return true;
  else if (a.first==b.first and a.second<b.second) return true;
  else return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i].first>>ary[i].second;
  }
  sort(ary+1,ary+n+1,comp);
  int st=ary[1].first,ed=ary[1].second,rooms=1;
  for (int i=1;i<=n;i++){
    if (ary[i].first>ed){
      rooms++;
      st=ary[i].first;
      ed=ary[i].second;
    }else if (ary[i].second<ed){
      ed=ary[i].second;
    }
  }
  cout<<rooms;
  return 0;
}
