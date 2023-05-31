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
int ary[SIZE];
map <int,int> mp;
int main() {
  int n,k,l=1,r=1,temp;
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  if (k==1) cout<<1<<" "<<1;
  else{
    for (int i=1;i<=n;i++) mp[ary[i]]++;
    
    if (mp.size()<k){
      cout<<-1<<" "<<-1;
    }else{
      int num=0;
      for (int i=1;i<=n;i++){
        if (mp[ary[i]]){
          mp.erase(ary[i]);
          num++;
          if (num==k){
            r=i;
            break;
          }
        }
      }
      
      mp.clear();
      for (int i=1;i<=n;i++) mp[ary[i]]++;
      
      num=0;
      for (int i=r;i>=1;i--){
        if (mp[ary[i]]){
          mp.erase(ary[i]);
          num++;
          if (num==k){
            l=i;
            break;
          }
        }
      }
      
      cout<<l<<" "<<r;
    }
  }
  return 0;
}
