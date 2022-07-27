//Uva Not So Mobile
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool flag;
int paths(){
	int w1,w2,d1,d2,temp,temp1;
	cin>>w1>>d1>>w2>>d2;
	if (!w1) w1=paths();
	if (!w2) w2=paths();
	temp=w1*d1;
	temp1=w2*d2;
	if (temp!=temp1) flag=false;
	return w1+w2;
}
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		flag=true;
		paths();
		if (flag) cout<<"YES\n";
		else cout<<"NO\n";
		if (i!=n) cout<<"\n";
	}
	return 0;
}
