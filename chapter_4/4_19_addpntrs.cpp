#include<iostream>
int main(){
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    double * pw = wages;//多数情况下，C++将数组名解释为数组第一个元素的地址。本行语句将pw声明为指向double类型的指针，然后将它初始化为wages------wages数组中第1个元素的地址：
    short * ps = &stacks[0];//该程序在表达式&stacks[0]中显式地使用地址运算符来将ps指针初始化为stacks数组的第1个元素。

    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << endl;

    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";//通过第10行和第15行代码的比较
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";
    
    cout << "access two elements with array notation\n";
    cout << "stack[0] = " << stacks[0]
        << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stack = " << *stacks
        << ", *(stacks + 1) = " << *(stacks + 1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";
    return 0;
}