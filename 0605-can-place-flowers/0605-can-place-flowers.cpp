class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            return (n==0) || (n==1 && flowerbed[0] == 0);
        }
        
        int m = flowerbed.size();
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && i != 0 && i != m - 1) {
                if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            } else if (flowerbed[i] == 0 && i == 0) {
                if (flowerbed[i+1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            } else if (flowerbed[i] == 0 && i == m-1) {
                if (flowerbed[i-1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }

        return n <= 0;
    }
};