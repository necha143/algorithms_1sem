/*#include <iostream>
using namespace std;

typedef struct tree_elem{
    int data;
    tree_elem *left= nullptr;
    tree_elem *right= nullptr;
    tree_elem *parent= nullptr;
}node;

struct two_ways{
    node *root= nullptr;

    void insert(int array[], int n){
        root=new node;
        node *elem[n];
        root->data=array[0];
        elem[array[0]]=root;

        for (int i = 1; i < n; i++) {
            node *root_help=new node;

            if (array[i] < array[i-1]) {
                root_help->data=array[i];
                elem[array[i-1]]->left = root_help;
                root_help->parent = elem[array[i-1]];
                elem[array[i]] = root_help;
            }
            else {
                root_help->data=array[i];
                node *parent = prev(elem[array[i-1]],array[i]);
                parent->right = root_help;
                root_help->parent = parent;
                elem[array[i]] = root_help;
            }
        }
    }

    node *prev(node *mx, int elem){
        node *maxs = mx;
        while (mx != root) {
            if (mx->parent->data<elem) {
                mx=mx->parent;
                if (maxs->data<mx->data) {
                    maxs=mx;
                }
            }
            else {
                break;
            }
        }
        return maxs;
    }

    void preorderPrint(node *root){
        if (root == nullptr)
        {
            return;
        }
        preorderPrint(root->left);
        preorderPrint(root->right);
        cout << root->data << " ";
    }

}twoWays;


int main(){
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++){
        cin >> array[i];
    }

    twoWays.insert(array, n);
    twoWays.preorderPrint(twoWays.root);

    return 0;
}*/