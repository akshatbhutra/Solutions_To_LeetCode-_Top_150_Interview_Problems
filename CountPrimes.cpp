// https://leetcode.com/problems/count-primes/
// Approach:
// Sieve Of Eratosthenes to precompute primes till n.

class Solution {
public:
    int limit;
    // vector<int> primes;
    vector<bool> is_prime;
    int sieve() {
        is_prime.resize(limit + 1);
        fill(is_prime.begin(), is_prime.end(), 1);
        int ans = 0;
        is_prime[1] = 0;
        for (int i = 2; i * i <= limit; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
        for (int i = 2; i <= limit; i++)
            if (is_prime[i])
                ans++;
        return ans;
    }  
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        limit = n - 1;
        return sieve();
    }
};