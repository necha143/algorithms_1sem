#include <iostream>
using namespace std;

long long min_search(int n, int k, int array[]) {

    long long sum=0;
    int max_elem=0;
    for (int i=0; i<n; i++){
        sum+=array[i];
        if (array[i]>max_elem){
            max_elem=array[i];
        }
    }

    long long left=max_elem;// наим возможная сумма при разбиении
    long long right=sum;// наиб возможная суммма при разбиении
    while (left<right-1){
        long long middle=(left+right)/2;
        int splits=0;
        long long sum_array=0;

        for (int i=0;i<n;i++){
            if (sum_array+array[i]<=middle){
                sum_array+=array[i];
            } else {
                sum_array=array[i];
                splits++;
            }
        }

        if (splits>=k){ // если получилось слишком много сумм, надо искать с суммы с большими значениями
            left=middle;
        } else {
            right=middle;
        }
    }
    return left+1;// как итог - получилась минимальная сумма
}

void splitting(int n, int array[], long long min_sum, int k){
    int splits=0;
    long long sum_array=0;

    int array_splits[n];
    for (int i=0; i<n; i++){
        array_splits[i]=0;
    }

    for (int i=0;i<n;i++){
        if (sum_array+array[i]>min_sum){
            sum_array=array[i];
            array_splits[i]= 1;
            splits++;
        } else {
            sum_array=sum_array+array[i];
        }
    }

    int help_speed=n-1;
    while (k-splits>1){
        for (int i=help_speed;i>0;i--){
            if (array_splits[i]==0){
                array_splits[i]= 1;
                help_speed=i;
                splits++;
                break;
            }
        }
    }

    for (int i=0;i<n;i++){
        if (array_splits[i]==1){
            cout << i << " ";
        }
    }

    return;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; int k;
    cin >> n >> k;
    int array[n];
    for (int i=0;i<n;i++){
        cin >> array[i];
    }

    long long min_sum=min_search(n, k, array);
    splitting(n, array, min_sum, k);

    return 0;
}