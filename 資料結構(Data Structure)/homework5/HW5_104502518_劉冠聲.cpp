#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#define isfull(temp) (!(temp))
using namespace std;
typedef struct tree2 *pointer;
typedef struct tree2
{
    pointer left;
    int data;
    pointer right;
};

pointer search2(pointer tree,int key)
{
    while(tree)
    {
        if(key==tree->data)
        {
            return NULL;
        }
        if(key<tree->data)
        {
            if((tree->left)!=NULL)
            {
                tree=tree->left;
            }
            else
            {
                return tree;
            }
        }
        else
        {
            if((tree->right)!=NULL)
            {
                tree=tree->right;
            }
            else
            {
                return tree;
            }
        }
    }
}

void insertnode(pointer *node,int num)
{
    pointer ptr,temp;
    temp=search2(*node,num);
    if((temp)||(!(*node)))
    {
        ptr=(pointer)malloc(sizeof(tree2));
        if(isfull(ptr))
        {
            cout<<"沒有空間哈哈哈笑你~"<<endl;
            exit(1);
        }
        ptr->data=num;
        ptr->left=ptr->right=NULL;

        if(*node)
        {
            if(num<temp->data)
            {
                temp->left=ptr;
            }
            else
            {
                temp->right=ptr;
            }
        }
        else
        {
            (*node)=ptr;
        }
    }
}

/*pointer search1(pointer tree,int key)
{
    while(tree)
    {
        if(key==tree->data)
        {
            return NULL;
        }
        if(key<tree->data)
        {
            if((tree->left->data)==key){
                return tree;
            }
            else{
                tree=tree->left;
            }
        }
        else
        {
            if((tree->right->data)==key){
                return tree;
            }
            else{
                tree=tree->right;
            }
        }
    }
}

void deletenode(pointer *node,int num){
    pointer temp;
    temp=search1(*node,num);
    if(temp==NULL){
        temp=*node;

    }
    else{
        if(num<(temp->data)){

        }
        else{

        }
    }

}*/

void preorder(pointer tree)
{
    cout<<tree->data<<" ";
    if(tree->left)
    {
        preorder(tree->left);
    }
    if(tree->right)
    {
        preorder(tree->right);
    }
}

void inorder(pointer tree)
{
    if(tree->left)
    {
        inorder(tree->left);
    }
    cout<<tree->data<<" ";
    if(tree->right)
    {
        inorder(tree->right);
    }
}

void postorder(pointer tree)
{
    if(tree->left)
    {
        postorder(tree->left);
    }

    if(tree->right)
    {
        postorder(tree->right);
    }
    cout<<tree->data<<" ";
}

int main()
{
    pointer root=NULL;
    int n;
    ifstream input("input5.txt");
    while(input>>n)
    {
        insertnode(&root,n);
    }
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl<<endl;

    /*cout<<"delete num : ";
    cin>>n;
    deletenode(&root,n);

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;*/

    return 0;
}
