class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
         stack<int>s;
        int n=arr.size();
        int rb[n];
        int lb[n];
        
        rb[n-1]=n;
        lb[0]=-1;
        
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(s.size()>0 && arr[i]<=arr[s.top()])
                s.pop();          
            rb[i]=(s.size()==0)?n:s.top();
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(s.size()>0 && arr[i]<=arr[s.top()])
                s.pop();          
            lb[i]=(s.size()==0)?-1:s.top();
           
            s.push(i);
        }
        int max_area=INT_MIN;
        for(int i=0;i<n;i++)
        { 
            int cur=arr[i]*(rb[i]-lb[i]-1);
            max_area=max(max_area,cur);
        }
        return max_area;
    }
};
