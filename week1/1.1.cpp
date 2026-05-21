#include <iostream>
using namespace std;

int main()
{
    int n, key, comp = 0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> key;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        comp++;

        if (arr[i] == key)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Present\n";
    else
        cout << "Not Present\n";

    cout << "Comparisons = " << comp;

    return 0;
}