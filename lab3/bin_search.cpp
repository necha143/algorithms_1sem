#include <iostream>
using namespace std;

class bin_search { public:
    int res1=-1;
    int res2=-1;

    void first (int array[], int n, int k){
        int left = 0;
        int right = n-1;
        int middle;

        while (left<=right){
            middle=(right-left)/2 + left;
            if (array[middle]==k){
                res1=middle;
                right=middle-1;
            } else if (array[middle]>k){
                right=middle-1;
            } else if (array[middle]<k){
                left=middle+1;
            }
        }
    }

    void last (int array[], int n, int k){
        int left = 0;
        int right = n-1;
        int middle;
        while (left<=right){
            middle=(right-left)/2 + left;
            if (array[middle]==k){
                res2=middle;
                left=middle+1;
            } else if (array[middle]>k){
                right=middle-1;
            } else if (array[middle]<k){
                left=middle+1;
            }
        }
    }

    void print(){
        if (res1!=-1 and res2!=-1){
            cout << res1+1 << " " << res2+1 << "\n";
            res1=-1; res2=-1;
        } else {
            cout << "-1 -1" << "\n";
        }
    }
} bin_Search;

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i=0;i<n;i++){
        cin >> array[i];
    }

    int m;
    cin >> m;
    int k[m];
    for (int i=0;i<m;i++){
        cin >> k[i];
    }

    sort(array, array+n);

    for (int i=0; i<m; i++){
        bin_Search.first(array,n,k[i]);
        bin_Search.last(array,n,k[i]);
        bin_Search.print();
    }

    return 0;
}