#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long x[n];
    for (int k=0; k<n; k++) {
        cin >> x[k];
    }

    for (int k=0; k<n; k++){
        int l=k;
        char flag='F';

        while (l>0 and x[l]<x[l-1]){
            swap(x[l],x[l-1]);
            l--;
            flag='T';
        }

        if (flag=='T'){
            for (int m = 0; m<n; m++) {
                cout << x[m] << ' ';
            }
            cout << endl;}
    }

    return 0;
}