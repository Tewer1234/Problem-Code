//Uva 497 - Strategic Defense Initiative O(n^2) version
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[100000],dp[100000],ans[100000],final[100000];
int main(int argc, char** argv) {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,cnt,temp,maximum,last;
	string s;
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	while (n--){
		memset(ary,0,sizeof(ary));
		memset(dp,0,sizeof(dp));
		cnt=1;
		while (getline(cin,s)){
			if (s.size()==0) break;
			for (int i=0;i<s.size();i++){
				ary[cnt]=ary[cnt]*10+(s[i]-'0');
			}
			cnt++;
		}
		dp[1]=1;
		ans[1]=-1;
		for (int i=1;i<cnt;i++){
			dp[i]=1;
			ans[i]=-1;
			temp=1;
			for (int j=1;j<i;j++){
				if (ary[j]<ary[i]){
					dp[i]=max(dp[j]+1,dp[i]);
					if (temp<dp[i]){
						temp=dp[i];
						ans[i]=j;
					}
				}
			}
		}
		maximum=dp[1];
		last=1;
		for (int i=2;i<cnt;i++){
			if (maximum<dp[i]){
				maximum=dp[i];
				last=i;
			}
		}
		temp=maximum;
		cout<<"Max hits: "<<maximum<<"\n";
		while (ans[last]!=-1){
			final[temp]=ary[last];
			last=ans[last];
			temp--;
		}
		final[1]=ary[last];
		for (int i=1;i<=maximum;i++){
			cout<<final[i]<<"\n";
		}
	}
	return 0;
}
