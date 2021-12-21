class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int numEmpty = numBottles;
        while (numEmpty >= numExchange){
            numBottles += numEmpty / numExchange;
            numEmpty = numEmpty / numExchange + numEmpty % numExchange;
        }
        return numBottles;
    }
};