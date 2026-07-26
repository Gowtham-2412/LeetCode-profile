class Solution {
public:
    long calculate(string s) {
        long result = 0;
        int sign = 1;
        long number = 0;
        stack<int> answer;
        for(char c:s) {
            if(c == ' ') {
                continue;
            }
            if(isdigit(c)) {
                number = number * 10 + (c-'0');
            }
            if(c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }
            if(c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            if(c == '(') {
                answer.push(result);
                answer.push(sign);
                result = 0;
                sign = 1;
            }
            if(c == ')') {
                result += sign * number;
                number = 0;
                result *= answer.top();
                answer.pop();
                result += answer.top();
                answer.pop();
            }
        }
        result += sign * number;
        
        return result;
    } 
};