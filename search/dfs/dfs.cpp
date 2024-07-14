#include<bits/stdc++.h>
using namespace std;

struct nod_{
    int val;
    nod_ *left=NULL;
    nod_ *right=NULL;
    bool checking=false;  //khi = false thì chưa đi qua node này, true là đi qua r
};

typedef nod_ * node;
class linklist{
    public:
    node root=NULL;
    linklist(){};
    ~linklist(){};
    node create_(int x){
        node node_=new nod_;
        node_->val=x;
        return node_;
    }
    void add_node (node P,int x){   //ds lk dạng cây chỉ có hướng trái or phải
        node res_node=create_(x);
        if(P==NULL) {
            this->root =res_node;
            return;
        }
        if (P->left==NULL){
            P->left=res_node;
            return;   //hàm void nên chỉ return lại return
        }
        if (P->right==NULL){
            P->right=res_node;
            return;   //hàm void nên chỉ return lại return
        }
    }
    void dfs(node P){
        if(P==NULL) return;
        if (P-> checking==false){
            cout<<"node: "<<P->val<<endl;
            dfs(P->left);    
            dfs(P->right);
        }
    }
    
};
typedef linklist *l_list;
int main(){
    l_list res_list=new linklist();  //nhập cây trong vở
    res_list->add_node(NULL,1);
    res_list->add_node(res_list->root,2);
    res_list->add_node(res_list->root,3);
    res_list->add_node(res_list->root->left,4);
    res_list->add_node(res_list->root->right,9);
    res_list->add_node(res_list->root->left,6);
    res_list->add_node(res_list->root->right,7);

    res_list->dfs(res_list->root);
    return 0;
}