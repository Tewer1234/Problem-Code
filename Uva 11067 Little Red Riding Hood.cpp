//Uva 11067
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int wolf[1000][1000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int r,c,n,wx,wy;
	while (cin>>c>>r){
		memset(dp,0,sizeof(dp));
		memset(wolf,0,sizeof(wolf));
		dp[0][0]=1;
		if (r==0 and c==0){
			break;
		}
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>wx>>wy;
			wolf[wx][wy]=1;
		}
		for (int i=0;i<=r;i++){
			for (int j=0;j<=c;j++){
				if (!wolf[i][j]){
					if (j-1>=0){
						dp[i][j]+=dp[i][j-1];
					}
					if (i-1>=0){
						dp[i][j]+=dp[i-1][j];
					}
				}
			}
		}
		if (!dp[r][c]){
			cout<<"There is no path.\n";
		}else{
			if (dp[r][c]>1){
				cout<<"There are "<<dp[r][c]<<" paths from Little Red Riding Hood¡Šs house to her grandmother¡Šs house.\n";
			}else{
				cout<<"There is one path from Little Red Riding Hood¡Šs house to her grandmother¡Šs house.\n";
			}
		}
	}
	return 0;
}

