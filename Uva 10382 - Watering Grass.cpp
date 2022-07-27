//Uva 10382 - Watering Grass
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n,l,w;
const double EPS=1e-7;
struct node{
	int c,r;
	double st,ed;
};
node ary[1000000];
bool comp(node a,node b){
	double diff1;
	diff1=fabs(a.st-b.st);
	if (a.st<b.st) return true;
	else if (diff1<EPS){
		if (a.ed<b.ed) return true;
	}
	return false;
} 
bool check(double begin,double end){
	double diff1,diff2;
	diff1=fabs(begin-0);
	diff2=fabs(end-l);
	if (diff1<EPS and (end>l or diff2<EPS)){
		return true;
	}else{
		return false;
	}
}
int main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
	int center,radius,cnt;
	double temp;
	while (cin>>n>>l>>w){
		cnt=0;
		for (int i=1;i<=n;i++){
			cin>>center>>radius;
			if (radius*2>w){
				cnt++;
				ary[cnt].c=center;
				ary[cnt].r=radius;
				temp=sqrt((long long int)radius*radius-((double)w/2)*((double)w/2));
				if ((double)center-temp<0){
					ary[cnt].st=0;
				}else{
					ary[cnt].st=(double)center-temp;
				}
				ary[cnt].ed=(double)center+temp;
			}
		}
		if (!cnt) cout<<-1<<"\n";
		else{
			sort(ary+1,ary+cnt+1,comp);
//			for (int i=1;i<=cnt;i++){
//				cout<<ary[i].c<<" "<<ary[i].r<<" "<<ary[i].st<<" "<<ary[i].ed<<"\n";
//			}
			int ans=0,flag=1,found=0;
			double begin=0,end=0,diff1,tempEnd=-1;
			for (int i=1;i<=cnt+1;i++){
				if (check(begin,end) or check(begin,tempEnd)){
					end=tempEnd;
					ans++;
					break;
				}
				if (i!=cnt+1){
  				diff1=fabs(ary[i].st-end);
  				if ((ary[i].st<end or diff1<EPS)){
  					if (ary[i].ed>tempEnd) tempEnd=ary[i].ed;
  				}else{
  					diff1=fabs(ary[i].st-tempEnd);
  					if (ary[i].st<tempEnd or diff1<EPS){
  						ans++;
  						end=tempEnd;
  						tempEnd=ary[i].ed;
  					}else{
  						flag=0;
  						break;
  					}
  				}
				}else{
				  flag=0;
				}
			}
		// 	if (flag and !found){
		// 		end=tempEnd;
		// 		if (check(begin,end)){
		// 			ans++;
		// 		}else{
		// 			flag=0;
		// 		}
		// 	}
		// 	cout<<begin<<" "<<end<<"\n";
			if (!flag) cout<<-1<<"\n";
			else cout<<ans<<"\n";
		}
	}
	return 0;
}
