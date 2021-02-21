#include <iostream>
#include <vector>

int main(){
    using std::cout;
    using std::cin;
    using std::vector;
    using std::endl;

    vector<int> firstVector;

    int numInserted;
    while(cin>>numInserted && numInserted >= 0){
        firstVector.push_back(numInserted);
    }

    cout << "Now we have " << firstVector.size() << " firstVectors" << endl;

    for (int i = 0; i < firstVector.size(); i++)
    {
        cout << firstVector[i] << " ";
    }

    firstVector.erase(firstVector.begin() + 1, firstVector.begin() + 2);
    
    cout << "\nNow we have " << firstVector.size() << " firstVectors" << endl;

    for (int i = 0; i < firstVector.size(); i++)
    {
        cout << firstVector[i] << " ";
    }


    return 0;

}