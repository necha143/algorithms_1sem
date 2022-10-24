#include <iostream>
using namespace std;

double search_B(double left, double right, double A, int n){
    double h[n];
    h[0]=A;
    while (right-left>0.000001/(n-1)){
        double mid=(left+right)/2;
        h[1]=mid;
        bool check = true;
        for (int i=2; i<n; i++){
            h[i]=2*h[i-1]-h[i-2]+2;
            if (h[i]<0){
                check= false;
                break;
            }
        }
        if (check){
            right=mid;
        } else {
            left=mid;
        }
    }
    return h[n-1];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; double A;
    cin >> n >> A;

    printf("%.2f", search_B(0,A,A,n));
    return 0;
}