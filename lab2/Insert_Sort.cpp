#include <iostream>
using namespace std;

int main()
{
    int n, x[1000];
    cin >> n;
    for (int k=0; k<n; k++) {
        cin >> x[k];
    }

    for (int k=0; k<n; k++){
        int l=k;
        while (l>0 and x[l]<x[l-1]){
            swap(x[l],x[l-1]);
            l--;
        }
    }

    for (int k = 0; k<n; k++) {
        cout << x[k] << ' ';
    }

    return 0;
}