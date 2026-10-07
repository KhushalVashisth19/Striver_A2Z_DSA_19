//Brute Force : TC : O(N^2), SC : O(N)
#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == k) {
              	int subLen = j - i + 1;
                res = max(res, subLen);
            }
        }
    }

    return res;
}

//Optimized Approach : TC : O(N), SC : O(N)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int>m;
        int res = 0;
        int prefSum = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            prefSum += arr[i];
            if(prefSum == k){
                res = i+1;
            }
            else if(m.find(prefSum - k) != m.end()){
                res = i - m[prefSum - k] > res ? i - m[prefSum - k] : res;
            }
            
            if(m.find(prefSum) == m.end()){
                m[prefSum] = i;
            }
        }
        return res;
    }
};
