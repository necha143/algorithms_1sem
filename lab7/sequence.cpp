/*
#include <iostream>
using namespace std;

void sequence(int array[], int len[], int next[], int n){

    for (int i=n-1; i>=0; i--) {
        int lenght=0, best_next=-1;
        for (int j=i+1; j<n; j++) {
            if (array[j] > array[i]) {
                if (len[j] > lenght) {
                    lenght=len[j];
                    best_next=j;
                }
            }
        }
        next[i]=best_next; len[i]=lenght+1;
    }

    int pos=INT_MIN, best=-1;
    for (int i=0; i<n; i++) {
        if (len[i]>pos) {
            best=i;
            pos=len[i];
        }
    }

    cout << pos << "\n" << array[best] << " ";
    for (int i=next[best]; i!=-1; i=next[i]) {
        cout << array[i] << " ";
    }

    return;
}


int main() {
    int n; cin >> n;
    int array[n], len[n], next[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    sequence(array, len, next, n);
    return 0;
}*/
