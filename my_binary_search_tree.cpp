#include<stdio.h>
#include<stdlib.h>
#define MALLOC(t,type,n) t=(type *)(malloc(sizeof(type)*n))
struct node
{
    int data;
    struct node *l;
    struct node *r;
};
typedef struct node NODE;
void search(NODE *t,NODE *temp);
void ins(NODE **root,int d);
void inorder(NODE *t);
void preorder(NODE *t);
void postorder(NODE *t);
int smallest(NODE *t);
int largest(NODE *t);
void del1(NODE *t,NODE *par,NODE **root);
void search1(NODE *t,int d,NODE *par,NODE **root);
void del(NODE **root,int d);
int main()
{
    int choice,d;
    NODE *root=NULL;
    while(1)
    {
        printf("1.insert\n2.delete\n3.inorder\n4.preorder\n5.postorder\n6.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element\n");
                    scanf("%d",&d);
                    ins(&root,d);
                    break;
            case 2:printf("Enter the element\n");
                    scanf("%d",&d);
                    del(&root,d);
                    break;
            case 3:inorder(root);
                    break;
            case 4:preorder(root);
                    break;
            case 5:postorder(root);
                    break;
            case 6:return 0;
        }
    }
return 0;
}
void search(NODE *t,NODE *temp)
{
    if(t->data>temp->data && t->l!=NULL)
        search(t->l,temp);
    else if(t->data>temp->data && t->l==NULL)
        t->l=temp;
    else if(t->data<temp->data && t->r!=NULL)
        search(t->r,temp);
    else if(t->data<temp->data && t->r==NULL)
        t->r=temp;
}
void ins(NODE **root,int d)
{
    NODE *temp;
    MALLOC(temp,NODE,1);
    temp->data=d;
    temp->l=temp->r=NULL;
    if(*root==NULL)
        *root=temp;
    else
        search(*root,temp);
}
void inorder(NODE *t)
{
    if(t==NULL)
        return;
    inorder(t->l);
    printf("%d ",t->data);
    inorder(t->r);
}
void preorder(NODE *t)
{
    if(t==NULL)
        return;
    printf("%d ",t->data);
    preorder(t->l);
    preorder(t->r);
}
void postorder(NODE *t)
{
    if(t==NULL)
        return;
    postorder(t->l);
    postorder(t->r);
    printf("%d ",t->data);
}
int smallest(NODE *t)
{
    if(t->l!=NULL)
        return(smallest(t->l));
    else
        return(t->data);
}
int largest(NODE *t)
{
    if(t->r!=NULL)
        return(largest(t->r));
    else
        return(t->data);
}
void del1(NODE *t,NODE *par,NODE **root)
{
    int k;
    NODE *t2;
    if(t->l==NULL && t->r==NULL)
    {
        if(par->l==t)
            par->l=NULL;
        else
            par->r=NULL;
    }
    else if(t->r==NULL)
    {
        if(par==t)
        {
            *root=t->l;
            par=*root;
        }
        else if(par->l==t)
            par->l=t->l;
        else
            par->r=t->l;
    }
    else if(t->l==NULL)
    {
        if(par==t)
        {
            *root=t->r;
            par=*root;
        }
        else if(par->r==t)
            par->r=t->r;
        else
            par->l=t->r;
    }
    else
    {
        t2=*root;
        if(t->r!=NULL)
            k=smallest(t->r);
        else
            k=largest(t->l);
        search1(*root,k,par,root);//still not clear why this is used
        t->data=k;
    }
}
void search1(NODE *t,int d,NODE *par,NODE **root)
{
    if(d>t->data)
    {
        par=t;
        search1(t->r,d,par,root);
    }
    else if(d<t->data)
    {
        par=t;
        search1(t->l,d,par,root);
    }
    else
        del1(t,par,root);
}
void del(NODE **root,int d)
{
    NODE *par;
    if(*root==NULL)
        return;
    par=*root;
    search1(*root,d,par,root);
}
