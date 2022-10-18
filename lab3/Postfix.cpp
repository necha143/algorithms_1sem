#include <iostream>
#include <string>
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

    void plus(){
        int res=tail->val + tail->prev->val;
        pop();
        pop();
        push(res);
    }

    void minus(){
        int res=tail->prev->val - tail->val;
        pop();
        pop();
        push(res);
    }

    void multiply(){
        int res=tail->val * tail->prev->val;
        pop();
        pop();
        push(res);
    }

    void pop(){
        if (head==tail){
            head= nullptr;
            tail= nullptr;
        } else {
            tail = tail->prev;
        }
    }

    void print(){
        cout << tail->val << "\n";
    }

    void primer(){
        string tsk;
        getline(cin,tsk);
        for (char a:tsk){
            int b= a-'0'; //a - '0' эквивалентно ((int)a) - ((int)'0'), что означает,
            //что значения символов ascii вычитаются друг из друга.
            //Поскольку 0 он находится непосредственно перед 1 в таблице ascii (и так далее до 9),
            //разница между ними дает число, которое представляет символa.
            if (a=='+'){
                plus();
            } else if (a=='-'){
                minus();
            } else if (a=='*'){
                multiply();
            } else if (a==' '){
                continue;
            } else{
                push(b);
            }
        }
    }
} list_stak3;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (!cin.eof()){
        list_stak3.primer();
    }

    list_stak3.print();
    return 0;
}