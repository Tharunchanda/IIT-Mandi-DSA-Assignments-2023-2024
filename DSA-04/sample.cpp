#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};
class BinaryTreeArray{
    private:
    vector<int> tree;
    public:
    BinaryTreeArray(){}
    void insert(int val){
        tree.push_back(val);
    }
    bool search(int val){
        for (int node_val : tree){
            if(node_val ==val){
                return true;
            }
        }return false;
    }
    void remove(int val){
        for(int i=0;i<tree.size();i++){
            if(tree[i]==val){
                tree[i]=tree.back();
                tree.pop_back();
                return;
            }
        }
    }
    void display(){
        cout<<"Binary Tree: ";
        for(int node_val:tree){
            cout<<node_val<<" ";
        }
        cout<<endl;
    }
};
class BinaryTreeLinked{
    private:
    TreeNode* root;
    TreeNode* findMin(TreeNode* node){
        while(node->left != nullptr){
            node=node->left;
        }return node;
    }
    void inorder(TreeNode* node){
        if(node ==nullptr){
            return;
        }  
        inorder(node->left);
        cout<<node->val<<" ";
        inorder(node->right);
    }
    public:
    TreeNode* insert(TreeNode* node,int val){
        if(node == nullptr){
            return new TreeNode(val); }
        if(val<node->val){
            node->left=insert(node->left,val);}
        else if (val>node->val){
            node->right=insert(node->right,val);}
        return node;
    }
    bool search(TreeNode* node,int val){
        if(node == nullptr){
            return false;
        }
        if(node->val == val){
            return true;
        }
        if(val<node->val){
            return search(node->left,val);
        }
        if(val > node->val){
            return search(node->right,val);
        }
    }
    TreeNode* remove(TreeNode* node , int val){
        if(node == nullptr){
            return nullptr;
        }
        if(val <node-> val){
            node -> left = remove(node -> left,val);
        }else if(val > node -> val){
            node -> right = remove(node -> right,val);
        }else{
            if(node->left == nullptr){
                TreeNode* temp = node 
            }
        }
    }

};





int main(){
    BinaryTreeArray tree;
    return 0;
};
