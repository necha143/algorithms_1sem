#include <iostream>
using namespace std;

bool check(int array[][3], int min, int max, int i){
    if (array[i][0]<min or array[i][0]>max){
        return false;
    }
    if (array[i][1]==0 and array[i][2]==0){
        return true;
    }
    if (array[i][1]!=0 and array[i][2]!=0){
        return check(array, min, array[i][0] - 1, array[i][1]-1) and check(array, array[i][0] + 1, max, array[i][2]-1);
    } else if (array[i][1]!=0) {
        return check(array, min, array[i][0] - 1, array[i][1] - 1);
    } else if (array[i][2]!=0) {
        return check(array, array[i][0] + 1, max, array[i][2] - 1);
    }
    return false;
}

int main(){

    int n; cin >> n;
    int array[n][3];
    for (int i=0; i<n; i++){
        cin >> array[i][0] >> array[i][1] >> array[i][2];
    }

    if (n!=0){
        if (check(array, INT_MIN, INT_MAX, 0)){
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "YES";
    }

    return 0;
}
