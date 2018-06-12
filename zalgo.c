#include <stdio.h>
#include <string.h>
int main()
{
    char s1[100],p[100],z[1000],s[200];
    int i,k1,left=0,right=0,k,count=0,p_len,s_len;
    printf("Enter the string");
    scanf("%s",s1);
    printf("enter the pattern");
    scanf("%s",p);
    for(i=0,k=0;p[i]!='\0';i++,k++)
        s[k]=p[i];
    s[k]='$';
    k++;
    for(i=0;s1[i]!='\0';i++,k++)
        s[k]=s1[i];
    s_len=strlen(s);
    p_len=strlen(p);


    for(k=1;k<s_len;k++)
    {
        if(k>right)
        {
        left=right=k;
        while(right<s_len&&s[right]==s[right-left])
            right++;
        z[k]=right-left;
        right--;
        }
        else
        {
            k1=k-left;
            if(z[k1]<right-k+1)
                z[k]=z[k1];

            else
            {
                left=k;
                while(right<s_len&&s[right]==s[right-left])
                    right++;

                z[k]=right-left;
                right--;
            }

        }

    }
    for(k=1;k<s_len;k++)
        if(z[k]>=p_len)
            count++;
    if(count>0)
        printf("pattern exist %d times in a string",count);
    else
        printf("does not exist");
    return 0;
}
