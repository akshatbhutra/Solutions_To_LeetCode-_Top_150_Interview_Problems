// https://leetcode.com/problems/happy-number/
// approach:
// there is a fixed transition for fixed n
// our goal is to detect a cycle in it
// or it ends at 1
// tortoise and hare / slow and fast pointer algorithm

class Solution {
public:
    int next(int n) {
        int s = 0;
        while (n > 0) {
            s += (n % 10) * (n % 10);
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        while (1) {
            cout << "fast " << fast << " slow " << slow << '\n';
            if (fast == 1) {
                return true;
            }
            if (fast == slow) {
                return false;
            }
            fast = next(next(fast));
            slow = next(slow);
        }
        return false;
    }
};