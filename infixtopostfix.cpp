#include <iostream>
#include <stack>

int main()
{
    int i,t;
    char s[400];
    std::stack <char> st;

    std::cin>>t;
    while(t--)
    {
        std::cin>>s;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]>='a' && s[i]<='z')
                std::cout<<s[i];
            else if(s[i]=='+')
            {
                while(st.top()>='*')
                {
                    std::cout<<st.top();
                    st.pop();
                }
                st.push('+');
            }
            else if(s[i]=='-')
            {
                while(st.top()>='-' || st.top()=='*')
                {
                    std::cout<<st.top();
                    st.pop();
                }
                st.push('-');
            }
            else if(s[i]=='*')
            {
                while(st.top()>'-' || st.top()=='*')
                {
                    std::cout<<st.top();
                    st.pop();
                }
                st.push('*');
            }
            else if(s[i]=='/')
            {
                while(st.top()>='/')
                {
                    std::cout<<st.top();
                    st.pop();
                }
                st.push('/');
            }
            else if(s[i]=='^')
            {
                while(st.top()=='^')
                {
                    std::cout<<st.top();
                    st.pop();
                }
                st.push('^');
            }
            else
            {
                while(st.top()!='(')
                {
                    std::cout<<st.top();
                    st.pop();
                }
                st.pop();
            }
        }
        std::cout<<"\n";
    }

    return 0;
}
