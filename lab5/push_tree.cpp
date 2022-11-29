/*#include <iostream>
using namespace std;
int k=1;

void push(int array[][3], int i){
    i--;
    int left=array[i][1];
    int right=array[i][2];
    if (i!=-1){
        push(array,left);
        array[i][0]=k;
        k++;
        push(array,right);
    }
}

void print(int array[][3], int n){
    for (int i=0; i<n; i++){
        cout << array[i][0] << " ";
    }
}

int main (){
    int n; cin >> n;
    int array[n][3];
    for (int i=0; i<n; i++){
        array[i][0]=i+1;
        cin >> array[i][1] >> array[i][2];
    }

    push(array,1);
    print(array,n);
    return 0;
}*/