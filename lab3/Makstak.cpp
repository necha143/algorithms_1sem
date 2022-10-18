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
    one* head1;
    one* tail1;
    stak() : head(nullptr), tail(nullptr), head1(nullptr), tail1(nullptr) {}

    bool empty(){
        if (head==nullptr and head1==nullptr){
            return true;
        }
        return false;
    }

    void push(int val){
        one* ch = new one (val);
        if (empty()){
            head=ch;
            tail=ch;
            head1=ch;
            tail1=ch;

        } else {
            tail->next=ch;
            ch->next= nullptr;
            ch->prev=tail;
            tail=ch;

            if (tail->val > tail1->val){
                tail1->next=ch;
                ch->next= nullptr;
                ch->prev=tail1;
                tail1=ch;
            } else {
                one* ch2 = new one (tail1->val);
                tail1->next=ch2;
                ch2->next= nullptr;
                ch2->prev=tail1;
                tail1= ch2;
            }
        }
    }

    void pop(){
        if (head==tail and head1==tail1){
            head= nullptr;
            tail= nullptr;
            head1= nullptr;
            tail1= nullptr;
        } else {
            tail = tail->prev;
            tail1=tail1->prev;
        }
    }

    void max_elem(){
        int max;
        one* sled = tail1;
        max = sled->val;
        cout << max << "\n";
    }
} list_stak1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        char sign[4];
        int elem;
        cin >> sign;
        if (sign[0]=='+') {
            cin >> elem;
            list_stak1.push(elem);
        } else if (sign[0]=='-'){
            list_stak1.pop();
        } else {
            list_stak1.max_elem();
        }
    }
    return 0;
}