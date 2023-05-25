#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#define SIZE 400005
#define ll long long int
#define pp pair<int,int>
#define pb push_back
using namespace std;
ll ary[SIZE];
ll alpha[SIZE];
ll final[SIZE];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt=0,temp;
  string s,t;
  cin>>s>>t;
  
  for (int i=0;i<s.size();i++){
    alpha[s[i]]++;
    if (s[i]=='?') cnt++;
  }
  for (int i=0;i<t.size();i++){
    ary[t[i]]++;
  }
  int l=0,r=1000005,ans=-1,mid;
  ll sum=0;
  while (l<=r){
    mid=(l+r)/2;
    sum=cnt;
    for (char i='a';i<='z';i++){
      final[i]=(ary[i]*mid)-alpha[i];
      if (final[i]>0) sum-=final[i];
      else final[i]=0;
    }
    // cout<<mid<<": "<<s.size()<<" "<<sum<<" "<<total<<"\n";
    if (sum>=0){
      ans=mid;
      l=mid+1;
    }else r=mid-1;
  }
  
  for (char i='a';i<='z';i++){
    if (ary[i]*ans>alpha[i]) final[i]=ary[i]*ans-alpha[i];
    else final[i]=0;
  }


  int flag=1;
  for (int i=0;i<s.size();i++){
    if (s[i]=='?'){
      flag=1;
      for (char j='a';j<='z';j++){
        if (final[j]>0){
          final[j]--;
          cout<<j;
          flag=0;
          break;
        }
      }
      
      if (flag){
        cout<<'a';
      }
    }else{
      cout<<s[i];
    }
  }
  return 0;
}
