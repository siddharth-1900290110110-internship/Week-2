class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> ans(nums1.size(), -1); 
      
        for (int i = nums2.size() - 1; i >= 0; --i) {
          
            while(!st.empty() && nums2[i] >= nums2[st.top()]) {  
                st.pop();
              
            }
            if (!st.empty()) { 
              
                 mp[nums2[i]] = nums2[st.top()];
            }
          
            st.push(i);  
        for (int i = 0; i < nums1.size(); ++i) {
          
            if (mp.find(nums1[i]) != mp.end()) {
              
                ans[i] = mp[nums1[i]];
            }
        }
        return ans;
        
    }
};
