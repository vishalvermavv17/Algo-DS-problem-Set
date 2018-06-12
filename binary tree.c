#include<stdio.h>
#include<stdlib.h>

struct tree{
        struct tree *left;
        struct tree *right;
        char data;
    }*nptr,*lcptr,*rcptr,*subroot;

int top=0;
struct tree *a[100];

void postorder(struct tree *root)
{
    if(root)
    {
        printf("\npost%c",root->data );
        postorder(root->left);
        postorder(root->right);

    }
}

int push(struct tree* ptr)
{
   a[top]=ptr;
   top++;
   return 0;
}

struct tree* pop()
{
    top--;
    return a[top+1];
}

void main()
{
    int i;
    char s[100];


    printf("Enter the string");
    scanf("%s",s);
    for(i=0;s[i]!='#';i++)
    {
        switch(s[i])
        {
            case '(': break;
            case ')': rcptr=pop();
                      lcptr=pop();
                      subroot=pop();
                      subroot->right=rcptr;
                      subroot->left=lcptr;
                        printf("\nreturn %c",subroot->data);
                      push(subroot);
                      break;
            case '#': subroot=pop();
                      break;
            case '@': nptr= (struct tree *) malloc(sizeof(struct tree ));
                      nptr->data='\0';
                      nptr->left='\0';
                      nptr->right='\0';
                      push(nptr);
                      break;
            default : nptr= (struct tree *) malloc(sizeof(struct tree ));
                      nptr->data=s[i];
                      nptr->left='\0';
                      nptr->right='\0';
                      push(nptr);
                      break;
        }
    }
    subroot=pop;
    postorder(subroot);

}
