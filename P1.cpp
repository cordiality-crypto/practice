#include <iostream>
using namespace std;

bool BinarySearch(int *, int, int, int);

/*
Test Cases:
2 4 1 2 3 4 3 4 1 2 3 4 -1 
*/
int main() {
    cout << "T = \t" << endl;
    int t;
    cin >> t;
    while (t--) {
        cout << "n = \t" << endl;
        int n;
        cin >> n; 
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i] ;
        int x;
        cout << "x = \t" << endl;
        cin >> x;
        cout << BinarySearch(arr, 0, n - 1, x) << endl;
    }
    return 0;
}

bool BinarySearch(int *arr, int low, int high, int x) {
    if (high < low) 
        return false;
    int mid = low + (high - low) / 2;
    if (*(arr + mid) == x)
        return true;
    else if (*(arr + mid) < x)
        return BinarySearch(arr, mid, high, x);
    return BinarySearch(arr, low, mid - 1, x);
}