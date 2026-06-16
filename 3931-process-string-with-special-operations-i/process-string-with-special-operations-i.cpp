class Solution {
public:
    string processStr(string s) {
        string result;
        int n = s.size();

        for(int i = 0; i < n; i++){
            char ch = s[i];
        

        if(ch == '*'){
            if(result.size() != 0){
                result.pop_back();
            }
        }
        else if(ch == '#'){
                result += result;
        }
        else if(ch == '%'){
            reverse(result.begin(),result.end());
        } 
        else if(ch >= 'a' && ch <= 'z'){
            result.push_back(ch);
        }

    }
    return result;   
    }
};