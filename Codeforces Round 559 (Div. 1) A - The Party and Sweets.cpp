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
int ary[SIZE];
int bry[SIZE];
bool comp(int a,int b){
  return a>b;
}
int main() {
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=m;i++) cin>>bry[i];
  
  sort(ary+1,ary+n+1,comp);
  sort(bry+1,bry+m+1,comp);
  
  if (ary[1]>bry[m]) cout<<-1;
  else{
    unsigned ll total=0;
    if (ary[1]<bry[m]){
      for (int i=1;i<=n;i++) total+=((ll)ary[i]*m);
      for (int i=1;i<=m;i++) total+=bry[i];
      total-=( ((ll)ary[1]*(m-1))+ary[2]);
    }else if (ary[1]==bry[m]){
      for (int i=1;i<=n;i++) total+=((ll)ary[i]*m);
      for (int i=1;i<=m;i++) total+=bry[i];
      total-=((ll)ary[1]*m);
    }
    cout<<total;
  }
  return 0;
}
