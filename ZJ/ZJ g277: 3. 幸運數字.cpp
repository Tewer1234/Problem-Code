//g277: 3. 幸運數字
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct node{
  int val,pos;
};
node ary[10000000];
ll psum[10000000];
bool comp(node a, node b){
  if (a.val<b.val) return true;
  else if (a.val==b.val and a.pos<b.pos) return true;
  else return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,num;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i].val;
    ary[i].pos=i;
    psum[i]=psum[i-1]+ary[i].val;
  }
  sort(ary+1,ary+n+1,comp);
  int l=1,r=n,cur=1,mid,flag;
  while (l<r){
    ll lsum,rsum,flag=1;
    while (flag){
      if (l<=ary[cur].pos and ary[cur].pos<=r){
        flag=0;
        break;
      }else{
        cur++;
      }
    }
    mid=ary[cur].pos;
    lsum=psum[mid-1]-psum[l-1];
    rsum=psum[r]-psum[mid];
    if (lsum<=rsum){
      l=mid+1;
    }else{
      r=mid-1;
    }
    // cout<<l<<" "<<r<<" "<<mid<<"\n";
  }
  cout<<psum[r]-psum[r-1];
  return 0;
}
