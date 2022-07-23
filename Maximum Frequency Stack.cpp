class FreqStack {
public:
    
    unordered_map<int,int> freq; // freq map
    unordered_map<int,stack<int>> group_st; 
  
    int max_freq = 0; // max_freq
    
    FreqStack() {}
    
    void push(int val)
    {
        freq[val]++; 
      
        max_freq = max(max_freq,freq[val]); 
      
        group_st[freq[val]].push(val); 
    }
    
    int pop()
    {
        int top_max = group_st[max_freq].top(); 
      
        group_st[max_freq].pop();
      
        freq[top_max]--; // 
        
		
        if(group_st[max_freq].size()==0)
            max_freq--;
        
        return top_max; // 
    }
};
