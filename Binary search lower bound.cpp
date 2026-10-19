#include <iostream>
#include <vector>

// Time Complexity: O(log N) | Space Complexity: O(1)
int lowerBound(const std::vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size(); // Search space is [low, high)
    
    while (low < high) {
        // Prevents integer overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2; 
        
        if (arr[mid] >= x) {
            high = mid; // Look for a smaller index on the left
        } else {
            low = mid + 1; // Look on the right side
        }
    }
    return low; // Both 'low' and 'high' converge to the lower bound index
}
