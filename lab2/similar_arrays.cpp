#include <iostream>
#include <vector>
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

int main()
{
    int n1;
    cin >> n1;
    int array1[n1];
    for (int k = 0; k < n1; k++) {
        cin >> array1[k];
    }

    int n2;
    cin >> n2;
    int array2[n2];
    for (int k = 0; k < n2; k++) {
        cin >> array2[k];
    }

    QuickSort(array1,0,n1-1);
    QuickSort(array2,0,n2-1);

    vector <int> ans1;
    vector <int> ans2;

    int smvl;
    ans1.push_back(array1[0]);
    smvl = array1[0];
    for (int i = 1; i < n1; i++) {
        if (smvl != array1[i]) {
            smvl = array1[i];
            ans1.push_back(smvl);
        }
    }

    ans2.push_back(array2[0]);
    smvl = array2[0];
    for (int i = 0; i < n2; i++) {
        if (smvl != array2[i]) {
            smvl = array2[i];
            ans2.push_back(smvl);
        }
    }

    if (ans1 == ans2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}