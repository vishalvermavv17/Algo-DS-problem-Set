class Solution {
public:
    int longestValidParentheses(string s) {
        int len= s.length();
        stack<int> st;
        vector<bool> v;

        for(int i=0; i<len; i++){
            if(s[i] == '(' ){
                st.push(i);
                v.push_back(0);
            }
            else {
                if(!st.empty()){

                    v.push_back(1);
                    int top=st.top();
                    v[top]=1;
                    st.pop();
                }
                else{
                    v.push_back(0);
                }
            }
        }

        int Max=0,cnt=0;
        for(int i=0; i<len; i++){

            if(v[i]){
                cnt++;
            }
            else{
                if(cnt > Max)
                    Max=cnt;
                cnt=0;
            }
        }
        if(cnt > Max)
            Max=cnt;
        return Max;
    }
};
