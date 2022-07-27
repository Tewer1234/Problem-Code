//AtCoder F - LCS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int dp[3001][3001];
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	string s,t,lcs="";
	int ans,ex,ey,temp=0;
	cin>>s>>t;
	s=" "+s;
	t=" "+t;
	for (int i=1;i<s.size();i++){
		for (int j=1;j<t.size();j++){
			if (s[i]!=t[j]){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}else{
				dp[i][j]=dp[i-1][j-1]+1;
			}
		}
	}
	ex=s.size()-1;
	ey=t.size()-1;
	ans=dp[ex][ey];
	while (temp!=ans){
	  if (s[ex]==t[ey]){
	    temp++;
	    lcs+=s[ex];
	    ex--;
	    ey--;
	  }else{
	    if (dp[ex-1][ey]>=dp[ex][ey-1]){
	      ex--;
	    }else{
	      ey--;
	    }
	  }
	}
	reverse(lcs.begin(),lcs.end());
	cout<<lcs;
	return 0;
}
Collapse




