class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {

    // Binary search on smaller array
    if(a.size() > b.size())
        return findMedianSortedArrays(b, a);

    int n1 = a.size();
    int n2 = b.size();

    int low = 0;
    int high = n1;

    int leftSize = (n1 + n2 + 1) / 2;

    while(low <= high) {

        int cut1 = low + (high - low) / 2;
        int cut2 = leftSize - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : a[cut1];

        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

        // Correct partition
        if(l1 <= r2 && l2 <= r1) {

            // Odd
            if((n1 + n2) % 2 == 1)
                return max(l1, l2);

            // Even
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }

        // Took too many elements from A
        else if(l1 > r2) {
            high = cut1 - 1;
        }

        // Took too few elements from A
        else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}
};