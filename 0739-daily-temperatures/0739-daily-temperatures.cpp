class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> dayIndices;

        for(int i = 0; i<temperatures.size(); i++) {
            while(!dayIndices.empty() && temperatures[i] > temperatures[dayIndices.top()]) {
                int previous = dayIndices.top();
                dayIndices.pop();
                answer[previous] = i - previous;
            }
            dayIndices.push(i);
        }
        return answer;
    };
};