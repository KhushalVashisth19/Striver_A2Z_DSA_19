#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // 1. If target is found, return its index
            if (nums[mid] == k) {
                return mid;
            }
            
            // 2. Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (k >= nums[left] && k < nums[mid]) {
                    right = mid - 1; // Eliminate right half
                } else {
                    left = mid + 1;  // Eliminate left half
                }
            } 
            // 3. Otherwise, the right half must be sorted
            else {
                // Check if target lies within the sorted right half
                if (k > nums[mid] && k <= nums[right]) {
                    left = mid + 1;  // Eliminate left half
                } else {
                    right = mid - 1; // Eliminate right half
                }
            }
        }
        
        return -1; // Target not found
    }
};
