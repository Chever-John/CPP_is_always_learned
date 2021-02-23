#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    using std::vector;
    using std::cin;
    using std::cout;

    int cases[10] = { 6, 7, 2, 9, 4, 11, 8, 7, 10, 5};

    vector<int> dice(10);

    dice[0]= {1};
    for (auto x : dice) cout << x << " ";
    
    cout << "\n";
    std::copy(cases, cases + 10, dice.begin());

    for (auto x : dice) cout << x << " ";

    return 0;
}