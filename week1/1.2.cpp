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

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        comp++;

        if (arr[mid] == key)
        {
            found = true;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found)
        cout << "Present\n";
    else
        cout << "Not Present\n";

    cout << "Comparisons = " << comp;

    return 0;
}