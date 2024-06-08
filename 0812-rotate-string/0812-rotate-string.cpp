class Solution {
public:
    bool rotateString(string s, string goal) {
        int n =s.size();

        if(s==goal) return true;
        for(int i=0;i<n;i++){
            char a= goal[0];
            goal.erase(goal.begin());
            goal.push_back(a);

            if(s==goal) return true;
        }
        return false;
    }
};