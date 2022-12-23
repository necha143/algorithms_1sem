#include <iostream>
using namespace std;

void is_balance(int array[][3], int i, int check[]){
    i--;
    int left=array[i][1];
    int right=array[i][2];

    if (i!=-1){
        check[i+1] = 1 + max(check[left], check[right]);
        is_balance(array, i, check);
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
    int check[n];
    for (int i=0; i<n; i++){
        cin >> array[i][0] >> array[i][1] >> array[i][2];
    }

    is_balance(array,n, check);

    for (int i=0; i<n; i++){
        int ans = check[array[i][2]] - check[array[i][1]];
        cout << ans << "\n";
    }

    return 0;
}
