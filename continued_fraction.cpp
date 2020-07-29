#include<iostream>
#include<cstring>
using namespace std;

int len;

void continued_fraction_cast_num(){

}

void num_cast_continued_fraction(){

}


int main(){
    while (cin >> str) {
        len = strlen(str);
        if(str[0] == ']') {
            continued_fraction_cast_num();
        } else {
            num_cast_continued_fraction();
        }
    }
}