#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#include <vector>
#define ll long long int
#define pb push_back
#define SIZE 400005
#define pp pair<ll,ll>
using namespace std;
pp ary[SIZE];
int main() {
  int n;
  char c;
  cin>>n;
  while (n--){
    cin>>c>>ary[c].first>>ary[c].second;
  }
  
  string s;
  while (cin>>s){
    stack <pp> st;
    int flag=1;
    ll ans=0;
    if (s.size()==1) cout<<"0\n";
    else{
      for (int i=0;i<s.size();i++){
        if (s[i]==')'){
          pp bottom=st.top();
          st.pop();
          pp top=st.top();
          st.pop();
          if (top.second!=bottom.first){
            flag=0;
            break;
          }else{
            ans+=(top.first*top.second*bottom.second);
            st.push(make_pair(top.first,bottom.second));
          }
        }else if (s[i]>='A' and s[i]<='Z'){
          st.push(ary[s[i]]);
        }
      }
      
      if (!flag) cout<<"error\n";
      else cout<<ans<<'\n';
    }
  }
  return 0;
}
