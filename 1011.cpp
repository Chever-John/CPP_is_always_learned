#include<iostream>
using namespace std;

bool hhh(long a,long b,long c){
    if (a + b > c) return true;
    else false;
    
}
int main(){
    int exam, a, b, c;
    cin >> exam;
    bool aa[exam];
    while (exam--){
        cin >> a;
        cin >> b;
        cin >> c;
        aa[exam] = hhh(a,b,c);
    }
    for (int i = exam; i > 0; i--)
    {
        cout << aa[i] << endl;
    }
    
    return 0;
}
