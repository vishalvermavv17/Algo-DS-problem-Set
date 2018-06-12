#include <stdio.h>
#include <stdlib.h>



int top=-1;
struct node{
    struct node* left;
    struct node* right;
    char data;
}*nptr,*lc,*rc,*root;

struct node *a[20];

push(struct node* ptr)
{
    top++;
    a[top]=ptr;
}
struct node* pop()
{
 top--;
 return(a[top+1]);
}

void preorder(struct node* root)
{
    if(root)
    {
        printf("\n%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void main()
{
    int i;
    char s[20];
    printf("Enter the data \n");
    scanf("%s",s);
    while(s[i]!='\0')
    {
        if(s[i]=='(')
            i++;
        else if(s[i]>'a-1'&&s[i]<'z+1')
        {
            nptr=(struct node*)malloc(sizeof(struct node*));
            nptr->left='\0';
            nptr->right='\0';
            nptr->data=s[i];
            push(nptr);
        }
        else if(s[i]=='@')
            push('\0');
        else if(s[i]==')')
        {
            rc=pop();
            lc=pop();
            root=pop();
            root->left=lc;
            root->right=rc;
            push(root);
        }
        else if(s[i]=='#')
            root=pop();
    }
    preorder(root);
}
