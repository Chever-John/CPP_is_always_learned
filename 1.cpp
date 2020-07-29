#include <iostream>
#include <algorithm>

const int ArSize = 10;
//int binary_search(int arr[],int n,int valueforsearch);

int main() {

	int wait_for_search[ArSize] = { 5,1,2,3,7,9,5,4,1,55 };
	
	std::cout << wait_for_search << "=array's address";
	std::cout << sizeof wait_for_search << "=sizeof wait_for_search\n";
	std::sort(wait_for_search, wait_for_search + ArSize);
	for (int i = 0; i < ArSize; i++) {
		std::cout << wait_for_search[i] << " ";
	}
	return 0;
	//int returned_value = binary_search(wait_for_search, ArSize, 11);
}

//int binary_search(int arr[], int n, int valueforsearch) {
//
//}