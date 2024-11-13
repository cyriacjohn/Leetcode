class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int asteroid: asteroids) {
            bool exploded  = false;
            while(!stk.empty() && asteroid<0 && stk.top()>0 ) {
                if(abs(asteroid) > stk.top()) {
                    stk.pop();
                }
                else if(abs(asteroid) == stk.top()){
                    stk.pop();
                    exploded = true;
                    break;
                }
                else {
                    exploded = true;
                    break;
                }
            }
            if(!exploded) {
                stk.push(asteroid);
            }
        }
         vector<int> result(stk.size());
    for (int i = stk.size() - 1; i >= 0; i--) {
        result[i] = stk.top();
        stk.pop();
    }
    return result;
}
    };