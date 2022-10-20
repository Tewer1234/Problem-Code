#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int ary[1000000];
int h[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k,tallest=0,ans=0;
  stack <int> st;
  cin>>n>>k;
  st.push(0);
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=n;i++) cin>>h[i];
  
  ary[n+1]=k;
  for (int i=1;i<=n;i++){
    int l=ary[i]-h[i],r=ary[i]+h[i];
    if (l>=ary[st.top()] or r<=ary[i+1]){
      // stack <int> temp;
      // temp=st;
      // cout<<i<<"\n";
      // while (!temp.empty()){
      //   cout<<temp.top()<<" ";
      //   temp.pop();
      // }
      
      // cout<<"\n";
      // cout<<l<<' '<<r<<" "<<h[st.top()]<<"\n";
      ans++;
      tallest=max(tallest,h[i]);
      while (st.size()>1 and ary[st.top()]+h[st.top()]<=ary[i+1]){
        ans++;
        tallest=max(tallest,h[st.top()]);
        // cout<<st.top();
        st.pop();
      }
    }else{
      st.push(i);
    }
  }
  cout<<ans<<"\n"<<tallest;
  return 0; 
}

