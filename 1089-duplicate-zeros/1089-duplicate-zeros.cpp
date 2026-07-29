class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int possibleDups = 0;
        int last = n - 1;

        // Count the zeros that can be duplicated
        for (int left = 0; left <= last - possibleDups; left++) {

            if (arr[left] == 0) {

                // Edge case: zero at the boundary
                if (left == last - possibleDups) {
                    arr[last] = 0;
                    last--;
                    break;
                }

                possibleDups++;
            }
        }

        // Start from the last element that will be copied
        for (int i = last - possibleDups; i >= 0; i--) {

            if (arr[i] == 0) {
                arr[i + possibleDups] = 0;
                possibleDups--;
                arr[i + possibleDups] = 0;
            } else {
                arr[i + possibleDups] = arr[i];
            }
        }
    }
};