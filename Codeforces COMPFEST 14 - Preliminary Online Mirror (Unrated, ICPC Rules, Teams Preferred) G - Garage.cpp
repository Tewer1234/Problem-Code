#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define ll long long int
#define SIZE 400005
#define pb push_back
#define inf 0x3f3f3f3f
#define dd 1e9+7
using namespace std;
typedef pair<int,int> pp;
int ary[SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  
  ll l,r,mid,ans=INT_MAX,pos=-1,quads;
  l=1,r=(ll)2e9+10;
  while (l<=r){
    mid=((l+r)>>1);
    quads=(2*mid+1)/4-1;
    pos=quads+mid;
    // cout<<n<<" "<<pos<<" "<<quads<<" "<<mid<<"\n";
    if (n>=pos) l=mid+1;
    else r=mid-1;
  }
  // cout<<l<<" ";
  if (n==1) cout<<3;
  else{
    quads=(2*l+1)/4-1;
    if (n==quads*3+1) cout<<2*l;
    else cout<<2*l-1;
  }
  return 0;
}
