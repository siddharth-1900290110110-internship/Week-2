class Solution {
public:
    int trap(vector<int>& height) {
      
        int i,j,n,max=0,max2=0,pos,pos2,ans,k,total=0;
      
        n=height.size();
      
        int a[100001] = {0};
      
        for(i=0;i<n;i++)
          
        {
            if(height[i]>max)
            {
                max=height[i];
              
                pos=i;
            }
        }
        //cout<<pos<<" "<<max;
      
        if(max==0)
        {
            return 0;
          
        }
        // from start to max_height
        for(i=1;i<pos;i++)
          
        { max2=0;
            for(j=i-1;j>=0;j--)
              
            {
                if(height[j]>height[i]&&height[j]>max2)
                {
                    max2=height[j];
                  
                    pos2=j;
                }
            }
            if(max2!=0)
            {
              
                ans = (i-pos2)*height[pos2];
              
                for(k=pos2+1;k<i;k++)
                  
                {
                    ans-=(a[k]+height[k]);
                }
                ans-=height[i];
              
              
                a[i]=ans;
                total+=ans;
            }
        }
        // from end to max_height
      
        for(i=n-1;i>pos;i--)
        { max2=0;
         
            for(j=i+1;j<n;j++)
              
            {
                if(height[j]>height[i]&&height[j]>max2)
                {
                    max2=height[j];
                    pos2=j;
                }
            }
            if(max2!=0)
            {
                ans = (pos2-i)*height[pos2];
                for(k=pos2-1;k>i;k--)
                  
                {
                    ans-=(a[k]+height[k]);
                  
                }
                ans-=height[i];
              
                a[i]=ans;
              
                total+=ans;
            }
        }
        /*for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }*/
        return total;
        
    }
};
