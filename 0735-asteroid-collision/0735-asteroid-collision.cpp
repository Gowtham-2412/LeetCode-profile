class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        
        for(int asteroid:asteroids) {
            bool alive = true;
            while(alive && !s.empty() && asteroid < 0 && s.top() > 0) {
                if(s.top() < abs(asteroid)) {
                    s.pop();
                } else if(s.top() == abs(asteroid)) {
                    alive = false;
                    s.pop();
                } else if(s.top() > abs(asteroid)) {
                    alive = false;
                }
            }
            if(alive) {
                s.push(asteroid);
            }
        }
        vector<int> result(s.size());
        for(int i = (int)s.size()-1; i>=0; i--) {
            result[i] = s.top();
            s.pop();
        }
        return result;
    } 
};