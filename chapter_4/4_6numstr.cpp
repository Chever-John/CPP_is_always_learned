#include <iostream>
int main(){
    using namespace std;
    cout << " What year was your house built?\n";
    int year;
    cin >> year;
    cin.get();//这边使用了没有参数的get()和使用接受一个char参数的get(),实现了在读取“Address”之前先读取并丢弃换行符。
    cout << " What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    return 0;
}