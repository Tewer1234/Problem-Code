//Uva 10534 - Wavio Sequence 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;	
int ary[1000000],it[1000000],dt[1000000],maxI[1000000],maxD[1000000];
int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    int n;
    while (cin>>n){
    	memset(it,0x7f,sizeof(it));
    	memset(dt,0x7f,sizeof(dt));
    	it[0]=INT_MIN;
    	dt[0]=INT_MIN;
    	for (int i=1;i<=n;i++){
    		cin>>ary[i];
		}
		int l,r,mid,temp,len=0;
		for (int i=1;i<=n;i++){
			l=0,r=n;
			while (l<=r){
				mid=(l+r)/2;
				if (ary[i]>it[mid]){
					temp=mid+1;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			it[temp]=ary[i];
			maxI[i]=temp;
		}
		for (int i=n;i>=1;i--){
			l=0,r=n;
			while (l<=r){
				mid=(l+r)/2;
				if (ary[i]>dt[mid]){
					temp=mid+1;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			dt[temp]=ary[i];
			maxD[i]=temp;
		}
		for (int i=1;i<=n;i++){
			len=max(len,min(maxI[i],maxD[i])*2-1);
		}
		cout<<len<<"\n";
	}
    return 0;
}
​
