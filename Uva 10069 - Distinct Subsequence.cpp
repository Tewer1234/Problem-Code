//Uva 10069 - Distinct Subsequence
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
string dp[101][10001];
void addString(int r,int c){
    int carry=0,temp,len=0;
    string num1=dp[r-1][c-1],num2=dp[r][c-1],final="";
    len=num1.size();
    if (len<num2.size()){
        len=num2.size();
        swap(num1,num2);
    }
    for (int i=num1.size()-1,j=num2.size()-1;i>=0 and j>=0;i--,j--){
        temp=(num1[i]-'0')+(num2[j]-'0')+carry;
        final+=(temp%10+'0');
        carry=temp/10;
    }
    len=len-num2.size()-1;
    while (len>=0){
        temp=(num1[len]-'0')+carry;
        final+=(temp%10+'0');
        carry=temp/10;
        len--;
    }
    if (carry){
      while (carry){
        final+=(carry%10+'0');
        carry/=10;
      }
    }
    reverse(final.begin(),final.end());
//     cout<<num1<<" + "<<num2<<" = "<<final<<"\n";
    dp[r][c]=final;
}
int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    int n;
    string s,t;
    cin>>n;
    for (int cases=1;cases<=n;cases++){
        cin>>s>>t;
        s=" "+s;
        t=" "+t;
        for (int i=0;i<s.size();i++){
            dp[0][i]="1";
        }
        for (int i=1;i<t.size();i++){
          dp[i][i-1]="0";
        }
        // for (int j=0;j<s.size();j++){
     //   cout<<dp[0][j];
     // }
        for (int i=1;i<t.size();i++){
            for (int j=i;j<s.size();j++){
                if (t[i]==s[j]){
                    addString(i,j);
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        // for (int i=0;i<t.size();i++){
        //   for (int j=0;j<s.size();j++){
        //     cout<<setw(10)<<dp[i][j];
        //   }
        //   cout<<"\n";
        // }
        string ans=dp[t.size()-1][s.size()-1];
        cout<<ans<<"\n";
    }
    return 0;
}
​
