//TOJ 584
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int ary[10000];
const int v=20010;
int dp[1005][v<<1];
const int e=1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    const int num=20000;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>ary[i];
    }
    int res=n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            dp[i][ary[i]-ary[j]+num]=(dp[i][ary[i]-ary[j]+num]+dp[j][ary[i]-ary[j]+num]+1)%e;
            res=(res+dp[j][ary[i]-ary[j]+num]+1)%e;
        }
    }
    cout<<res<<"\n";
    return 0;
}
