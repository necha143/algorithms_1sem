/*
#include <iostream>
using namespace std;

void build_sum_tree(int *array, int *array_new, int left, int right, int v, int n) {
    if (left==right-1) {
        if (left < n) {
            array_new[v] = array[left];
        }
        return;
    }

    int first_kid=2*v+1;
    int second_kid=2*v+2;
    build_sum_tree(array, array_new, left, (left+right)/2, first_kid, n);
    build_sum_tree(array, array_new, (left+right)/2, right, second_kid, n);
    array_new[v] = array_new[first_kid] + array_new[second_kid];// потомки некой вершины
}

void set_in(int *array, int v, int left, int right, int index, int val) {
    if (left==right-1) {
        array[v]=val;
        return;
    }

    int first_kid=2*v+1;
    int second_kid=2*v+2;
    if (index < (left+right)/2) {
        set_in(array, first_kid, left, (left+right)/2, index, val);
    } else {
        set_in(array, second_kid, (left+right)/2, right, index, val);
    }
    array[v] = array[first_kid] + array[second_kid];// потомки некой вершины
}

int summary(int *array_new, int v, int L, int R, int left, int right) {
    if (right<=L or left>=R) {
        return 0;
    } else if (left<=L and R<=right) {
        return array_new[v];
    }

    int first_kid=2*v+1;
    int second_kid=2*v+2;
    return summary(array_new, first_kid, L, (L+R)/2, left, right) + summary(array_new, second_kid, (L+R)/2, R, left, right);
}

int main() {
    int n, q; cin >> n >> q;
    if (n==0) {
        return 0;
    }
    n++;
    int array[n], array2[n*4];
    for (int i = 0; i < n; ++i) {
        array[i] = 0;
    }
    for (int i = 0; i < 4 * n; ++i) {
        array2[i] = 0;
    }

    build_sum_tree(array, array2, 0, n, 0, n);

    char sign; int index, val;
    for (int i=0; i<q; i++) {
        cin >> sign;
        if (sign=='+'){
            cin >> index >> val;
            array[index] += val;
            set_in(array2, 0, 0, n, index-1, array[index]);
        } else if (sign=='-'){
            cin >> index >> val;
            array[index] -= val;
            if (array[index] < 0) {
                array[index] = 0;
            }
            set_in(array2, 0, 0, n, index-1, array[index]);
        } else if (sign=='?'){
            cin >> index >> val;
            cout << summary(array2, 0, 0, n, index - 1, val) << "\n";
        }
    }
    return 0;
}*/
