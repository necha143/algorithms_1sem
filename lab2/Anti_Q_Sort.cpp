#include <iostream>
using namespace std;

void anti_Qsort(int *a, int n)
{
    for (int i=2; i < n; i++){
        swap(a[i], a[i / 2]);
    }
}

int main(){
    int n;
    cin >> n;
    int array[n];
    int k=1;
    for (int i=0; i<n; i++){
        array[i]=k;
        k++;
    }

    anti_Qsort(array,n);

    for (int i = 0; i<n; i++){
        cout << array[i] << " ";
    }

    return 0;
}