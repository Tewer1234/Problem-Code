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
int diff(int temp,int mid){
  int dif;
  dif=mid-temp;
  return dif;
}
int addin(int temp,int dif,int tb){
  temp+=min(dif,tb);
  tb-=min(dif,tb);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t,a,b,c,ta,tb,tc;
  cin>>t;
  while (t--){
    cin>>a>>b>>c;
    
    int l,r,mid,ans=-1;
    l=(a+b+c)/3,r=1000;
    if ((a+b+c)%3) l++;
    
    while (l<=r){
      mid=((l+r)>>1);
      ta=a,tb=b,tc=c;
      if (tc>ta) swap(ta,tc);
      
      int difa,difc,add=0;
      difa=diff(ta,mid);
      difc=diff(tc,mid);
      if (difa<0 and difc<0) l=mid+1;
      else{
        if (difa<0){
          add-=difa;
          ta+=difa;
          tc+=min(tb,difc);
          tb=tb-min(tb,difc)+add;
        }else if (difc<0){
          add-=difc;
          tc+=difc;
          ta+=min(tb,difa);
          tb=tb-min(tb,difa)+add;
        }else{
          ta+=min(difa,tb);
          tb-=(difa,tb);
          tc+=min(difc,tb);
          tb-=min(difc,tb);
        }
        
        // cout<<mid<<": "<<ta<<' '<<tb<<" "<<tc<<"\n";
        
        if (!(ta==mid or tb==mid or tc==mid)) r=mid-1;
        else if (!(ta<=mid and tb<=mid and tc<=mid)) l=mid+1;
        else{
          ans=mid;
          r=mid-1;
        }
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
