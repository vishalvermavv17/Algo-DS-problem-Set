#include<bits/stdc++.h>
using namespace std;

void formattedString(string rs, string ps)
{
    map<int,string> m,mr;
    bool visited[100]={false};
    int cntR=0,cnt=0;
    int j;

    for(int i=0; i<rs.length(); )
    {
        if(rs[i] != ' ')
        {
            j=i;
            string word;
            while(rs[j] != ' ' && j <rs.length())
            {
                word+=rs[j];
                j++;
            }
            mr[cntR++]=word;
            i=++j;
        }
        else
            i++;
    }

    int blankPos=0;
    for(int i=0; i<ps.length(); )
    {
        j=i;
        if(ps[j] != '{')
        {
            string word;
            while(ps[j] != ' ' && j < ps.length())
            {
                word+=ps[j];
                j++;
            }
            m[cnt++]=word;
            i=++j;
        }
        else
        {
            string word;
            int idx=0;
            bool isWord=false;
            j++;
            while(ps[j] != '}')
            {
                word+=ps[j];
                if(ps[j] < '0' && ps[j] > '9')
                {
                    isWord=true;

                }
                idx=(idx*10)+ps[j]-48;
                j++;
            }
            if(ps[j-1] == '{')
            {
                if(blankPos < cntR)
                {
                     m[cnt++]=mr[blankPos];
                        blankPos++;
                }
            }
            else if(isWord)
                m[cnt++]=word;
            else
            {
                if(idx < cntR)
                    m[cnt++]=mr[idx];

            }
            i=j+2;
        }

    }

    for(int i=0; i<cnt; i++)
        cout<<m[i]<<" ";
}


int main()
{
    string ra,pa;
    getline(cin,ra);
    getline(cin,pa);
    formattedString(ra,pa);
}
