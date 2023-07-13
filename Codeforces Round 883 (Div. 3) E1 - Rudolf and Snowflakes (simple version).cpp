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
int ary[SIZE];
int main() {
  int n,t;
  cin>>t;
  while (t--){
    cin>>n;
    
    ll sum,flag=0;
    for (int i=2;i*i<=n;i++){
      sum=i+1;
      if (sum<n){
        ll temp=i*i,r=(ll)1e6;
        // cout<<temp<<" "<<r<<"\n";
        while (temp<r){
          sum+=temp;
          if (sum==n){
            flag=1;
            break;
          }else if (sum>n) break;
          temp*=i;
        }
      }
      
      if (flag) break;
    }
    
    if (flag) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
