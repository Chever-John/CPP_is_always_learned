void show_array(const double arr[], int n){
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << arr[i] << endl;
    }
    
}