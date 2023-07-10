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
using namespace std;
int ary[SIZE];
stack <int> st;
int main() {
  int n,num,cnt=1,ans=0;
  string s;
  cin>>n;
  n*=2;
  for (int i=1;i<=n;i++){
    cin>>s;
    if (s=="add"){
      cin>>num;
      st.push(num);
    }else{
      if (!st.empty()){
        if (cnt==st.top()){
          st.pop();
        }else{
          ans++;
          while (!st.empty()){
            st.pop();
          }
        }
      }
      cnt++;
    }
  }
  cout<<ans;
  return 0;
}
