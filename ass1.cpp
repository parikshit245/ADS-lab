#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int key;
        string value;
        Node* left;
        Node* right;

    Node(int k, string v){
        key = k;
        value = v;
        left = right = nullptr;
    }
};

class Dict{
    Node* root;

    Node* insertNode(Node* root, int k, string v){

        if(root == nullptr){
            return new Node(k, v);
        }

        if(k < root->key){
            root->left = insertNode(root->left, k, v);
        }else if(k > root->key){
            root->right = insertNode(root->right, k, v);
        }else{
            root->value = v;
        }

        return root;
    }

    void inorder(Node* root){
        if(root == nullptr){
            return;
        }

        inorder(root->left);
        cout<<root->key<<" - "<<root->value<<"\n";
        inorder(root->right);
    }


    public:
    Dict(){
        root = nullptr;
    }

    void insert(int k, string v){
        root = insertNode(root,k, v);
    }

    void display(){
        inorder(root);
    }

    void deleteNode(int k){
        
    }
};


int main(){
    Dict dictionary;
    int choice;
    int key;
    string value;
    do{
         cout << "\nMenu:\n";
        cout << "1. Insert Word\n";
        cout << "2. display Word\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            cout<<"Enter key to be inserted: ";
            cin>>key;
            cout<<"\nEnter word to be inserted: ";
            cin>>value;

            dictionary.insert(key, value);
            break;
        
        case 2:
            cout<<"The dictionary is: "<<endl;
            dictionary.display();

        default:
            cout<<"\nhug u zigga"<<endl;
            break;
        }
    }while(choice != 2);

    return 0;
}
