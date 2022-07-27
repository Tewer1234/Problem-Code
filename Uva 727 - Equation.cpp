//Uva 727 - Equation
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#define ll long long int 
using namespace std;
char post[1000000];
char ary[1000000];
int main() {
  int n,cnt=0,pos=0,first=1;
  string s;
  cin>>n;
  getline(cin,s);
  getline(cin,s);
  while (n--){
    cnt=pos=0;
    stack <char> st;
    while (getline(cin,s)){
      if (!s.size()) break;
      char c=s[0];
      cnt++;
      ary[cnt]=c;
    }
    if (first) first=0;
    else cout<<"\n";
    for (int i=1;i<=cnt;i++){
      if (ary[i]>='0' and ary[i]<='9'){
        pos++;
        post[pos]=ary[i];
      }else if (ary[i]=='('){
        st.push(ary[i]);
      }else{
        while (st.size() and st.top()!='('){
          if ((ary[i]=='*' or ary[i]=='/') and (st.top()=='+' or st.top()=='-')) break;
          pos++;
          post[pos]=st.top();
          st.pop();
        }
        if (ary[i]==')' and st.size() and st.top()=='(') st.pop();
        if (ary[i]!=')') st.push(ary[i]);
      }
    }
    while (st.size()){
      pos++;
      post[pos]=st.top();
      st.pop();
    }
    for (int i=1;i<=pos;i++){
      cout<<post[i];
    }
    cout<<"\n";
  }
  return 0;
}
