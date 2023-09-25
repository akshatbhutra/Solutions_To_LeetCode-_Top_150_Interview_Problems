// https://leetcode.com/problems/power-of-three/
// approach1
// atmost log3(n) iterations 

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n == 1)
//             return true;
//         if (n <= 2)
//             return false;
//         long long p = 1;
//         int limit = 21; // log3(MAX)
//         for (int i = 1; i <= limit; i++) {
//             p *= 3;
//             if (p == n) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// Approach2:
// Recursion

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n == 0)
//             return false;
//         if (n == 1)
//             return true;
//         if (n % 3 != 0)
//             return false;
//         return isPowerOfThree(n / 3);
//     }
// };

// another implementation

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1)
            return true;
        if (n <= 2)
            return false;
        while (n != 1) {
            if (n % 3 != 0)
                return false;
            n /= 3;
        }
        return true;
    }
};

// Follow up: Could you solve it without loops/recursion?
// Calculate 3^19 by hand & check if n divides 3^19 as 3^20 overflows in int