class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>ans;
        for(auto i:grid)
        {
            for(auto j:i)
            {
              ans.push_back(j);
            }
        }
        sort(ans.begin(),ans.end());
        int size=ans.size()-1;
        int l=0;
        int mid=size/2;
        for(int i=0;i<ans.size();i++)
        {
            int diff=abs(ans[mid]-ans[i]);
            if(diff%x!=0)return-1;
            else l+=diff/x;
        }
        return l;        
    }
};