//Uva 884 - Factorial Factors
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int pfactor[10000000];
ll dp[10000000];
int main() {
  for (int i=3;i*i<=1000000;i+=2){
    if (!pfactor[i]){
      for (int j=i*i;j<=1000000;j+=(i+i)){
        pfactor[j]=i;
      }
    }
  }
  for (int i=2;i<=1000000;i++){
    int t=i,p;
    while (t>1){
      p=pfactor[t];
      if (t%2==0){
        p=2;
      }else if (p==0){
        p=t;
      }
      while (t%p==0){
        dp[i]++;
        t/=p;
      }
    }
    dp[i]+=dp[i-1];
  }
  int n;
  while (cin>>n){
    cout<<dp[n]<<"\n";
  }
  return 0;
}  
