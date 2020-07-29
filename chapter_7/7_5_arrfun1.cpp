#include <iostream>
const int ArSize = 8;

int sums(int arr[], int n);

int main()
{
    using namespace std;
    int counts[ArSize] = { 1, 2, 4, 8, 16, 32, 64,128};

    int sum = sums(counts, ArSize);
    cout << "Total counts: " << sum << "\n";
    return 0;
}

int sums(int arr[], int n){
    int total = 0;
    for(int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}