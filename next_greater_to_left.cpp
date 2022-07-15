class Solution {
public:
    vector<int> nextGreaterToLeft(vector<int>& nums) {
        vector<int> ans,t;
      
        for(int i = 0;i<nums.size();i++){
          
            t.push_back(nums[i]);
        }
         for(int i = 0;i<nums.size();i++){
           
            t.push_back(nums[i]);
           
        }
        reverse(t.begin(),t.end());
        stack<int>st;
      
        for(int i = 0;i<t.size();i++){
          
            while(!st.empty() && st.top() <= t[i]){
                st.pop();
              
            }
            int res = (st.empty()) ? (-1) : (st.top());
          
            ans.push_back(res);
            st.push(t[i]);
          
        }
        reverse(ans.begin(),ans.end());
      
        int x = ans.size()/2;
        while(x--){
          
            ans.pop_back();
        }
        return ans;
    }
};
