#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool found = false;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Duplicate Present";
    else
        cout << "No Duplicate";

    return 0;
}