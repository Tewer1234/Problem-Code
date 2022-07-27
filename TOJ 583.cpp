//TOJ 583
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long int 
using namespace std;
ll ary[1000000],psum[1000000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    map <ll,int> mp;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>ary[i];
        auto it=mp.find(ary[i]);
        if (it==mp.end()){
            mp[ary[i]]=0;
        }
    }
    sort(ary+1,ary+n+1);
    for (int i=1;i<=n;i++){
        psum[i]=psum[i-1]+ary[i];
    }
    int l,r,mid,tempans,cnt=0;
    ll temp,dif1,dif2,steps,num;
    for (int i=1;i<=n;i++){
        tempans=1;
        temp=ary[i]*(i-1);
        l=1,r=i;
        while (l<=r){
            mid=(l+r)/2;
            dif1=ary[i]*(mid-1);
            dif2=psum[i-1]-psum[mid-1];
            steps=abs(temp-dif1-dif2);
            // cout<<mid<<" "<<ary[i]<<": "<<temp<<" - "<<dif1<<" - "<<dif2<<" = "<<steps<<"\n";
            if (steps<=k){
                tempans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        mp[ary[i]]=max(mp[ary[i]],i-tempans+1);
    }
    
    for (auto it:mp){
        // cout<<it.first<<" "<<it.second<<"\n";
        if (cnt<it.second){
            num=it.first;
            cnt=it.second;
        }else if (cnt==it.second){
            if (num>it.first){
                num=it.first;
            }
        }
    }
    cout<<num<<" "<<cnt<<"\n";
    return 0;
}
