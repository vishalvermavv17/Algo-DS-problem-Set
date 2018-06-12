#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char date[20],uname[20],bname[20],mno[15];
long int cost;
int n,i;

//function for writing entry of book into file

void write()
{
    FILE *fp;
    char dat[20],qnam[20],soque[20],mn[15];
    int nque1,nque2,nque3;
    long int cos;

    printf("\n Enter date(dd-mm-yyyy)\t:");
    scanf("%s",dat);
    printf("\nEnter the Question name\t:");
    scanf("%s",qnam);
    printf("\nEnter the source of question\t:");
    scanf("%s",soque);
    printf("\nEnter No.of quetions solved by: \t");
    printf("\nPranjil : ");
    scanf("%d",&nque1);
    printf("\nSaurav : ");
    scanf("%d",&nque2);
    printf("\nVishal : ");
    scanf("%d",&nque3);
    printf("\nTotal quettions solved \t:");
    fp=fopen("Secrete Record.txt","a");

    fprintf(fp,"\ndate: %s questionname: %s Sourceofquetion %s Pranjil: %d Saurav: %d Vishal: %d",dat,qnam,soque,nque1,nque2,nque3);
    printf("\n\tRecord written successfully!!!");
    fclose(fp);
}

//function to search record by date
void display(char da[20])
{
    char dat[20],qnam[20],soque[20],mn[15],snque1[15],snque2[15],snque3[15],sdat[20],sqnam[20],ssoque[20],smn[15];
    int nque1,nque2,nque3;
    FILE *fp;
    int res;

    fp=fopen("Secrete Record.txt","r");

    //while(fscanf(fp,"%s %s %s %s %ld\n",date,uname,bname,mno,&cost)!=EOF)
    while(fscanf(fp,"\n%s",dat)!=EOF)
    {
        res=strcmp(dat,da);
        if(res==0)
        {
            fscanf(fp,"%s",)
            printf("\n%s : %s",sqnam,qnam);
            printf("\n%s : %s",ssoque,soque);
            printf("\%s : %d",snque1,nque1);
            printf("\%s : %d",snque2,nque2);
            printf("\%s : %d",snque3,nque3);
        }
    }
    fclose(fp);
}

void main()
{
    char ch;
    char sdate[20];
    system("color FC");
    system("textxolor 0");

    do
    {
        system("cls");
        printf("\t ***SECRETE RECORD OF BFS @YMCA***\t\n");
        printf("\n Press 1 to create entry of new question record");
        printf("\n Press 2 to display list of questions on specific date");
        printf("\n Press any other key for exit");
        printf("\n Enter your choice:\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:write();
                    break;
            case 2:printf("Enter date(DD-MM-YYYY): ");
                    scanf("%s",sdate);
                    display(sdate);
                    break;
            default:printf("Invalid Selection");
        }
        getch();
    }
    while(ch>0&&ch<3);

}
