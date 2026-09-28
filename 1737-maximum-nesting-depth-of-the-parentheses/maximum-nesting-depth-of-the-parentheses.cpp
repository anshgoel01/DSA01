class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int maxD = 0;
        int depth = 0;
        for(auto c : s){
            if(c == '('){
                depth++;
                maxD = max(maxD,depth);
            }else if(c == ')'){
                depth--;
            }else{
                continue;
            }
        }
        return maxD;
    }
};