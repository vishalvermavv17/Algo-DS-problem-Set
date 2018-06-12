//largest rectangle in histogram function

int largestRectangleArea(vector<int>& heights) {
        int ans=0,localAns=0;
        int n=heights.size();
        int i;
        stack<int> s;
        for(i=0; i<n; ){
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else{
                int top=s.top();
                s.pop();
                if(s.empty())
                    localAns=heights[top] * i;
                else
                    localAns=heights[top] * (i-s.top()-1);
                ans = max(ans, localAns);
            }
        }
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(s.empty())
                localAns=heights[top] * i;
            else
                localAns=heights[top] * (i-s.top()-1);
            ans = max(ans, localAns);
        }
    return ans;
    }