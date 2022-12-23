#include <iostream>
using namespace std;

struct node {
    node *left= nullptr;
    node *right= nullptr;
    string key;
    int grade, count_task, height;
};

struct ban {
    int height(node *root){
        if (root != nullptr) {
            return root->height;
        } else {
            return 0;
        }
    }

    int balancing(node *root){
        return height(root->right) - height(root->left);
    }

    void new_height(node *root){
        root->height = max(height(root->left), height(root->right)) + 1;
    }

    node *rotate_right(node *tree){
        node *tree_new=tree->left;;
        tree->left=tree_new->right;
        tree_new->right=tree;
        new_height(tree);
        new_height(tree_new);
        return tree_new;
    }

    node *rotate_left(node *tree){
        node *tree_new=tree->right;
        tree->right=tree_new->left;
        tree_new->left=tree;
        new_height(tree);
        new_height(tree_new);
        return tree_new;
    }

    node *balance(node *tree){
        new_height(tree);
        if (balancing(tree)==-2){
            if (balancing(tree->left)>0) {
                tree->left = rotate_left(tree->left);
            }
            return rotate_right(tree);

        }
        if (balancing(tree)==2){
            if (balancing(tree->right)<0) {
                tree->right = rotate_right(tree->right);
            }
            return rotate_left(tree);
        }
        return tree;
    }

    node *exists(node *find, string elem) {
        if (find == nullptr or find->key == elem) {
            return find;
        } else if (find->key > elem) {
            return exists(find->left, elem);
        } else {
            return exists(find->right, elem);
        }
    }

    node *insert(node *root, string key){
        if (root== nullptr){
            node *root2= new node;
            root2->key=key;
            root2->count_task=1;
            root2->grade=3;
            root2->height=1;
            return root2;
        }
        if (key<root->key){
            root->left= insert(root->left, key);
        } else if (key>=root->key){
            root->right= insert(root->right, key);
        }
        return balance(root);
    }

    node *check_elem (node* root, string elem) {
        node *new_node=exists(root, elem);
        if (new_node== nullptr) {
            return insert(root, elem);
        } else {
            if (new_node->count_task==1) {
                new_node->grade = 1;
                new_node->count_task+=1;
            } else if (new_node->count_task==2) {
                new_node->grade = 0;
                new_node->count_task+=1;
            }
            return root;
        }
    }

    void print(node *root, int n, string array1[], string array2[], string array3[]){
        int ans1=0, ans2=0, ans3=0;
        node *arr1, *arr2, *arr3;
        for (int i=0; i<n; i++){
            arr1= exists(root, array1[i]);
            arr2= exists(root, array2[i]);
            arr3= exists(root, array3[i]);
            ans1+=arr1->grade;
            ans2+=arr2->grade;
            ans3+=arr3->grade;
        }

        cout << ans1 << " " << ans2 << " " << ans3;
    }
} BAN;


int main() {
    int n; cin >> n;
    node *root= nullptr;
    string array1[n]; string array2[n]; string array3[n]; string key;

    for (int i=0; i<3; i++){
        for (int j=0; j<n; j++){
            if (i==0){
                cin >> array1[j];
                root= BAN.check_elem(root, array1[j]);
            } else if (i==1){
                cin >> array2[j];
                root= BAN.check_elem(root, array2[j]);
            } else if (i==2){
                cin >> array3[j];
                root= BAN.check_elem(root, array3[j]);
            }
        }
    }


    BAN.print(root, n, array1, array2, array3);
    return 0;
}
