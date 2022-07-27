//TOJ 508
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[1005][1005],dp[1005][1005];
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int r,c;
	string s;
	cin>>r>>c;
	for (int i=1;i<=r;i++){
		cin>>s;
		s=" "+s;
		for (int j=1;j<s.size();j++){
			ary[i][j]=(s[j]-'0');
		}
	}
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++){
			if (ary[i][j]==9){
				dp[i][j]=1;
			}		
		}
	}
	int ans=0;
	for (int i=9;i>=1;i--){
		for (int j=1;j<=r;j++){
			for (int k=1;k<=c;k++){
				if (ary[j][k]==i){
					int tempx,tempy;
					for (int l=0;l<4;l++){
						tempx=j+moves[l][0];
						tempy=k+moves[l][1];
						if ((tempx>=1 and tempx<=r) and (tempy>=1 and tempy<=c)){
							if (ary[j][k]-1==ary[tempx][tempy]){
								dp[tempx][tempy]+=dp[j][k];
							}
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++){
			if (!ary[i][j]){
				ans+=dp[i][j];
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
