#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
struct node{
	int num[1000],shape[1000];
};
node hand,deck,zero;
string h[1000],d[1000],order="23456789TJQKA",order1="CDHS",tbl[100]={"","straight-flush","four-of-a-kind","full-house","flush","straight","three-of-a-kind","two-pairs","one-pair","highest-card"};
int find_dif(string s,int a[]){
	int dif=0;
	for (int i=0;i<s.size();i++){
		if (a[s[i]]>=1) dif++;
	}
	return dif;
}
//four of a kind
int four_of_a_kind(node a,node b){
	int dif=find_dif(order,b.num);
	if (dif>2) return 0;
	for (int i=0;i<order.size();i++){
		if (a.num[order[i]]+b.num[order[i]]==4){
			return 2;
		}
	}
	return 0;
}
//full house, three of a kind, two pairs, and one pair
int full_house(int n,int n1,int find,node a,node b){
	int dif=find_dif(order,b.num);
	for (int i=0;i<order.size();i++){
		if (a.num[order[i]]+b.num[order[i]]==n){
			for (int j=0;j<order.size();j++){
				if (i!=j and a.num[order[j]]+b.num[order[j]]==n1){
					if (find==3 and dif<3) return 3; 
					else if (find==7 and dif<=3) return 7;
				}
			}
			if (find==3 and dif<=3) return 6;
			else if (find==7 and dif<=4) return 8;
		}
	}
	return 0;
}
//flush
int flush(node a,node b){
	int dif=find_dif(order1,b.shape);
	if (dif>=2) return 0;
	for (int i=0;i<order1.size();i++){
		if (a.shape[order1[i]]+b.shape[order1[i]]==5){
			return 4;
		}
	}
	return 0;
}
//straight
int get_straight(node a,node b,int pos,int temp,int t){
	int picked[1000]={0},left=5,flag=1,temp1=pos;
	left-=temp;
	for (int i=1;i<=temp;i++){
		picked[d[i][0]]=1;
	}
	while (left>=1){
//		cout<<order[temp1]<<"\n";
		if (a.num[order[temp1]]>=1 and picked[order[temp1]]==0){
			picked[order[temp1]]=1;
			left--;
		}else if (a.num[order[temp1]]==0 and picked[order[temp1]]==0){
			flag=0;
			break;
		}
		if (t==1) temp1=(temp1+1)%13;
		else temp1=(temp1+12)%13;
	}
//	cout<<temp<<"\n";
//	for (int i=0;i<order.size();i++) cout<<picked[order[i]];
	temp1=pos;
	for (int i=1;i<=5;i++){
		if (picked[order[temp1]]==0){
			flag=0;
			break;
		}
		if (t==1) temp1=(temp1+1)%13;
		else temp1=(temp1+12)%13;
	}
//	cout<<"\n";
	if (flag==1) return 5;
	return 0;
}
int straight(node a,node b,int temp){
	int dif=find_dif(order,b.num),pos,res=0,t;
	if (dif!=temp) return 0;
	for (int i=0;i<order.size();i++){
		if (b.num[order[i]]>=1) pos=i;
	}
	if (temp>=1){
		if (pos<=8 or order[pos]=='A') res=get_straight(a,b,pos,temp,1),t=1;
		else if (pos>=3 or order[pos]=='A') res=get_straight(a,b,pos,temp,2),t=2;
		if (res==0){
			if (t==1 and pos>=3) res=get_straight(a,b,pos,temp,2);
			else if (t==2 and pos<=8) res=get_straight(a,b,pos,temp,1);
		}
	}
	return res;
}
int solve(int temp){
	int r1,r2,r3,r4,r5;
	if (temp!=5) r1=flush(hand,deck),r2=straight(hand,deck,temp),r3=four_of_a_kind(hand,deck),r4=full_house(3,2,3,hand,deck),r5=full_house(2,2,7,hand,deck);
	else r1=flush(zero,deck),r2=straight(zero,deck,temp),r3=four_of_a_kind(zero,deck),r4=full_house(3,2,3,zero,deck),r5=full_house(2,2,7,zero,deck);
	if (r1 and r2) return 1;
	else if (r3==2) return 2;
	else if (r4==3) return 3;
	else if (r1==4) return 4;
	else if (r2==5) return 5;
	else if (r4==6) return 6;
	else if (r5==7) return 7;
	else if (r5==8) return 8;
	else return 9;
}
void print_out(string s,string a[]){
	cout<<s<<": ";
	for (int i=1;i<=5;i++){
		cout<<a[i];
		cout<<" ";
	}
}
int main(){
//  freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//  ios::sync_with_stdio(0);
//  cin.tie(0);
    while (cin>>h[1]){
    	memset(hand.num,0,sizeof(hand.num));
    	memset(deck.num,0,sizeof(deck.num));
    	memset(hand.shape,0,sizeof(hand.shape));
    	memset(deck.shape,0,sizeof(deck.shape));
    	hand.num[h[1][0]]++;
    	hand.shape[h[1][1]]++;
    	for (int i=2;i<=5;i++){
    		cin>>h[i];
    		hand.num[h[i][0]]++;
    		hand.shape[h[i][1]]++;
		}
		for (int i=1;i<=5;i++){
			cin>>d[i];
		}
		int ans=INT_MAX;
		for (int i=0;i<=5;i++){
			if (i!=0){
				deck.num[d[i][0]]++;
				deck.shape[d[i][1]]++;
			}
			int temp;
			temp=solve(i);
			ans=min(temp,ans);
		}
		print_out("Hand",h);
		print_out("Deck",d);
		cout<<"Best hand: "<<tbl[ans]<<"\n";
	}
    return 0;
}
