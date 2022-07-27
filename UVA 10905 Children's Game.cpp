//Uva 10905 Children's Game
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
string s[100000];
bool comp(string a,string b){
	return (a+b)>(b+a);
}
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n;
	while (cin>>n and n!=0){
		for (int i=1;i<=n;i++){
			cin>>s[i];
		}
		sort(s+1,s+n+1,comp);
		for (int i=1;i<=n;i++){
			cout<<s[i];
		}
		cout<<'\n';
	}
	return 0;
