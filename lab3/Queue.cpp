#include <iostream>
using namespace std;

struct one{
    int val; //переменная одной ячейки
    struct one* next; //указатель на след ячейку
    one (int num) : val(num),next(nullptr) {} //констркутор ячейки
};

class queue { public:
    one* head; //указатель на начало
    one* tail; //указатель на конец
    queue() : head(nullptr), tail(nullptr) {} //для начала, указатели не должны ссылаться никуда

    bool empty() { //проверяем, пустой ли у нас список, нет ли ссылок у бегин
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void push(int val) {
        one* ch = new one(val);
        if (empty()) {
            head = ch;
            tail = ch;
        } else {
            tail->next = ch;
            tail = ch;
        }
    }

    void pop() {
        if (head == tail) {
            cout << head->val << "\n";
            head= nullptr;
            tail= nullptr;
        } else {
            cout << head->val << "\n";
            head = head->next;
        }
    }
} list_qu;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        char sign;
        int elem;
        cin >> sign;
        if (sign=='+'){
            cin >> elem;
            list_qu.push(elem);
        } else {
            list_qu.pop();
        }
    }
    return 0;
}