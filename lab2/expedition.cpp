/*#include <iostream>
using namespace std;

int CCCC()
{
    int n, m;
    cin >> n >> m;
    int size = n*m;
    int array[size];
    for (int i=0; i<size; i++) {
        cin >> array[i];
    }

    int k;
    cin >> k;
    int array_weight[k];
    for (int i=0; i<k; i++) {
        cin >> array_weight[i];
    }

    for (int i=0; i<size; i++){
        int l=i;
        while (l>0 and array[l]<array[l-1]){
            swap(array[l],array[l-1]);
            l--;
        }
    }

    for (int i=0; i<k; i++){
        int l=i;
        while (l>0 and array_weight[l]<array_weight[l-1]){
            swap(array_weight[l],array_weight[l-1]);
            l--;
        }
    }

    int cnt=0;
    for (int i=0; i<size; i++){
        for (int j=0; j<k; j++){
            if (array_weight[j]<=array[i] and array[i]!=0 and array_weight[j]!=0){
                cnt++;
                array[i]=0;
                array_weight[j]=0;
            }
        }
    }

    cout << cnt;

    return 0;
}*/