//Uva 10854 Number of Paths
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
struct node{
	long long int l,r,from;
};
node st[10000000];
int from[10000000];
string commands[10000000];
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n;
	string s;
	cin>>n;
	for (int i=1;i<=n;i++){
		int cnt=0,top=0,from=0;
		long long int value;
		while (cin>>s){
			if (s=="ENDPROGRAM") break;
			else if (s!="S"){
				cnt++;
				commands[cnt]=s;
			}
		}
		st[top].l=1;
		for (int j=1;j<=cnt;j++){
			if (commands[j]=="IF"){
				top++;
				st[top].l=1;
				st[top].from=0;
			}else if (commands[j]=="ELSE"){
				st[top].r=1;
				st[top].from=1;
			}else{
				value=st[top].l+st[top].r;
				top--;
				if (!st[top].from) st[top].l*=value;
				else st[top].r*=value;
			}
		}
		cout<<st[top].l<<"\n";
	}
	return 0;
}
