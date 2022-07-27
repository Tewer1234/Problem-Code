//Uva 103 - Stacking Boxes
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n,k,ary[1000][1000],ans[1000][1000],temp[1000000],dp[1000][1000],amount[100000],final[1000000];
int main(){
  while (cin>>k>>n){
    memset(dp,0,sizeof(dp));
    memset(amount,0,sizeof(amount));
    for (int i=1;i<=k;i++){
      dp[i][1]=1;
      ans[i][1]=i;
    }
    for (int i=1;i<=k;i++){
      for (int j=1;j<=n;j++){
        cin>>temp[j];
      }
      sort(temp+1,temp+n+1);
      for (int j=1;j<=n;j++){
        ary[i][j]=temp[j];
      }
    }
    // for (int i=1;i<=k;i++){
    //   for (int j=1;j<=n;j++){
    //     cout<<ary[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    int cnt,flag;
    cnt=0;
    for (int i=2;i<=k;i++){
      for (int j=1;j<=k;j++){
        for (int l=1;l<=k;l++){
          if (j!=l and dp[l][i-1]){
            flag=1;
            for (int p=1;p<=n;p++){
              if (ary[j][p]<=ary[l][p]){
                flag=0;
                break;
              }
            }
            if (flag and !dp[j][i]){
              amount[j]++;
              dp[j][i]=1;
              ans[j][i]=l;
            }
          }
        }
      }
    }
    int maximum=0,last=0;
    for (int i=1;i<=k;i++){
      if (maximum<amount[i]+1){
        maximum=amount[i]+1;
        last=i;
      }
    }
    // cout<<last<<"\n";
    // for (int i=1;i<=k;i++){
      // cout<<amount[i]<<" \n";
    //   for (int j=1;j<=amount[i]+1;j++){
    //     cout<<ans[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    cnt=maximum;
    cout<<maximum<<"\n";
    for (int i=maximum;i>=1;i--){
      final[cnt]=last;
      cnt--;
      last=ans[last][i];
    }
    for (int i=1;i<=maximum;i++){
      cout<<final[i];
      if (i!=maximum) cout<<" ";
    }
    cout<<"\n";
  }
	return 0;
}
Collapse




