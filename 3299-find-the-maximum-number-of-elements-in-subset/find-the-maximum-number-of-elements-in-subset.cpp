class Solution {
public:
    int maximumLength(vector<int>& nums) {
            unordered_map<long long, int>freq;
            int ones=0;
            for(int num:nums)
            {
               freq[num]++;
               if(num==1)ones++;
            }

            // handle one separetally.
            int ans=(ones%2==0)?ones-1:ones;
            freq.erase(1LL);

            // here we are access one by one the element of the hash map
            for(auto & it:freq)
            {
                long long num=it.first;
                long long curr=num;
                int count=0;

                while(freq.count(curr))
                {
                    if(freq[curr]>=2)
                    {
                        count+=2;
                    }
                    else
                    {
                        count+=1;
                        break;
                    }
                    curr=curr*curr;
                }
                // length must be add.
                if(count%2==0)
                {
                    count--;   
                }
                ans=max(ans,count);
            
            }             
            return ans ;  
    }
};