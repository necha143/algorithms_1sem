#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct PRIO_QUEUE {
    vector<int> array;
    vector<int> pushh;

    void siftDown(int i, int n){
        int max = i;

        while (2*i + 1 < n) {
            int left_child = 2*i + 1;
            int right_child = 2*i + 2;

            if (array[max] > array[left_child]) {
                max = left_child;
            }
            if (array[max] > array[right_child] and right_child < n) {
                max = right_child;
            }

            if (array[max] < array[i]) {
                swap(array[max], array[i]);
            } else {
                break;
            }
            i = max;
        }
    }

    void siftUP(int i){
        while ((i - 1) / 2 >= 0 and array[(i - 1) / 2] > array[i]) {
            swap(array[(i - 1) / 2], array[i]);
            i = (i - 1) / 2;
        }
    }

    void push(int elem){
        pushh.push_back(elem);
        array.push_back(elem);
        int n = array.size()-1;
        siftUP(n);
    }

    void extract_min(){
        pushh.push_back(INT_MIN);
        if (array.empty()){
            cout << "*" << "\n";
            return;
        } else {
            int min=array[0];
            swap(array[0], array[array.size()-1]);
            array.pop_back();
            siftDown(0, array.size());
            cout << min << "\n";
            return;
        }
    }

    void decrease_key(int x, int y){
        pushh.push_back(INT_MIN);
        int index;
        for (int i=0; i<array.size(); i++){
            if (array[i]==pushh[x-1]){
                array[i]=y;
                index=i;
                break;
            }
        }
        siftUP(index);
        pushh[x-1]=y;
    }
};


int main(){
    PRIO_QUEUE queue;

    string s, sign;
    while (getline(cin,s)){
        int elem, x, y;
        if (s.empty()){
            break;
        }
        istringstream iss(s);
        iss >> sign;
        if (sign=="push"){
            iss >> elem;
            queue.push(elem);
        } else if (sign=="extract-min"){
            queue.extract_min();
        } else if (sign=="decrease-key"){
            iss >> x >> y;
            queue.decrease_key(x, y);
        }
    }

    return 0;
}