class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char k) {
        int low = 0;
        int high = arr.size() - 1;
        char res = arr[0];
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= k) {
                low = mid + 1;
            }
            else {
                res = arr[mid];
                high = mid - 1;
            }
        }

        return res;
    }
};