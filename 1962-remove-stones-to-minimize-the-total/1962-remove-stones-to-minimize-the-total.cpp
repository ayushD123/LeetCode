class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        vector freq(10001,0);
        int sum = 0;
        int count = 0;
        int size = -1;
        for (int pile : piles) {
            freq[pile]++;
            sum += pile;
            size = max(size, pile);
        }
        for (int j = 0; j < k && size; j++) {
            freq[size - size / 2]++;
            freq[size]--;
            count += size / 2;
            while (!freq[size] && size > 0) {
                size--;
            }
        }
        return sum - count;
    }
};