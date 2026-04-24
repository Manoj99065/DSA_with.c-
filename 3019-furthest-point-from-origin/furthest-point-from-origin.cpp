// class Solution {
// public:
//     int furthestDistanceFromOrigin(string moves) {
//         int ans=0;
//         for(int i=0;i<moves.size();i++)
//         {
//             if(moves[i]=='L' || moves[i]=='_')
//             {
//                ans++;
//                continue;
//             }
           
//             ans--;
//         }
//         return abs(ans);
//     }
// };


class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0 ,right=0, blank=0;
        for(char i : moves)
        {
            if(i=='L')left++;
            else if(i=='R')right++;
            else blank++;
        }
        int result=abs(left-right)+blank;
        return result;
    }
};