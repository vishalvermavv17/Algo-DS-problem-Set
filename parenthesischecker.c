#include <stdio.h>
char a[10];
int push(int i);
int pop();
void main()
{
    int i,j=0;
    a[0]='(';
    a[1]='a';
    a[2]='+';
    a[3]='b';
    a[4]=')';
    for(i=0;i<5;i++)
    {
        switch(a[i])
        {
            case '(':   push(int j);
                        j++;
                        break;
            case ')':   pop(int j);
                        j--;
                        break;
        }
        if(j==0)
            printf("Parenthesis Marking Correct");
        else
        printf("Not correct Placing");
}
void push(int j)
{
    if(j>4)
        printf("Stack Full");
    else
    {
        a[j]='(';
        j++;
    }
}
void pop(int j)
{
    if(j>0)
        printf("Stack empty");
    else
    {
        j--;
    }
}
