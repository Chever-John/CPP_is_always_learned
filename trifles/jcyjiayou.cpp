#include<iostream>
using namespace std;
int main()
{
    int m, n, i, j;
    cout << "Please enter the number of judges and contestants:";
    cin >> n >> m;
    for(j = 1; j <= m; j++)
    {
        int max = 0, min = 100;
        double sum = 0;
        double avg = 0;
        int score[100];
        cout << "No."<< j << "player:";
        for(i = 1; i <= n; i++)
        {
            cin >> score[i];    
            sum=sum+score[i];
            if(score[i] > max)
            {
                max = score[i];
            }
            if(score[i] < min)
            {
                min = score[i];
            }
            avg = (sum - max - min) / (n - 2);
        }
        cout << "Final score: " << avg << endl;
    }
    return 0;
}