#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int m, int n){
	if(m > n)return gcd(n, m);//��֤m < n 
	else return (n % m == 0) ? m : gcd(n % m, m); 
} 

int main(){
	printf("%d\n", gcd(6, 9));
	printf("%d\n", gcd(9, 6));
	return 0;
}