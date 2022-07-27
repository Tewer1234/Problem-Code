//Uva 507 - Jill Rides Again
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ary[10000000];
int main() {
  int n,m,cases=1;
  cin>>n;
  while (n--){
    cin>>m;
    for (int i=1;i<m;i++){
      cin>>ary[i];
    }
    int l=-1,r=-1,sum=0,maxSum=0,st=-1;
    for (int i=1;i<m;i++){
      if (st==-1) st=i;
      sum+=ary[i];
      if (sum>maxSum or (sum==maxSum and r-l<i-st)){
        maxSum=sum;
        l=st;
        r=i;
      }
      if (sum<0){
        st=-1;
        sum=0;
      }
    }
    if (maxSum<=0) cout<<"Route "<<cases<<" has no nice parts\n";
    else cout<<"The nicest part of route "<<cases<<" is between stops "<<l<<" and "<<r+1<<"\n";
    cases++;
  }
  return 0;
}
