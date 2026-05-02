#include <stdio.h>
#include <limits.h>

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i = 0; i < n; i++) {

        if(prices[i] < minPrice) {
            minPrice = prices[i];
        }

        int profit = prices[i] - minPrice;

        if(profit > maxProfit) {
            maxProfit = profit;
        }
    }

    printf("Maximum Profit = %d", maxProfit);

    return 0;
}