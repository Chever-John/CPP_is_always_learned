#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a[4] = {88, 2, 333234, 4};

    vector<int> b(a, a + 4);
    
    for(auto i: b){
        cout << i << " ";
    }

    cout << "\n";
    return 0;
}