//Uva 10131 - Is BIgger Smarter?
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct node{
  int w,s,pos;
};
node ary[1000000];
int dp[10000000],prevs[1005][1005],cur[1000000];
bool comp(node a,node b){
  return a.w<=b.w;
}
void rec(int last,int id){
  if (!id){
    return;
  }else{
    rec(prevs[cur[ary[last].pos]][id-1],id-1);
    cout<<ary[last].pos<<"\n";
  }
}
int main() {
  int n,m,cnt=0;
  while (cin>>n>>m){
    cnt++;
    ary[cnt].w=n;
    ary[cnt].s=m;
    ary[cnt].pos=cnt;
  }
  sort(ary+1,ary+cnt+1,comp);
  for (int i=1;i<=cnt;i++){
    cur[ary[i].pos]=i;
  }
  // for (int i=1;i<=cnt;i++){
  //   cout<<ary[i].pos<<": "<<ary[i].w<<" "<<ary[i].s<<"\n";
  // }
  for (int i=1;i<=cnt;i++){
    for (int j=1;j<i;j++){
      if (ary[i].w>ary[j].w and ary[i].s<ary[j].s){
        if (dp[i]<dp[j]+1){
          dp[i]=dp[j]+1;
          prevs[i][dp[j]+1]=j;
        }
      }
    }
  }
  int maxSum=-1,last;
  for (int i=1;i<=cnt;i++){
    if (maxSum<dp[i]){
      maxSum=dp[i];
      last=i;
    }
  }
  maxSum++;
  cout<<maxSum<<"\n";
  // cout<<last<<" "<<ary[last].pos<<"\n";
  // for (int i=1;i<=cnt;i++){
  //   cout<<i<<": ";
  //   for (int j=1;j<=dp[i];j++){
  //     cout<<ary[prevs[i][j]].pos<<" ";
  //   }
  //   cout<<"\n";
  // }
  rec(last,maxSum);
  return 0;
}
