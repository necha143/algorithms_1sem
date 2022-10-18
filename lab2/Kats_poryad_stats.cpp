/*#include <iostream>
#include <cstdlib>
using namespace std;

void kps (int *array, int l, int r, int k){
    if (l>=r){
        return;
    } else {
        int pivot = array[(l+r)/2];
        int left = l;
        int right = r;
        while (left<=right) {
            while (array[left]<pivot) {
                left++;
            }
            while (array[right]>pivot){
                right--;
            }
            if (left<=right){
                int dop = array[left];
                array[left]=array[right];
                array[right]=dop;
                left++;
                right--;
            }
        }
        if (k<=right){
            kps(array,l,right,k);
        } else {
            kps(array,left,r,k);
        }
    }
}

int main() {
    int n, k;
    int a, b, c, arr1, arr2;

    cin >> n >> k;
    cin >> a >> b >> c >> arr1 >> arr2;

    int *array = (int*) calloc(n, sizeof(int));
    array[0]=arr1;
    array[1]=arr2;

    for (int i = 2; i < n; i++) {
        array[i] = a*array[i-2] + b*array[i-1] + c;
    }

    kps(array, 0, n-1, k-1);

    cout << array[k-1];

    return 0;
}*/