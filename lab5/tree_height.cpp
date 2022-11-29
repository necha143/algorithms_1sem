#include <iostream>
using namespace std;

int check(int left, int right){
    if (left > right){
        return left;
    } else {
        return right;
    }
}

int max_height(int array[][3], int i){
    i--;
    int left=array[i][1];
    int right=array[i][2];

    if (left==0 and right==0) {
        return 1;
    } else if (right==0){
        return 1 + max_height(array,left);
    } else if (left==0){
        return 1 + max_height(array,right);
    } else {
        return 1 + check(max_height(array,left), max_height(array,right));
    }
}

int main() {
    int n;
    cin >> n;
    if (n==0) {
        cout << 0;
        return 0;
    }

    int array[n][3];
    for (int i=0; i<n; i++){
        cin >> array[i][0] >> array[i][1] >> array[i][2];
    }

    cout << max_height(array,1);
    return 0;
}
