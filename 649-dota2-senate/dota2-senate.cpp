class Solution {
public:
    queue<int>rediant,dire;
    string predictPartyVictory(string senate) {
        int size=senate.length();
        for(int i=0;i<senate.length();i++)
        {
         if(senate[i]=='R')
         {
            rediant.push(i);
         }
         else
         {
            dire.push(i);
         }
        }

       if(rediant.size()==0)
       {
        return "Dire";
       } 
       else if(dire.size()==0)
       {
        return "Radiant";
       }

       while(!rediant.empty() && ! dire.empty())
       {
        if(rediant.front()<dire.front())
        {
            int val=rediant.front();
            dire.pop();
            int val1=val+size;
            rediant.push(val1);
            rediant.pop();
        }

        else
        {
            rediant.pop();
            int val=dire.front();
            int val1=val+size;
            dire.pop();
            dire.push(val1);
        }
       }

    return rediant.size()==0  ? "Dire":"Radiant";
    }
};