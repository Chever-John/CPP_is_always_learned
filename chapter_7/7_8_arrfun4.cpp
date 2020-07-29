#include <iostream>
const int ArSize = 8;
int sums(const int * begin, const int * end);
int main(){
    using namespace std;
    int things[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    int sum = sums(things, things + ArSize);
    cout << "Total things eaten: " << sum << endl;
    sum = sums(things, things + 3);
    cout << "First three people buy " << sum << " things.\n";
    sum = sums(things + 4, things + 8);
    cout << "Last four people buy " << sum << " things.\n";
    return 0;
}

int sums(const int * begin, const int * end){
    const int * pt;
    int total = 0;

    for(pt = begin; pt != end; pt++)
        total += *pt;
    
    return total;
}