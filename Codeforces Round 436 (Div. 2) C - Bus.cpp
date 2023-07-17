#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#define SIZE 400005
#define ll long long int
#define pp pair<ll,int>
#define pb push_back
#define DiscordModerator 998244353
using namespace std;
int ary[SIZE];
int ans,l,flag;
bool check(int dif1,int dif2,int a,int b,int k,int cur){
  
  // cout<<"BEFORE: "<<l<<" "<<ans<<"\n";
  
  if (l>=a){
    int tempa=a;
    if (cur!=k) tempa+=dif2;
    
    if (tempa<=l) l-=a;
    else{
      ans++;
      l=b-dif2;
    }
  }else{
    if (l<dif1){
      flag=0;
    }else{
      l=b-dif2;
      ans++;
    }
  }
  
  // cout<<"AFTER: "<<l<<" "<<ans<<"\n";
  
  if (flag) return true;
  else return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n,a,b,f,k;
  cin>>a>>b>>f>>k;
  
  int dif1,dif2;
  l=b;
  ans=0,flag=1;
  dif1=f;
  dif2=a-f;
  if (b<dif1 or b<dif2) cout<<-1;
  else{
    for (int i=1;i<=k;i++){
      if (i%2){
        if (!check(dif1,dif2,a,b,k,i)) break;
      }else{
        if (!check(dif2,dif1,a,b,k,i)) break;
      }
    }
    
    if (flag) cout<<ans;
    else cout<<-1;
  }
  return 0;
}
