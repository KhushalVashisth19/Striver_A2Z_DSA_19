#include <vector>

using namespace std;

class Solution {
public:
    // Helper function jo first ya last occurrence dhoondhne ke kaam aayegi
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                ans = mid; // Answer track kar liya
                
                if (isFirst) {
                    high = mid - 1; // First occurrence ke liye left side check karo
                } else {
                    low = mid + 1;  // Last occurrence ke liye right side check karo
                }
            } 
            else if (nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        
        // Agar first occurrence hi nahi mili, matlab element array mein nahi hai
        if (first == -1) {
            return {-1, -1};
        }
        
        int last = findBound(nums, target, false);
        
        return {first, last};
    }
};
