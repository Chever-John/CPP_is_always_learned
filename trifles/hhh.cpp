#include <cstdio>
#include <iostream>

bool prime(unsigned long long num);

int main() {
  unsigned long long temp;
  unsigned long long max = 600851475143;
  FILE* fptr;

  try {
    fptr = fopen("primes.txt", "w");

#pragma omp parallel for
    for (unsigned long long i = 2; i < max; i++) {
      if (prime(i)) {
        temp = i;
        fputs(i + ",", fptr);
        // int percent = (int)((float)i)/((float)max);
        // if(percent > 1 && (percent % 10 == 0)){
        //  std::cout << "Percent Complete: " << percent << std::endl;
        //}
      }
    }
    std::cout << temp << std::endl;
    fclose(fptr);
  } catch (...) {
    std::cout << "Exception!" << std::endl;
  }
  return 0;
}

bool prime(unsigned long long num) {
  for (unsigned long long i = 2; i < num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}