#include<iostream>
#include<queue>
using namespace std;


class node{
public:
  int data;
  node* left;
  node* right;


    node(int d){
        this->data = d;
        left = right = nullptr;
    }
};


node* insertInTree(node* root, int n){
    cout<<"Enter data: ";
    int data;
    cin>>data;

    if(data == -1){
        return nullptr;
    }

    if(data<n){
        root->left = insertInTree(root->left, n);
    }else{
        root->right = insertInTree(root->right, n);
    }
    return root;
}


void preOrder(node* root){
    if(root == nullptr){
        return;
    }


    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(node* root){
    if(root == nullptr){
        return;
    }


    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


void postOrder(node* root){
    if(root == nullptr){
        return;
    }


    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}




void levelOrder(node* root){
    queue<node* > q;
    q.push(root);
    q.push(nullptr);


    while(!q.empty()){
        node* temp = q.front();
        q.pop();


        if(temp == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    node* root = nullptr;
    cout<<"Enter root data: ";
    int n;
    cin>>n;
    root->data = n;
    root = insertInTree(root, n);
    // cout<<"\npreorder traversal is: "<<endl;
    // preOrder(root);


    cout<<"\ninOrder traversal is: "<<endl;
    inOrder(root);


    // cout<<"\npostOrder traversal is: "<<endl;
    // postOrder(root);
    //5 7 8 -1 -1 6 10 -1 -1 -1 9 -1 -1
    // cout<<endl<<endl;
    // levelOrder(root);
    return 0;
}
