class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1000000007;
        // Numbers at even indices can be [0, 2, 4, 6, 8] -> 5 choices
        // Numbers at odd indices can be [2, 3, 5, 7] -> 4 choices
        
        long long even_count = (n + 1) / 2; // count of even positions
        long long odd_count = n / 2;        // count of odd positions
        
        long long even_result = power(5, even_count, MOD);
        long long odd_result = power(4, odd_count, MOD);
        
        return (even_result * odd_result) % MOD;
    }
    
private:
    long long power(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {  // if exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};
