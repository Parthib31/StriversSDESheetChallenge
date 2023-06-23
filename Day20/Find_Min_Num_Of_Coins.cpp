#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins = 0;
    int denominations[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    for(int i = 8 ; i >= 0 ; i--)
    {
        if(amount >= denominations[i])
        {
            coins += amount / denominations[i];
            amount = amount % denominations[i];
        }
    }
    return coins;
}