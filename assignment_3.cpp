#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void knapsack()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Number of items cannot be negative.\n";
        return;
    }

    vector<int> weight(n + 1);
    vector<int> profit(n + 1);

    cout << "Enter weights of items:\n";

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];

        if (weight[i] <= 0)
        {
            cout << "Weights must be positive.\n";
            return;
        }
    }

    cout << "Enter profits of items:\n";

    for (int i = 1; i <= n; i++)
    {
        cin >> profit[i];

        if (profit[i] < 0)
        {
            cout << "Profits cannot be negative.\n";
            return;
        }
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0)
    {
        cout << "Capacity cannot be negative.\n";
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weight[i] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], profit[i] + dp[i - 1][w - weight[i]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][capacity] << endl;

    cout << "Selected items: ";
    int w = capacity;

    for (int i = n; i >= 1; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << i << " ";
            w -= weight[i];
        }
    }

    cout << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== 0-1 Knapsack Menu =====\n";
        cout << "1. Solve Knapsack Problem\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            knapsack();
            break;

        case 2:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 2);

    return 0;
}
