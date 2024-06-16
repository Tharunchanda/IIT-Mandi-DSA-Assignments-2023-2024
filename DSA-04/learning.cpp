#include <iostream>
#include <cstdlib>
#include <climits>
#include <queue>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left =nullptr;
        right = nullptr;
    }
};
//Arrays
class ArrayBinaryTree{
    private:
    int *tree;
    int capacity;
    int size;
    public:
    ArrayBinaryTree(int cap){
        capacity =cap;
        tree = new int[capacity];
        size =0;
    }
    void print(){
        for (int i=0;i<size;i++)
        {
            cout<<tree[i]<<" ";
        }
    }
    void insert(int val){
        if(size < capacity){
            tree[size++]=val;
            cout << "Inserted " << val << " into the binary tree." << endl;
        }}
        bool search (int val){
            for(int i=0;i<size;++i){
                if(tree[i]==val){
                    return true;
                }
            }
            return false;
        }
        void deleteNode(int val){
            int i;
            for(int i=0;i<size;++i){
                if(tree[i]==val)
                break;
            }
            if (i==size){
                cout<<"not found";
            }
            tree[i]=tree[--size];
        }
};
