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
using namespace std;

int main() {
  int n,t,shift;
  string key,s;
  cin>>t;
  while (t--){
    cin>>key>>shift>>n;
    set <char> st;
    getline(cin,s);
    for (int i=0;i<key.size();i++){
      st.insert(key[i]);
    }
    for (int i=1;i<=n;i++){
      int m=0;
      getline(cin,s);
      
      int flag=1;
      string dec="";
      for (int j=0;j<s.size();j++){
        int cur;
        // cout<<j<<"\n";
        if (j+2<s.size() and s[j+2]!=' ' and key[m]==s[j] and key[(m+1)%key.size()]==s[j+2]){
          cur=s[j+1]-'A';
          cur=(cur-shift+26)%26;
          dec+=(cur+'A');
          // cout<<i<<": "<<dec;
          m=(m+1)%key.size();
          j+=2;
        }else{
          if (s[j]==' ') dec+=' ';
          else{
            cur=s[j]-'A';
            cur=(cur-shift+26)%26;
            char c=(cur+'A');
            auto it=st.find(c);
            if (it!=st.end()){
              flag=0;
              break;
            }else dec+=c;
          }
        }
        // cout<<i<<": "<<j<<" "<<m<<" "<<dec<<"\n";
      }
      
      // cout<<dec<<"\n";
      
      if (flag) cout<<dec<<"\n";
      else cout<<"error in encryption\n";
    }
    if (t!=0) cout<<"\n";
  }
  return 0;
}
