#include <iostream>
using namespace std;

void is_heap(int n, int *array){
    bool res= true;

    for (int i=1; i<=n; i++){
        if (2*i<n){
            if (array[i] > array[2*i]){
                res= false;
            }
        }
        if (2*i+1<n){
            if (array[i] > array[2*i+1]){
                res= false;
            }
        }
    }

    if (res){
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}


int main(){
    int n;
    cin >> n;
    int array[n+1];
    for (int i=1; i<n; i++){
        cin >> array[i];
    }

    is_heap(n,array);
    return 0;
}
