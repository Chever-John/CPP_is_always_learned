#include<iostream>
using namespace std;

void Bubble_Sort(int a[]){
    int i,j;
    for ( i = 0; i < 9; i++){
        for ( j = i + 1; j <= 9; j++){
            if(a[i] > a[j]) {
                int m = a[i];
                int n = a[j];
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int a[10];
    for (int i = 0; i < 10; i++){
        cin >> a[i];
    }

    Bubble_Sort(a);    
    for (int i = 0; i < 10; i++){
        cout  << a[i] << " ";
    }
}