#include <iostream>
using namespace std;
const int nmax=100000;

void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int to_sort[nmax];
    i = left;
    j = mid + 1;
    k = 0;

    while (i <= mid and j <= right) {
        if (array[i] < array[j]) {
            to_sort[k] = array[i];
            i++;
        }
        else {
            to_sort[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        to_sort[k] = array[i];
        i++; k++;
    }

    while (j <= right) {
        to_sort[k] = array[j];
        j++; k++;
    }

    for (i = 0; i<k; i++)
        array[left + i] = to_sort[i];
}

void MergeSort(int *array,int left, int right)
{
    int mid;
    if (left<right){
        mid = (left+right)/2;
        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    int array[nmax];
    for (int k=0; k<n; k++) {
        cin >> array[k];
    }

    MergeSort(array,0,n-1);

    for (int k = 0; k<n; k++) {
        cout << array[k] << ' ';
    }

    return 0;
}