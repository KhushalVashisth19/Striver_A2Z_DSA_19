#include <iostream>
#include <vector>

using namespace std;

int lowerBound(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // Default if all elements < target

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;         // Potential lower bound found
            high = mid - 1;    // Search left half for a smaller index
        } else {
            low = mid + 1;     // Search right half
        }
    }

    return ans;
}

int main() {
    //
}
