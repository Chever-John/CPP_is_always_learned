#include <iostream>
#include <cstring>
#define MAXOFN 307
#define IsDigit(x) (x >= '0' && x <= '9')
using namespace std;
char str[MAXOFN];
int len, sum, cun[MAXOFN], res[MAXOFN];

int gcd(int a, int b){
	return (b == 0) ? a : gcd(b, a % b); 
}

//连分数-数
void Work1(){
	int sup, a, b, pos = 0, t = 1;
	//提取数字并存储在数组里
	while (t < len){
		sum = 0;
		while (IsDigit(str[t]) and t < len)
			sum = sum * 10 + str[t++] - '0';
		cun[pos++] = sum;
		++t;
	}
	a = 1, b = cun[pos - 1];
	for (int i = pos - 2; i >= 0; --i)
		a += cun[i] * b, swap(a, b);
	//特例
	if (a == 1) cout << b << endl;
	else cout << b << "/" << a << endl;
}

//数-连分数
void Work2(){
	int a, b, t = 0, tmp, GCD;
	//同上
	while (t < len){
		sum = 0;
		while (IsDigit(str[t]) and t < len)
			sum = sum * 10 + str[t++] - '0';
		if (str[t] == '/') a = sum;
		++t;
	}
	b = sum, t = 0;
	//约分
	GCD = gcd(a, b), a /= GCD, b /= GCD;
	//特例
	if (b == 1) cout << "[" << a / b << "]\n";
	else{
		while (b != 1){
			tmp = a / b;
			res[t++] = tmp, a -= tmp * b;
			swap(a, b);
		}
		res[t++] = a;
		cout << "[" << res[0] << ";";
		for (int i = 1; i < t - 1; ++i)
			cout << res[i] << ",";
		cout << res[t - 1] << "]" << endl;
	}
}

int main(){
	while (cin >> str){
		len = strlen(str);
		if (str[len - 1] == ']') Work1();
		else Work2();
	}
	return 0;
}

