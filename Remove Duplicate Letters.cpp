class Solution {
public:
    string removeDuplicateLetters(string s) {
      
         //Frequency of each character
      
        vector<int> count(26,0);
      
      
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
          
        }
        //Is the current char is visited
        vector<int> visited(26,0);
      
        //Result
        string ans="";
      
        //Iterating
        for(int i=0;i<s.length();i++){
          
            //Decrement the count
          
            count[s[i]-'a']--;
            if(!visited[s[i]-'a']){
              
                while(ans.length()>0 && ans.back()>s[i] && count[ans.back()-'a']>0){
                  
                    visited[ans.back()-'a']=0;
                  
                    ans.pop_back();
                }
                ans+=s[i];
              
                visited[s[i]-'a']=1;
            }
        }
        return ans;
    }
};
