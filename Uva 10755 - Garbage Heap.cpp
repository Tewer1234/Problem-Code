//Uva 10755 - Garbage Heap
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long int ary1[100][100][100];
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,A,B,C;
	cin>>n;
	for (int cases=1;cases<=n;cases++){
		memset(ary1,0,sizeof(ary1));
		long long int ans,first=1;
		cin>>A>>B>>C;
		for (int i=1;i<=A;i++){
			for (int j=1;j<=B;j++){
				for (int k=1;k<=C;k++){
					cin>>ary1[i][j][k];
					if (first){
						ans=ary1[i][j][k];
						first=0;
					}else{
						if (ary1[i][j][k]>ans) ans=ary1[i][j][k];
					}
				}
			}
		}
		for (int i=1;i<=A;i++){
			for (int j=1;j<=B;j++){
				for (int k=1;k<=C;k++){
					ary1[i][j][k]+=ary1[i][j-1][k];
				}
			}
		}
		for (int i=1;i<=A;i++){
			for (int j=1;j<=B;j++){
				for (int k=1;k<=C;k++){
					ary1[i][j][k]+=ary1[i-1][j][k];
				}
			}
		}
		for (int i=1;i<=A;i++){
			for (int j=i;j<=A;j++){
				for (int k=1;k<=B;k++){
					for (int l=k;l<=B;l++){
						long long int temp=0;
						for (int p=1;p<=C;p++){
							temp=temp+((ary1[j][l][p]-ary1[i-1][l][p])-(ary1[j][k-1][p]-ary1[i-1][k-1][p]));
//							cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<p<<": "<<temp<<"\n";
//							cout<<ans<<"\n";
							ans=max(ans,temp);
							if (temp<0) temp=0;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
		if (cases!=n) cout<<"\n";
	}
	return 0;
}
