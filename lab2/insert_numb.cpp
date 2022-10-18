#include <iostream>
using namespace std;

int main()
{
    int n, x[1000], a, b;
    cin>> n;

    for (int k = 0; k < n; k++) {
        cin>> x[k];
    }

    cin>> a;
    cin>> b;

    for (int k=n-1; k >=(b-1); k--) {
        x[k+1]=x[k];
    }
    x[b-1]=a;
    for (int k = 0; k<n+1; k++) {
        cout << x[k] << ' ';
    }

    return 0;
}