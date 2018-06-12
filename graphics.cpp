#include<graphics.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, "C:\\tc\\bgi");
    int a[100];
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>a[i];

    int start;
    cin>>start;
    line(10,100,a[0],90);
    int t=90;



    getch();
}
