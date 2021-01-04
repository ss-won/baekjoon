#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
struct TNode{
    TNode *left;
    TNode *right;
    int data;
    
    TNode(TNode *left, TNode *right, int data) {
        this->left = left;
        this->right = right;
        this->data = data;
    }
    
    void insert(int data) {
        if(this->data > data){
            if(this->left == NULL)
                this->left = new TNode(NULL, NULL, data);
            else
                this->left->insert(data);
        }
        else{
            if(this->right == NULL)
                this->right = new TNode(NULL, NULL, data);
            else
                this->right->insert(data);
        }
    }
    
    void postorder() {
        if(this->left != NULL){
            this->left->postorder();
        }
        if(this->right != NULL){
            this->right->postorder();
        }
        cout << this->data << "\n";
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int input;
    cin >> input;
    TNode* root = new TNode(NULL, NULL, input);
    while(1){
         cin >> input;
        if(cin.eof()) break;
         root->insert(input);
    }
    root->postorder();
    return 0;
}
