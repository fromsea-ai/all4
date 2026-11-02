#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void generateCodes(Node *root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : "
             << (code.empty() ? "0" : code) << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

void deleteTree(Node *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    int n, choice;

    do
    {
        cout << "\n===== Huffman Encoding Menu =====\n";
        cout << "1. Generate Huffman Codes\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter number of characters: ";
            cin >> n;

            if (n <= 0)
            {
                cout << "Number of characters must be positive.\n";
                break;
            }

            priority_queue<Node *, vector<Node *>, Compare> pq;
            set<char> characters;
            bool valid = true;

            cout << "Enter character and frequency:\n";

            for (int i = 0; i < n; i++)
            {
                char ch;
                int freq;

                cin >> ch >> freq;

                if (freq < 0)
                {
                    cout << "Frequency cannot be negative.\n";
                    valid = false;
                    break;
                }

                if (characters.count(ch))
                {
                    cout << "Duplicate character is not allowed.\n";
                    valid = false;
                    break;
                }

                characters.insert(ch);
                pq.push(new Node(ch, freq));
            }

            if (!valid)
            {
                while (!pq.empty())
                {
                    deleteTree(pq.top());
                    pq.pop();
                }
                break;
            }

            while (pq.size() > 1)
            {
                Node *left = pq.top();
                pq.pop();

                Node *right = pq.top();
                pq.pop();

                Node *newNode =
                    new Node('$', left->freq + right->freq);

                newNode->left = left;
                newNode->right = right;

                pq.push(newNode);
            }

            Node *root = pq.top();

            cout << "\nHuffman Codes:\n";
            generateCodes(root, "");

            deleteTree(root);
            break;
        }

        case 2:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 2);

    return 0;
}
