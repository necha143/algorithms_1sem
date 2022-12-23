/*
#include <iostream>
using namespace std;

struct node{
    node *left;
    node *right;
    int key, index, height, balance;
};

int balance_or_height(char *what, node *tree){
    int height_left=0, height_right=0;
    if (tree->left!= nullptr){
        height_left=tree->left->height;
    }
    if (tree->right!= nullptr){
        height_right=tree->right->height;
    }
    if (what=="balance"){
        return height_right-height_left;
    } else if (what=="height"){
        return max(height_left+1,height_right+1);
    }
    return 0;
}

node *rotate_right(node *tree){
    node *tree_new=tree->left;;
    tree->left=tree_new->right;
    tree_new->right=tree;
    tree->height= balance_or_height("height",tree);
    tree_new->height= balance_or_height("height",tree_new);
    return tree_new;
}

node *rotate_left(node *tree){
    node *tree_new=tree->right;
    tree->right=tree_new->left;
    tree_new->left=tree;
    tree->height= balance_or_height("height",tree);
    tree_new->height= balance_or_height("height",tree_new);
    return tree_new;
}

node *balance(node *tree){
    if (tree->balance==-2){
        if (tree->left->balance>0) {
            tree->right = rotate_left(tree->left);
        }
        tree= rotate_right(tree);

    }
    if (tree->balance==2){
        if (tree->right->balance<0) {
            tree->right = rotate_right(tree->right);
        }
        tree= rotate_left(tree);
    }
    return tree;
}

void index_res(char *what, node *tree, int &i){
    if (tree== nullptr){
        return;
    }

    if (what=="index"){
        tree->index=i;
        i++; char *gg="index";
        index_res(gg, tree->left, i);
        index_res(gg, tree->right, i);

    } else if (what=="res"){
        cout << tree->key << " ";
        if (tree->left!= nullptr){
            cout << tree->left->index << " ";
        } else {
            cout << 0 << " ";
        }
        if (tree->right!= nullptr){
            cout << tree->right->index << " ";
        } else {
            cout << 0 << " ";
        }
        cout << "\n";

        int res=-1; char *gg="res";
        index_res(gg, tree->left, res);
        index_res(gg, tree->right, res);
    }
}

void balancing(node *tree){
    if (tree->right!= nullptr){
        balancing(tree->right);
    }
    if (tree->left!= nullptr){
        balancing(tree->left);
    }

    tree->height= balance_or_height("height", tree);
    tree->balance= balance_or_height("balance", tree);
}

void print(int n, node *array){
    cout << n << "\n";
    node *root= &array[0];
    balancing(root);
    root= balance(root);
    int index=1; char *what="index";
    index_res(what, root, index);
    int res=-1; char *what2="res";
    index_res(what2, root, res);
}

int main(){
    int n; cin >> n;
    if (n==0){
        return 0;
    }
    node *array= new node[n];
    for (int i=0; i<n; i++){
        int elem, left, right;
        cin >> elem >> left >> right;
        array[i].key=elem;
        if (left==0){
            array[i].left= nullptr;
        } else {
            array[i].left= &array[left-1];
        }
        if (right==0){
            array[i].right= nullptr;
        } else {
            array[i].right= &array[right-1];
        }
    }

    print(n, array);
    return 0;
}*/
