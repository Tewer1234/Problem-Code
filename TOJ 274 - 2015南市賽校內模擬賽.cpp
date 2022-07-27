#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
string input;
bool is_palindrome(int start,int end,int error){
	if (error>1) return false;
	else{
		if (start>=end){
			if (error<=1) return true;
			else return false;
		}
		if (input[start]!=input[end]){
			return is_palindrome(start+1,end,error+1) or is_palindrome(start,end-1,error+1);
		}else{
			return is_palindrome(start+1,end-1,error);
		}
	}
}
int main(){
	int cases;
	cin>>cases;
	for (int i=1;i<=cases;i++){
		cin>>input;
		if (is_palindrome(0,input.size()-1,0)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}
