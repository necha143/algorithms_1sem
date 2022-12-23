/*
#include <iostream>
using namespace std;
int S; int N;

void bag(int array[]){
    int gold[N+1][S+1];

    for (int i=0; i<=N; i++) {
        for (int j=0; j<=S; j++) {
            if (i==0 or j==0) {
                gold[i][j]=0;    //Первые элементы приравниваем к 0
            } else if (j>=array[i-1]) {   //Если текущий предмет вмещается в рюкзак
                gold[i][j] = max(gold[i-1][j], gold[i-1][j-array[i-1]]+array[i-1]);  //Выбираем какой положить
            } else {
                gold[i][j] = gold[i-1][j];   //Если не помещается просто кладем предыдущий
            }
        }
    }

    cout << gold[N][S];
}


int main() {
    cin >> S >> N;
    int array[N];
    for (int i=0; i<N; i++) {
        cin >> array[i];
    }

    bag(array);
    return 0;
}*/
