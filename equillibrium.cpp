#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node* left=NULL;
    Node* right = NULL;
    Node(){
        
    }
};

int main(){
    Node* curr;
    Node* root;
    if(curr->left == NULL){
        curr = curr->right;
    }
    else{
        Node* pred = curr->left;
        while(pred->right){
            pred = pred->right;
        }
    }
}