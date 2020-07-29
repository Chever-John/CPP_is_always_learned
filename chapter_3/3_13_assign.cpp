#include <iostream>
int main(){
    using namespace std;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    float tree = 3;
    int guess(3.9832);
    int debt = 7.2E12;
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess <<endl;
    cout << "debt = " << debt << endl;
    return 0;
}
/*
将浮点值3.0赋给了tree。将3.9832赋给int变量guess导致这个值被截取为3。
将浮点型转换为整型时，C++采取截取（丢弃小数部分）而不是四舍五入（查找最接近的整数）。
最后，int 变量debt无法存储3.0E12，这导致C++ 没有对接过进行定义的情况发生。在这种系统中，debt的结果出现了偏差，
我们可以看到在我这个系统中出现的是2147483647
*/