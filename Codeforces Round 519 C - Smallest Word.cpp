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
#define pp pair<ll,int>
#define pb push_back
using namespace std;
int ans[SIZE];
int main() {
  int cnt=0,l=0,r=0;
  string s,temp="";
  cin>>s;
  
  for (int i=0;i<s.size()-1;i++){
    if (s[i]!=s[i+1]){
      ans[i]=1;
      temp+=s[i];
      reverse(temp.begin(),temp.end());
    }else temp+=s[i];
    // cout<<temp<<"\n";
  }
  if (s[s.size()-1]=='a'){
    ans[s.size()-1]=1;
    // temp+=s[s.size()-1];
    // reverse(temp.begin(),temp.end());
  }
  for (int i=0;i<s.size();i++) cout<<ans[i]<<" ";
  return 0;
}
