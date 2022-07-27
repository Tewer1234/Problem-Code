//Uva 10401 Injured Queen Problem
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[1000][1000],dp[1000][1000];
int moves[100][100]={{1,0},{0,-1},{0,1}};
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int r,c;
	cin>>r>>c;
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++){
			cin>>ary[i][j];
		}
	}
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++){
			int temp,first=1;
			for (int k=0;k<3;k++){
				int tempx,tempy;
				tempx=i+moves[k][0];
				tempy=j+moves[k][1];
				if ((tempx>=1 and tempx<=r) and (tempy>=1 and tempy<=c)){
					dp[tempx][tempy]=max(dp[tempx][tempy],dp[i][j]+ary[i][j]);
				}
			}
		}
	}
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
