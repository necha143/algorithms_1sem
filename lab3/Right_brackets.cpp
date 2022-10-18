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
            head= nullptr;
            tail= nullptr;
        } else {
            tail = tail->prev;
        }
    }

    void null(){
        head= nullptr;
        tail= nullptr;
    }

    void check(){
        string bracket;
        getline(cin,bracket);
        for (char a:bracket){
            if (a=='(' or a=='['){
                push(a);
            } else if (a==')'){
                if (empty()){
                    cout << "NO" << "\n";
                    null();
                    return;
                } else if (tail->val=='['){
                    cout << "NO" << "\n";
                    null();
                    return;
                } else {
                    pop();
                }
            } else if (a==']'){
                if (empty()){
                    cout << "NO" << "\n";
                    null();
                    return;
                } else if (tail->val=='('){
                    cout << "NO" << "\n";
                    null();
                    return;
                } else {
                    pop();
                }
            }
        }
        if (empty()){
            cout << "YES" << "\n";
            return;
        } else {
            cout << "NO" << "\n";
            null();
        }
    }

} list_stak2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (!cin.eof()){
        list_stak2.check();
    }

    return 0;
}