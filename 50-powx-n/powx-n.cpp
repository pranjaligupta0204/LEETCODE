class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1.0;

        // If power is negative, convert it and take reciprocal later
        bool isNegative = (n < 0);
        n = llabs(n);

        double result = 1.0;

        while(n > 0){
            if(n & 1)   // If last bit of n is 1, multiply result
                result *= x;

            x = x * x;  // Square the base
            n >>= 1;    // Divide power by 2
        }

        return isNegative ? 1.0 / result : result;
    }
};
