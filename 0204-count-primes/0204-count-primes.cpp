class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * 2; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
        //idea is if a number if prime then all its multiples are not prime so if we find a prime then we take count++ and then all its multiples less than n we mark as false
    }
};