#include <iostream>
using namespace std;

int main() {
    int arr[] = { 23, 12, 1, 5, 9, 44, 2, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]); 

    
    for (int gap = n / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
    }

    
    cout << "Ready: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
