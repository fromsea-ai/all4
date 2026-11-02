#include <iostream>
using namespace std;

void iterative(int n) {
    int a = 0, b = 1, c;

    for (int i = 0; i <= n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

void recursive(int a, int b, int n) {
    if (n < 0)
        return;

    cout << a << " ";
    recursive(b, a + b, n - 1);
}

int main() {
    int choice, n;

    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Non-Recursive Method\n";
        cout << "2. Recursive Method\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value of n: ";
            cin >> n;

            if (n < 0)
                cout << "Enter a non-negative integer.\n";
            else {
                cout << "Fibonacci Series: ";
                iterative(n);
                cout << endl;
            }
            break;

        case 2:
            cout << "Enter the value of n: ";
            cin >> n;

            if (n < 0)
                cout << "Enter a non-negative integer.\n";
            else {
                cout << "Fibonacci Series: ";
                recursive(0, 1, n);
                cout << endl;
            }
            break;

        case 3:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
