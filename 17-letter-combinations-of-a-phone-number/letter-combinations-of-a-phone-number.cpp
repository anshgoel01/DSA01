class Solution {
public:
    vector<string> ans;

    void backtrack(int index,
                   string& digits,
                   vector<string>& mp,
                   string& curr) {

        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {

            curr.push_back(ch);

            backtrack(index + 1,
                      digits,
                      mp,
                      curr);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        string curr;

        backtrack(0, digits, mp, curr);

        return ans;
    }
};