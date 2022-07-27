//Q108: Maximum Sum
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
int grid[1000][1000];
int main() {
//      freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,ans,res,first=1;
	memset(grid,0,sizeof(grid));
	ans=INT_MIN;
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>grid[i][j];
		}
	}
	for (int col=1;col<=n;col++){
		for (int row=1;row<=n;row++){
			grid[row][col]+=grid[row-1][col];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			res=0;
			for (int k=1;k<=n;k++){
				res=res+grid[j][k]-grid[i-1][k];
				ans=max(ans,res);
				if (res<0) res=0; 
			}
		}
	}
	cout<<ans;
    return 0;                    
}
