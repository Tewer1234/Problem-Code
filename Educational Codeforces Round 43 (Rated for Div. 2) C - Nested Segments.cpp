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
#define DiscordModerator 1e9+7
using namespace std;
struct node{
  int l,r,id;
};
node ary[SIZE];
bool comp(node a,node b){
  if (a.l<b.l) return true;
  else if (a.l==b.l and a.r>b.r) return true;
  else return false;
}
int main() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i].l>>ary[i].r;
    ary[i].id=i;
  }
  
  int ansl=-1,ansr=-1,l,r,id;
  
  sort(ary+1,ary+n+1,comp);
  
  l=ary[1].l,r=ary[1].r,id=ary[1].id;
  for (int i=2;i<=n;i++){
    // cout<<ary[i].l<<" "<<ary[i].r<<" "<<l<<" "<<r<<"\n";
    if (ary[i].l>=l and ary[i].r<=r){
      ansl=id;
      ansr=ary[i].id;
      break;
    }else{
      l=ary[i].l;
      r=ary[i].r;
      id=ary[i].id;
    }
  }
  cout<<ansr<<" "<<ansl;
  return 0;
}
