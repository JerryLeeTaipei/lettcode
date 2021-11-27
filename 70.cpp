#include <iostream>

using namespace std;

int leaf_count=0;

class Tree {
    int count;
    Tree *node_1;
    Tree *node_2;
public:
    Tree(int count) {
        this->count = count;
        this->node_1 = NULL;
        this->node_2 = NULL;
    }
    void insert_node_1(int count) {
        this->node_1 = new Tree(count+1);
    }
    void insert_node_2(int count) {
        this->node_2 = new Tree(count+2);
    }
    void build_tree(int n){
        cout << "current count:" << this->count << " < " << n << endl; 
        if ( this->count < n ) {
            cout << "-1\n"; 
            this->insert_node_1(this->count);
            this->node_1->build_tree(n);
            if ( (this->count +2 ) <= n ) {
                cout << "-2\n"; 
                this->insert_node_2(this->count);
                this->node_2->build_tree(n);
            }
        }else {
            leaf_count++;
            cout << "\tLeaf:" << leaf_count << endl;
            if ( leaf_count > 14930352 )
                cout << "###\n";

        }
    }  
    void get_leaf_count(int n, int *count){
        if ( this->count != n ) {
            if ( this->node_1 )
                this->node_1->get_leaf_count(n, count);
            if ( this->node_2 )
                this->node_2->get_leaf_count(n, count);        
        } else
            *count = *count +1;
    }    
};


class Solution {
public:
    int climbStairs(int n) {
        Tree *root= new Tree(0);
        int count=0;

        root->build_tree(n);
        root->get_leaf_count(n, &count);
        return count;
    }
};
int main(){
    Solution test;

    cout <<  test.climbStairs(35) ;

    return 0;
}
