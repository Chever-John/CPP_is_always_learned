#include<iostream>

int main(){
     int x;
     std::cin >> x;
     for(int i = 0; i < x; i++){
          for(int j = i; j < x - 1; j++)
               std::cout << '\0';
          for(int j = 0; j < i * 2 + 1; j++)
               std::cout << '#';
          std::cout << std::endl;
     }
     return 0;
}

