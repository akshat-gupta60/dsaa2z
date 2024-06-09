class Solution {
public:
    double myPow(double a, long long b) {
        if (b == 0) return 1; // Base case: any number to the power of 0 is 1
        if (b < 0) return 1 / myPow(a, -b); // Handle negative exponents

        if (b % 2 == 0) {
            double half = myPow(a, b / 2);
            return half * half;
        } else {
            return a * myPow(a, b - 1);
        }
    }
};
