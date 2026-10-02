class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> result;
        int n = s.length();

        for(int i = 0; i + 10 <= n; i++){
            string sub = s.substr(i,10);
        if(seen.count(sub)){
            result.insert(sub);
        }
        seen.insert(sub);
        }
        return vector<string>(result.begin(),result.end());
    }
};