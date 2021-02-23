#include <iostream>
#include <algorithm>

const int NUM = 7;

int main(){
    using std::cin;
    using std::cout;

    int arr[NUM] = {456,87,12,56,332,458,12};

    for(auto i : arr){
        cout << i << " ";
    }
    cout << "\n";
    std::sort(arr, arr + NUM);

    for(auto i : arr) cout << i << " ";

    return 0;
}