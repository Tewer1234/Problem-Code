#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#define ll long long int 
#define pb push_back
using namespace std;
typedef pair<int,int> pp;
vector <int> ary[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s,q;
  cin>>s>>n;
  for (int i=0;i<s.size();i++){
    ary[s[i]].pb(i);
  }
  int l,r,mid,temp,flag,first,ansl,ansr;
  while (n--){
    cin>>q;
    l=0,r=s.size()-1,flag=1,first=1,ansl=ansr=0;
    for (int i=0;i<q.size();i++){
      int left,right,k,len=ary[q[i]].size();
      left=0,right=len-1,temp=-1;
      while (left<=right){
        mid=(left+right)/2;
        k=ary[q[i]][mid];
        if (k>=l and k<=r){
          temp=mid;
          right=mid-1;
        }else{
          left=mid+1;
        }
      }
      // cout<<temp<<"\n";
      // cout<<"LEFT: "<<l<<" RIGHT: "<<r<<"\n";
      if (temp<0){
        flag=0;
        break;
      }else{
        l=ary[q[i]][temp]+1;
        if (first) first=0,ansl=ary[q[i]][temp],ansr=ary[q[i]][temp];
        else ansr=ary[q[i]][temp];
      }
    }
    if (!flag) cout<<"Not matched\n";
    else cout<<"Matched "<<ansl<<" "<<ansr<<"\n";
  }
  return 0;
}

