class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> freqMap;

        for(char& c : word){
            ++freqMap[c];
        }

        priority_queue<int> freqQueue;

        for(const auto& entry : freqMap){
            freqQueue.push(entry.second);
        }

        int totalPush = 0;
        int index = 0;


        while(!freqQueue.empty()){
            totalPush += (1+(index/8))*freqQueue.top();
            freqQueue.pop();
            index++;
        }
        return totalPush;
    }
};