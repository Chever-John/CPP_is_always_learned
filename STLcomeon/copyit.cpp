/**
 * date: 2021年2月21日
 * descriptions: 研究一下迭代器的原因。
 */

#include <iostream>
#include <iterator>
#include <vector>

int main(){
    using namespace std;

    int casts[10] = { 6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);
    copy(casts, casts + 10, dice.begin());
    cout << "Let the dice be cast!\n";

    ostream_iterator<int, char> out_iter(cout, " ");

    copy(dice.begin(), dice.end(), out_iter);//又学到一招新的用来输出的方法咯，就是很离谱哦！

    cout << endl;

    cout << "Explicit use of reverse iterator.\n";
    vector<int>::reverse_iterator ri;
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri){
        cout << *ri << ' ';
    }
    cout << endl;

    return 0;
}