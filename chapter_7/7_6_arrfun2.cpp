#include <iostream>
const int ArSize = 8;
int sums(int arr[], int n);
int main(){
    int things[ArSize] = {1,2,4,8,16,32,64,128};
    std::cout << things << " = arr address, ";

    std::cout << sizeof(things) << " = sizeof things\n";
    int sum = sums(things, ArSize);
    std::cout << "Total things: " << sum << std::endl;
    sum = sums(things, 3);
    std::cout << "First tree people buy " << sum << " things.\n";
    sum = sums(things + 4, 4);
    std::cout << "Last four people buy " << sum << " things.\n";
    return 0;
}

int sums(int arr[], int n){
    int total = 0;
    std::cout << arr << " = arr, ";
    std::cout << sizeof(* arr) << " = sizeof  arr\n ";
    for (int  i = 0; i < n; i++)
        total += arr[i];
    return total;
}