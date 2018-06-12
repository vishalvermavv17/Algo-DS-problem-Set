#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<iostream>

using namespace std;
void draw2d(int,int [],int [],int,int);
int main()
{
int gd=DETECT,gm;
int x[20],y[20],x1[20],y1[20],tx=0,ty=0,i,fs;
initgraph(&gd,&gm,"");
printf("No of sides : ");
scanf("%d",&fs);
printf("Co-ordinates : ");
for(i=0;i<fs;i++)
{
printf("(x%d,y%d)",i,i);
scanf("%d%d",&x[i],&y[i]);
}
draw2d(fs,x,y,tx,ty);
printf("translation (x,y) : ");
scanf("%d%d",&tx,&ty);
while(1)
{

cleardevice();
printf("1. X Reflection\n\n2. Y Reflection\n\n3. Exit");
draw2d(fs,x,y,0,0);
switch(getche())
{
case '1':
for(i=0;i<fs;i++)
{
x1[i]=(tx+((x[i]-tx)*cos(M_PI))-((y[i]-ty)*sin(M_PI)));
y1[i]=y[i];
}
break;
case '2':
for(i=0;i<fs;i++)
{
x1[i]=x[i];
y1[i]=(tx+((y[i]-ty)*cos(M_PI))+((x[i]-tx)*sin(M_PI)));
}
break;
case '3':
closegraph();
exit(0);
}
draw2d(fs,x1,y1,tx,ty);
getch();
}
}
void draw2d(int fs,int x[20],int y[20],int tx,int ty)
{
int i;
for(i=0;i<fs;i++)
{
if(i!=(fs-1))
line(x[i]+tx,y[i]+ty,x[i+1]+tx,y[i+1]+ty);
else
line(x[i]+tx,y[i]+ty,x[0]+tx,y[0]+ty);
}
}
