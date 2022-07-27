//Uva 607 - Scheduling Lectures
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int t[10000],presum[10000];
int dp[200000],di[200000];
int main() {
  int n,l,c,cases=1,first=1,dif;
  while (cin>>n and n){
    int temp=0,cnt=1,res;
    memset(dp,0x3f,sizeof(dp));
    memset(di,0x3f,sizeof(di));
    memset(presum,0,sizeof(presum));
    cin>>l>>c;
    for (int i=1;i<=n;i++){
      cin>>t[i];
      presum[i]=presum[i-1]+t[i];
    }
    if (first) first=0;
    else cout<<"\n";
    dp[0]=0,di[0]=0;
    for (int i=1;i<=n;i++){
      for (int j=1;j<=i;j++){
        temp=presum[i]-presum[i-j];
        if (temp>l) break;
        if (l-temp==0) dif=0;
        else if (1<=l-temp and l-temp<=10) dif=-c;
        else dif=(l-temp-10)*(l-temp-10);
        if (dp[i-j]+1<dp[i] or (dp[i-j]+1==dp[i] and di[i-j]+dif<di[i])){
          dp[i]=dp[i-j]+1;
          di[i]=di[i-j]+dif;
        }
      }
    }
    cout<<"Case "<<cases<<":\n";
    cout<<"Minimum number of lectures: "<<dp[n]<<"\n";
    cout<<"Total dissatisfaction index: "<<di[n]<<"\n";
    cases++;
    // for (int i=1;i<=n;i++){
    //   for (int j=1;j<=n;j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    
  }
  return 0;
}
