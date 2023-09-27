



















// // 1) min length = 1, max length = n
        // 2) 1 is always the ans possible
        // binary search problem beacuse if x length substring is of unique characters, x - 1 also and so on
        // 1...............n
        // TTTTTTTTTTFFFFFFF
        // last T
        // l = which is definitely an ans
        // r = which is surely not an ans
        // stop when l and r come adjacent i.e while (r - l > 1)
        // finally output l
        // check(mid) normal

// class Solution {
// public:
//     bool ok (int x, string &s) {
//         // check all "x" length substrings in s
//         int n = s.size();
//         unordered_map<char,int> cc;
//         for(int i=0;i<x;i++) cc[s[i]]++;
//          if (cc.size() == x) return 1;
//         for (int i = x;i < n;i++) {
//             cc[s[i-x]]--;
//              if(cc[s[i-x]] == 0) cc.erase(s[i-x]);
//             cc[s[i]]++;            
//             if (cc.size() == x) return 1;
//        }
//     return 0;
//     }
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         if(s == "") return 0;
//         int l = 1, r = n + 1;
//         while (r - l > 1) {
//             int m = (l + r) / 2;
//             if(ok(m, s))
//                 l = m;
//             else 
//                 r = m;
//         }
//         return l;
//     }
// };