#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

stack<string> num;
int main(int argc, char**argv){
    num.push("The first stack");
    num.push("The second stack");
    num.push("The third stack");
    num.push("The forth stack");
    num.push("The fifth stack");

    cout << num.top() << endl;
    return 0;
}