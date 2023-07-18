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
set <ll> st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (ll i=2;i<=1e6;i++){
    ll temp=i*i+i+1;
    ll add=i*i*i;
    for (ll j=3;j<63;j++){
      temp+=add;
      
      if (temp<=1e18) st.insert(temp);
      else break;
      
      if (add>(ll)1e18/i) break;
      add*=i;
    }
  }
  
  
  ll n,t;
  cin>>t;
  while (t--){
    cin>>n;
    
    int flag=0;
    auto it=st.find(n);
    if (it!=st.end()) cout<<"YES\n";
    else{
      ll temp=4*n-3;
      temp=(ll)sqrt(temp);
      if (temp*temp==4*n-3 and (!((temp-1)%2)) and ((temp-1)/2>1)) flag=1;
      
      if (flag) cout<<"YES\n";
      else cout<<"NO\n";
    }
  }
  return 0;
}
