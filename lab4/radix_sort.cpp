/*#include <iostream>
using namespace std;

void countingSort(string arr[], int n, int clas) {
    char max='a';
    for (int i=0; i<n; i++){
        max=std::max(arr[i][clas],max);
    }

    int k=max+1-97;
    int CountArr[k];
    for (int i=0; i<k; i++){
        CountArr[i]=0;
    }

    for (int i = 0; i < n; i++) {
        CountArr[arr[i][clas]-97]++;
    }

    for (int i = 1; i < k; i++) {
        CountArr[i] = CountArr[i] + CountArr[i-1];
    }

    string sortArray[n];
    for (int i = n-1; i >= 0; i--) {
        sortArray[CountArr[arr[i][clas]-97]-1] = arr[i];
        CountArr[arr[i][clas]-97]--;
    }

    for (int i=0; i<n; i++){
        arr[i]=sortArray[i];
    }
}

void radixSort(string array[], int n, int k, int m) {
    for (int clas=m-1; clas>=m-k; clas--) {
        countingSort(array, n, clas);
    }
}

void print(string array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << "\n";
    }
}

int main() {
    int n, m ,k;
    cin >> n >> m >> k;
    string array[n];
    for (int i=0;i<n; i++){
        cin >> array[i];
    }

    radixSort(array, n, k, m);
    print(array, n);
    return 0;
}*/