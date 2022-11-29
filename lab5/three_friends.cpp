#include <iostream>
using namespace std;

struct node{
    string data;
    node *left= nullptr;
    node *right= nullptr;
    node *parent= nullptr;
    int count_task=0;
    int grade=3;
};

struct ban{
    node *root= nullptr;

    node *exists(node *find, string elem){
        if (find==nullptr or elem==find->data){
            return find;
        }
        if (elem < find->data){
            return exists(find->left, elem);
        } else {
            return exists(find->right, elem);
        }
    }


    void insert(string elem){
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


    node *cnt(node *root, string arr1[], string arr2[], string arr3[], int n){
        for (int i=0; i<n; i++){
            if (exists(root,arr1[i])){
                exists(root,arr1[i])->count_task+=1;
            }
            if (exists(root,arr2[i])){
                exists(root,arr2[i])->count_task+=1;
            }
            if (exists(root,arr3[i])){
                exists(root,arr3[i])->count_task+=1;
            }
        }
        return root;
    }


    node *help(node *root){

        if (root == nullptr)
        {
            return root;
        }
        if (root->count_task==1){
            exists(root,root->data)->grade-=0;
        } else if (root->count_task==2){
            exists(root,root->data)->grade-=2;
        } else if (root->count_task==3){
            exists(root,root->data)->grade-=3;
        }
        help(root->left);   //рекурсивный вызов левого поддерева
        help(root->right);  //рекурсивный вызов правого поддерева
        return root;
    }


    void print(string array1[], string array2[], string array3[], int n){
        int res1, res2, res3;
        int ans1=0, ans2=0, ans3=0;
        cnt(root, array1, array2, array3, n);
        help(root);
        for (int i=0; i<n; i++){
            res1 = exists(root,array1[i])->count_task;
            if (res1==1){
                ans1+=3;
            } else if (res1==2){
                ans1+=1;
            } else {
                ans1+=0;
            }
        }
        cout << ans1 << " ";
        for (int i=0; i<n; i++){
            res2 = exists(root,array2[i])->count_task;
            if (res2==1){
                ans2+=3;
            } else if (res2==2){
                ans2+=1;
            } else {
                ans2+=0;
            }
        }
        cout << ans2 << " ";
        for (int i=0; i<n; i++){
            res3 = exists(root,array3[i])->count_task;
            if (res3==1){
                ans3+=3;
            } else if (res3==2){
                ans3+=1;
            } else {
                ans3+=0;
            }
        }
        cout << ans3 << " ";
    }
}ban;


int main(){
    int n; cin >> n;
    string array1[n];
    for (int i=0; i<n; i++){
        cin >> array1[i];
    }
    string array2[n];
    for (int i=0; i<n; i++){
        cin >> array2[i];
    }
    string array3[n];
    for (int i=0; i<n; i++){
        cin >> array3[i];
    }

    for (int i=0; i<n; i++){
        ban.insert(array1[i]);
    }

    for (int i=0; i<n; i++){
        ban.insert(array2[i]);
    }

    for (int i=0; i<n; i++){
        ban.insert(array3[i]);
    }

    ban.print(array1, array2, array3, n);
}
