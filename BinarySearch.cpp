#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // (left + right) / 2 se hone wale integer overflow ko rokta hai
            int mid = left + (right - left) / 2; 
            
            if (nums[mid] == target) {
                return mid; // Target mil gaya
            } else if (nums[mid] < target) {
                left = mid + 1; // Right half me search karein
            } else {
                right = mid - 1; // Left half me search karein
            }
        }
        
        return -1; // Target nahi mila
    }
};
