/*#include <iostream>
using namespace std;

void QuickSort(int *array, int left, int right)
{
    int i = left;
    int j = right;
    int middle = array[(i + j)/2];

    while (i <= j)
    {
        while (array[i] < middle)
            i++;
        while (array[j] > middle)
            j--;
        if (i <= j)
        {
            int dop = array[i];
            array[i]=array[j];
            array[j]=dop;
            i++;
            j--;
        }
    }
    if (j > left)
        QuickSort(array, left, j);
    if (i < right)
        QuickSort(array, i, right);
}

int IIIII()
{
    int n;
    cin >> n;
    int array[n];
    for (int k=0; k<n; k++) {
        cin >> array[k];
    }

    QuickSort(array,0,n-1);

    for (int k = 0; k<n; k++) {
        cout << array[k] << ' ';
    }

    return 0;
}*/