//Uva 624 - CD
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[1000000],dp[1000000],ans[100000][21],cnt[100000],order[1000000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n,m,total;
    while (cin>>n>>m){
    	total=0;
    	memset(cnt,0,sizeof(cnt));
    	memset(dp,0,sizeof(dp));
    	for (int i=1;i<=m;i++){
    		cin>>ary[i];
    		total+=ary[i];
		}
		dp[0]=1;
		for (int i=1;i<=m;i++){
			for (int j=total;j>=ary[i];j--){
				if (dp[j-ary[i]]){
					cnt[j]++;
					ans[j][cnt[j]]=i;
					dp[j]=1;
				}
			}
		}
		for (int i=n;i>=0;i--){
			if (dp[i]){
				int temp=i,k=0;
				while (temp>0){
					k++;
					order[k]=ary[ans[temp][1]];
					temp-=ary[ans[temp][1]];
				}
				for (int j=k;j>=1;j--){
					cout<<order[j]<<" ";
				}
				cout<<"sum:"<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}
