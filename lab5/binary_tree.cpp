/*#include <iostream>
#include <sstream>
using namespace std;

typedef struct tree_elem{
    int data;
    tree_elem *left= nullptr;
    tree_elem *right= nullptr;
    tree_elem *parent= nullptr;
} node;

struct bin_tree{
    node *root= nullptr;

    void insert (int elem) {

        node *numb = new node;
        numb->data = elem;

        if (root== nullptr) {
            root=numb;
            return;
        } else if (exists(root,elem)== nullptr) {

            node *root_help=root;

            while (root_help != nullptr) {
                if (numb->data > root_help->data) {
                    if (root_help->right == nullptr) {
                        numb->parent = root_help;
                        root_help->right = numb;
                        return;
                    } else {
                        root_help = root_help->right;
                    }
                } else if (numb->data < root_help->data) {
                    if (root_help->left == nullptr) {
                        numb->parent = root_help;
                        root_help->left = numb;
                        return;
                    } else {
                        root_help = root_help->left;
                    }
                }
            }
        }
        else return;
    }

    node *exists(node *find, int elem){
        if (find==nullptr or elem==find->data){
            return find;
        }
        if (elem < find->data){
            return exists(find->left, elem);
        } else {
            return exists(find->right, elem);
        }
    }

    node *next(int elem){
        node *min = root;
        node *res = nullptr;
        while (min != nullptr) {
            if (min->data > elem) {
                res = min;
                min = min->left;
            } else {
                min = min->right;
            }
        }
        return res;
    }

    node *prev(int elem){
        node *max = root;
        node *res = nullptr;
        while (max != nullptr) {
            if (max->data < elem) {
                res = max;
                max = max->right;
            } else {
                max = max->left;
            }
        }
        return res;
    }

    node *kill(int elem) {
        node *del = exists(root, elem);
        if (del == nullptr) {
            return del;
        }

        if (del != root) { //обычное удаление элемента нерекурсивно
            node *p = del->parent;
            if (del->left == nullptr and del->right == nullptr) {
                if (p->left == del) {
                    p->left = nullptr;
                    return p;
                } else {
                    p->right = nullptr;
                    return p;
                }
            } else if (del->left == nullptr or del->right == nullptr) {
                if (del->left == nullptr) {
                    if (p->left == del) {
                        p->left = del->right;
                    } else {
                        p->right = del->right;
                    }
                    del->right->parent = p;
                } else {
                    if (p->left == del) {
                        p->left = del->left;
                    } else {
                        p->right = del->left;
                    }
                    del->left->parent = p;
                }
            } else {
                node *help_del = del;
                help_del = help_del->right;
                while (help_del->left != nullptr) {
                    help_del = help_del->left;
                }
                del->data = help_del->data;
                if (help_del->parent->left == help_del) {
                    help_del->parent->left = help_del->right;
                    if (help_del->right != nullptr) {
                        help_del->right->parent = help_del->parent;
                    }
                } else {
                    help_del->parent->right = help_del->right;
                    if (help_del->right != nullptr) {
                        help_del->right->parent = help_del->parent;
                    }
                }
            }
        } else { // помощь, в случае если надо удалить корень
            if (del->left == nullptr and del->right == nullptr) {
                root = nullptr;
            } else if (del->left != nullptr and del->right != nullptr) {
                del = del->right;
                while (del->left != nullptr) {
                    del = del->left;
                }
                if (del->parent == root) {
                    del->parent = nullptr;
                    del->left = root->left;
                    root = del;
                } else {
                    if (del->right != nullptr) {
                        del->parent->left = del->right;
                        root->data = del->data;
                    } else {
                        del->parent->left = nullptr;
                        root->data = del->data;
                    }
                }
            } else {
                if (del->left != nullptr) {
                    del->left->parent = nullptr;
                    root = del->left;
                } else {
                    del = del->right;
                    while (del->left != nullptr) {
                        del = del->left;
                    }
                    if (del->parent == root) {
                        del->parent = nullptr;
                        root = del;
                    } else {
                        if (del->right != nullptr) {
                            del->parent->left = del->right;
                            root->data = del->data;
                        }
                    }
                }
            }
        }
        return del;
    }

    node *minimum(node *mins){
        if (mins->left== nullptr){
            return mins;
        }
        return minimum(mins->left);
    }

} bin;


int main(){
    node *res;
    string s, sign;

    while (getline(cin,s)){
        int elem;
        if (s.empty()){
            break;
        }
        istringstream iss(s);
        iss >> sign;
        if (sign=="insert"){
            iss >> elem;
            bin.insert(elem);
        } else if (sign=="exists"){
            iss >> elem;
            res=bin.exists(bin.root,elem);
            if (res== nullptr){
                cout << "false" << "\n";
            } else {
                cout << "true" << "\n";
            }
        } else if (sign=="next"){
            iss >> elem;
            res=bin.next(elem);
            if (res== nullptr){
                cout << "none" << "\n";
            } else {
                cout << res->data << "\n";
            }
        } else if (sign=="prev"){
            iss >> elem;
            res=bin.prev(elem);
            if (res== nullptr){
                cout << "none" << "\n";
            } else {
                cout << res->data << "\n";
            }
        } else if (sign=="delete"){
            iss >> elem;
            bin.kill(elem);
        }
    }

    return 0;
}*/