#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int partitionDeterministic(vector<int>& a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortDeterministic(vector<int>& a, int low, int high)
{
    if (low < high)
    {
        int pi = partitionDeterministic(a, low, high);

        quickSortDeterministic(a, low, pi - 1);
        quickSortDeterministic(a, pi + 1, high);
    }
}

int partitionRandomized(vector<int>& a, int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);

    swap(a[randomIndex], a[high]);

    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortRandomized(vector<int>& a, int low, int high)
{
    if (low < high)
    {
        int pi = partitionRandomized(a, low, high);

        quickSortRandomized(a, low, pi - 1);
        quickSortRandomized(a, pi + 1, high);
    }
}

void display(vector<int>& a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int choice, n;

    srand(time(0));

    do
    {
        cout << "\n===== Quick Sort Menu =====\n";
        cout << "1. Deterministic Quick Sort\n";
        cout << "2. Randomized Quick Sort\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            cout << "Enter number of elements: ";
            cin >> n;

            if (n <= 0)
            {
                cout << "Invalid number of elements.\n";
                continue;
            }

            vector<int> a(n);

            cout << "Enter elements:\n";

            for (int i = 0; i < n; i++)
                cin >> a[i];

            if (choice == 1)
                quickSortDeterministic(a, 0, n - 1);
            else
                quickSortRandomized(a, 0, n - 1);

            cout << "Sorted Array:\n";
            display(a);
        }
        else if (choice == 3)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
