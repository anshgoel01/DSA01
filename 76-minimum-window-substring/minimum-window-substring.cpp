class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(256, 0);

        for(char c : t) {
            freq[c]++;
        }

        int left = 0;
        int cnt = 0;
        int minLength = INT_MAX;
        int startIndex = -1;

        for(int right = 0; right < s.size(); right++) {

            if(freq[s[right]] > 0) {
                cnt++;
            }

            freq[s[right]]--;

            while(cnt == t.size()) {

                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0) {
                    cnt--;
                }

                left++;
            }
        }

        if(startIndex == -1) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};