class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int count = 0;

        int i = 0;
        int j = n - 1;

        // Skip consecutive L's from the left — they never collide
        while (i < n && directions[i] == 'L') i++;

        // Skip consecutive R's from the right — they never collide
        while (j >= 0 && directions[j] == 'R') j--;

        // Count all cars that will collide in the middle segment
        while (i <= j) {
            if (directions[i] == 'L' || directions[i] == 'R')
                count++;
            i++;
        }

        return count;
    }
};