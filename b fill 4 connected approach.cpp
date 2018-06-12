







/**** WAP to implement area filling 8 connected approach algo ****/
#include <stdio.h>
#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void floodFill8(int sx, int sy)
{
    if(getpixel(sx,sy) != 5 && getpixel(sx,sy) != 8 )
    {
        putpixel(sx,sy,8);
        floodFill8(sx+1,sy);
        floodFill8(sx+1,sy+1);
        floodFill8(sx,sy+1);
        floodFill8(sx-1,sy+1);
        floodFill8(sx-1,sy);
        floodFill8(sx-1,sy-1);
        floodFill8(sx,sy-1);
        floodFill8(sx+1,sy-1);
    }
    return;
}

int main()
{
    int gdriver=DETECT, gmode,errorcode;
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(1,1,2);
    outtextxy(35,25,"Area Filling by 8 Connected approach");
    setcolor(0);
    int x1,y1,x2,y2;
    setcolor(5);
    cout<<"Enter Rectangle Coordinates:\t";
    cin>>x1>>y1>>x2>>y2;
    rectangle(x1,y1,x2,y2);

    int sx,sy;
    cout<<"Enter Seed Pixel\n";
    cin>>sx>>sy;
    setcolor(RED);
    floodFill8(sx,sy);

    getch();
    closegraph();
}
