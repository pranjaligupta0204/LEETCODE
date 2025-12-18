class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int x = a.size();
        int y = b.size();
        int start = 0, end = x;

        while (start <= end) {
            int partX = start + (end - start) / 2;
            int partY = (x + y + 1) / 2 - partX;

            int maxLeftX = (partX == 0) ? INT_MIN : a[partX - 1];
            int minRightX = (partX == x) ? INT_MAX : a[partX];

            int maxLeftY = (partY == 0) ? INT_MIN : b[partY - 1];
            int minRightY = (partY == y) ? INT_MAX : b[partY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0)
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                else
                    return max(maxLeftX, maxLeftY);
            }

            if (maxLeftX > minRightY)
                end = partX - 1;
            else
                start = partX + 1;
        }
        return 0.0;
    }
};
