#include "iostream"
using namespace std;

bool sum(int arr[], int n) {
    for(int i = 0; i < (n-2); i++) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {

                    cout << arr[i] << ", " << arr[j] << " and " << arr[k] << " forms a triplet with sum equal to 0\n";
                    return true;
                }
            }
        }
    }

    cout << "No triplet with zero sum exists" << endl;
    return false;
}


int main() {
    int n = 0;
    cout << "Enter size of array: " << endl;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    sum(arr, n);



    return 0;
}