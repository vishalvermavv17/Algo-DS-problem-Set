class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.length();
        int Max=0,left=0,right=0;
        for(int i=0; i<len; i++){
            if(s[i] == '(' ){
                left++;
            }
            if(s[i] == ')' ){
                right++;
                if(left == right)
                    Max=max(Max,left+right);
                else if(right > left){
                    left=0;
                    right=0;
                }
            }
        }
        left=right=0;
        for(int i = len-1; i>=0; i--){
            if(s[i] == ')' ){
                right++;
            }
            if(s[i] == '(' ){
                left++;
                if(left == right ){
                    Max=max(Max,left+right);
                }
                else if(left > right){
                    left=0;
                    right=0;
                }
            }
        }
        return Max;
    }
};
