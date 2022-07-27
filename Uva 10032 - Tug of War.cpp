//Uva 10032 - Tug of War
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int num1,num2,dif;
int ary[1000000];
int dp[105][25000];
void num(int sum,int i){
    int temp=sum-i;
    if (dif>=abs(sum-i)){
        dif=abs(temp-i);
        num1=i;
        num2=temp;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int first=1,n,t,sum,tsum,temp,len,pos1,pos2;
    cin>>n;
    while (n--){
        cin>>t;
        sum=tsum=0;
        len=(t>>1);
        if (t&1) len++;
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=t;i++){
            cin>>ary[i];
            sum+=ary[i];
        }
        if (first) first=0;
        else cout<<"\n";
        dp[0][0]=1;
        for (int i=1;i<=t;i++){
            tsum+=ary[i];
            for (int j=min(tsum,(sum>>1));j>=ary[i];j--){
                for (int k=1;k<=min(i,len);k++){
                    dp[k][j]|=dp[k-1][j-ary[i]];
                }
            }
        }
        dif=INT_MAX;
        if (t&1){
            for (int i=sum>>1;i>=0;i--){
                pos1=t>>1,pos2=(t>>1)+1;
                if (dp[pos1][i] or dp[pos2][i]){
                    num(sum,i);
                    break;
                }
            }
        }else{
            for (int i=sum>>1;i>=0;i--){
                pos1=t>>1;
                if (dp[pos1][i]){
                    num(sum,i);
                    break;
                }
            }
        }
        if (num1>num2) swap(num1,num2);
        cout<<num1<<" "<<num2<<"\n";
    }
    return 0;
}
