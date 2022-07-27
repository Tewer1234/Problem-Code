
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
long long int dp[1000][1000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    string s,find=" welcome to code jam";
    cin>>n;
    getline(cin,s);
    for (int cases=1;cases<=n;cases++){
        memset(dp,0,sizeof(dp));
        getline(cin,s);
        s=" "+s;
        for (int i=0;i<s.size();i++){
            dp[i][0]=1;
        }
        for (int i=1;i<s.size();i++){
            for (int j=1;j<find.size();j++){
                if (s[i]==find[j]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10000;
                }else{
                    dp[i][j]=dp[i-1][j]%10000;
                }
            }
        }
        long long int ans=dp[s.size()-1][find.size()-1];
        cout<<"Case #"<<cases<<": ";
        cout<<setfill('0')<<setw(4)<<ans;
        if (cases!=n) cout<<"\n";
    }
    return 0;
} 
