#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<string , string> test;
int main(){
    int n;
    //input how much the example;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    test earliest = test(b, a);
    test lastest = test(c, a);
    for (int i = 1; i < n; i++){
        string a, b, c;
        cin >> a >> b >> c;

        earliest = min(earliest, test(b, a));
        lastest = max(lastest, test(c, a));
    }

    cout << earliest.second << " " << lastest.second << endl;
    return 0;
}