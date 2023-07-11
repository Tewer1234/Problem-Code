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
stack <int> st;
int main() {
  int n;
  string s;
  cin>>n;
  cin>>s;
  
  for (int i=0;i<s.size();i++){
    if (s[i]=='('){
      if (!st.empty()){
        ary[i]=(!st.top());
        st.push((!st.top()));
      }else{
        ary[i]=0;
        st.push(0);
      }
    }else{
      if (!st.empty()){
        ary[i]=st.top();
        st.pop();
      }
    }
  }
  
  for (int i=0;i<s.size();i++) cout<<ary[i];
  
  return 0;
}
