#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == x) {
                return {nums[mid], nums[mid]}; // Agar exact mil gaya
            }
            else if (nums[mid] < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        // Loop khatam hone ke baad:
        // high index Floor ko point karega aur low index Ceil ko point karega
        
        int floor_val = (high >= 0) ? nums[high] : -1;
        int ceil_val = (low < nums.size()) ? nums[low] : -1;
        
        return {floor_val, ceil_val};
    }
};
