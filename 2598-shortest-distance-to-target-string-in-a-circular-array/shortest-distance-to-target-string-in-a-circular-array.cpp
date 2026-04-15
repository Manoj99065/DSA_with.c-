class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int size=words.size();
        int minimum=INT_MAX;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==target)
            {
                int k=abs(i-startIndex);
                minimum=min(minimum , min(k,size-k));
            }  
        }
       return minimum==INT_MAX  ? -1:minimum; 
    }
};

