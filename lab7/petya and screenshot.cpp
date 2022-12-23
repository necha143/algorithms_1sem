#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    char arr[n][m];
    int left_arr[n][m];
    int up_arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '1') {
                left_arr[i][j] = j;
            } else if (j == 0) {
                left_arr[i][j] = -1;
            } else {
                left_arr[i][j] = left_arr[i][j-1];
            }
            if (arr[i][j] == '1') {
                up_arr[i][j] = i;
            } else if (i == 0) {
                up_arr[i][j] = -1;
            } else {
                up_arr[i][j] = up_arr[i-1][j];
            }
        }
    }
    int dp_arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || j == 0) && arr[i][j] == '1') {
                dp_arr[i][j] = 0;
            } else if ((i == 0 || j == 0) && arr[i][j] == '5') {
                dp_arr[i][j] = 1;
            } else {
                dp_arr[i][j] = min(min(i - up_arr[i][j], j - left_arr[i][j]), dp_arr[i - 1][j - 1]+1);
            }
        }
    }
    int max = 0;
    int x;
    int y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp_arr[i][j] >= max) {
                max = dp_arr[i][j];
                y = i;
                x = j;
            }
        }
    }
    
    cout << max << ' ' << (y + 2 - max) << ' ' << (x + 2 - max);
    return 0;
}