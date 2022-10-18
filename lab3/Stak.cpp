#include <iostream>
using namespace std;

struct one{
    int val;
    struct one* next;
    struct one* prev;
    one (int num) : prev(nullptr), val(num), next(nullptr) {}
};

class stak { public:
    one* head;
    one* tail;
    stak() : head(nullptr), tail(nullptr) {}

    bool empty(){
        if (head==nullptr){
            return true;
        }
        return false;
    }

    void push(int val){
        one* ch = new one (val);
        if (empty()){
            head=ch;
            tail=ch;
        } else {
            tail->next=ch;
            ch->next= nullptr;
            ch->prev=tail;
            tail=ch;
        }
    }

    void pop(){
        if (head==tail){
            cout << head->val << "\n";
            head= nullptr;
            tail= nullptr;
        } else {
            cout << tail->val << "\n";
            tail = tail->prev;
        }
    }
} list_stak;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        char sign;
        int elem;
        cin >> sign;
        if (sign=='+'){
            cin >> elem;
            list_stak.push(elem);
        } else {
            list_stak.pop();
        }
    }
    return 0;
}