#include <iostream>
#include <vector>

using namespace std;

int recursiveForDP(int * n);
int main(){
    int n;
    cin >> n;
    vector<int> dp(n);

    for (int i = 0; i < n; i++){
        cin >> dp[i];
    }

    cout << "start output!" << endl;
    // cout << dp[1] << endl;
    for (auto i : dp){
        cout << i << endl;
        // cout << dp[i] << " ";
    }

    return 0;
}