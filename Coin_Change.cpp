#include <iostream>
using namespace std;

int topDown(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }
    // step 1;
    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = topDown(coins, amount - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }
    dp[amount] = mini;
    return dp[amount];
}

int Recsol(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = Recsol(coins, amount - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }
    return mini;
}

int coinChange(vector<int> &coins, int amount)
{
    // int ans= Recsol(coins,amount);
    // if(ans==INT_MAX)
    // {
    //     return -1;
    // }
    // else{
    //     return ans;
    // }
    vector<int> dp(amount + 1, -1);
    int ans = topDown(coins, amount, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
}