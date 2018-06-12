
// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    //cin.tie(NULL);


    char s[1000000];
    scanf("%s",s);
    long int len= strlen(s);

    long int x,y,cnt=0,nlen,mid;
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){

            bool flag=1;
            int nlen=j-i+1;

            mid=nlen/2;
            if(nlen%2){
                for(x=i; x<=j  && flag; x++){
                    if(s[x] != s[j])
                        flag=0;
                    if(x == i+mid-1)
                        x++;
                }

                if(flag)
                    cnt++;
            }
            else{
                for(x=i; x<=j && flag; x++){
                    if(s[x] != s[j])
                        flag=0;


                }
                if(flag)
                    cnt++;
            }
        }

    }
    printf("%ld",cnt);
    return 0;
}
