class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to positive long long
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        // Subtract divisor multiples from dividend
        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Double divisor until it exceeds dividend
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest possible multiple
            a -= temp;
            quotient += multiple;
        }

        // Apply the sign
        if (negative)
            quotient = -quotient;

        return (int)quotient;
    }
};