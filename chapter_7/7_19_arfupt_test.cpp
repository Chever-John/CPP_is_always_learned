#include <iostream>
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);
typedef const double *(*p_fun)(const double *, int);


int main(){
    using namespace std;

    double av[3] = {1112.3, 1542.6, 2227.9};

//第一种方法
    //一个指向函数的指针
    p_fun p1 = f1;
    p_fun p2 = f2;//这边用了C++11的auto自动推断，当然也可以用下面的代码代替
    //const double *(*p2)(const double *, int) = f2;

    cout << "Using pointers to functions:\n";
    cout << " Address Value\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
    //自己个人的理解啦（重要重要重要）：这边的(*p1)(av, 3) 和 p2(av, 3)其实都是调用函数而已
    //不要被吓着，然后这边调用的函数有两种，p1的函数是直接返回指针（原本指向第一个的，函数指针的指针都是先指向第一个的）
    //p2的函数就是返回指针+1的值，也就是我们这边第二个av[1] = 1542.6

//第二种方法
    p_fun pa[3] = {f1, f2, f3};//函数指针数组，包含三个指针的数组
    //定义pa是一个数组指针
    //这边再要注意的一点是，auto不适用于列表初始化，它只适用于初始化给一个单值
    auto pb = pa;
    //代替上面的代码：const double *(**pb)(const double *, int) = pa;
    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address Value\n";
    for (int i = 0; i < 3; i++){
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    }

//第三种方法：指向函数指针的数组指针
    cout <<  "\nUsing  a pointer to a pointer to a function:\n";
    cout << " Address Value\n";
    for (int i = 0; i < 3; i++){
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
    }

//第四种方法
    //What about a pointer to an array of function pointers
    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address Value\n";
    auto pc = &pa;//easy way to declare pc;can use the following code instead
    //const double *(*(*pc)[3])(const double *, int) = &pa;
//输出1112.3
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    //hard way to declare pd
    const double *(*(*pd)[3])(const double *, int) = &pa;
    //store return value in pdb
    const double * pdb = (*pd)[1](av, 3);
//输出1542.6
    cout << pdb << ": " << *pdb << endl;
//输出2227.9
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    return 0; 
    
}


const double * f1(const double * ar, int n){
    return ar;
}
const double * f2(const double ar[], int n){
    return ar+1;
}
const double * f3(const double ar[], int){
    return ar+2;
}