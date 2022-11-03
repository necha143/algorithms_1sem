#include <iostream>
using namespace std;

void heapify(int i, int array[], int n){
    int max=i;
    while (true){
        int left_child=2*i+1;
        int right_child=2*i+2;

        if (left_child<n and array[left_child]>array[max]){
            max=left_child;
        }
        if (right_child<n and array[right_child]>array[max]){
            max=right_child;
        }
        if (i==max){
            break;
        }
        swap(array[max],array[i]);
        i=max;
    }
    return;
}

void build_heap(int n, int array[]){
    for (int i = n / 2; i >= 0; i--){
        heapify(i,array,n);
    }
    return;
}

void heap_sort(int array[], int n){
    build_heap(n,array);
    for (int i=n-1; i>0;i--){
        swap(array[0],array[i]);
        heapify(0,array,i);
    }

    for (int i=0; i<n; i++){
        cout << array[i] << " ";
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i=0; i<n; i++){
        cin >> array[i];
    }

    heap_sort(array,n);
    return 0;
}