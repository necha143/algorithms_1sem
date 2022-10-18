#include <iostream>
#include <vector>
using namespace std;

/*void quickSort(int *array, int left, int right)
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
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}

int HHHHH()
{
    int n;
    cin >> n;
    int array_left[n], array_right[n];
    for (int i=0; i<n;i++){
        cin >> array_left[i];
        cin >> array_right[i];
    }

    quickSort(array_left,0,n-1);
    quickSort(array_right,0,n-1);

    int ans = array_right[0] - array_left[0] + 1;
    for (int i=1;i<n;i++){
        if (array_left[i] - array_right[i-1] < 2){
            ans+=array_right[i]-array_right[i-1];
        } else {
            ans+=array_right[i]-array_left[i]+1;
        }
    }

    cout << ans << endl;
    return 0;
}*/