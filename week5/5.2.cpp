#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, key;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> key;

    sort(arr, arr + n);

    int i = 0, j = n - 1;
    bool found = false;

    while (i < j)
    {
        int sum = arr[i] + arr[j];

        if (sum == key)
        {
            cout << "Present";
            found = true;
            break;
        }
        else if (sum < key)
            i++;
        else
            j--;
    }

    if (!found)
        cout << "Not Present";

    return 0;
}