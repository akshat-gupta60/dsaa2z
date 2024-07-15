class Solution {
public:
    stack<char>st;
    string removeKdigits(string num, int k) {
        
        int n=num.size();
         for (char c : num) {
        while (!st.empty() && st.top() > c && k > 0) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    
    // Remove remaining k digits from the end if k > 0
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    // Build the resulting number from the stack
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    
    // Remove leading zeros
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    
    return result.empty() ? "0" : result;
    }
};