// https://leetcode.com/problems/find-median-from-data-stream/
// Approach
// Use policy based data structure 

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // find_by_order, order_of_key
class MedianFinder {
public:
    ordered_multiset s;
    MedianFinder() {
        s.clear();
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        int n = s.size();
        if (n & 1)
            return (*s.find_by_order(n / 2));
        else {
            return ((*s.find_by_order(n / 2)) + (*s.find_by_order((n - 1) / 2))) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */