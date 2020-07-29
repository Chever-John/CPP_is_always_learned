#include <iostream> 
#include <iomanip>
using namespace std;
int main() {
    cout.setf(ios::fixed); 
    cout<<setprecision(2)<<(float)0.1<<endl;//输出0.10

    cout.unsetf(ios::fixed);
    cout<<setprecision(2)<<(float)0.1<<endl; //输出0.1
} 