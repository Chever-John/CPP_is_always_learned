#include <iostream>
int main(){
    using namespace std;
    int updates = 6;
    int * p_updates;
    p_updates = &updates;

    //表达值的两种方法
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    //表达地址的两种方法
    cout << "Address: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    //使用指针来改变值
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    return 0;
}