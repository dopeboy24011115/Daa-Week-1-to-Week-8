#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int low = 0, high = n - 1, ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int low = 0, high = n - 1, ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    int n, key;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> key;

    int first = firstOcc(arr, n, key);
    int last = lastOcc(arr, n, key);

    if (first == -1)
        cout << "Not Present";
    else
        cout << "Count = " << last - first + 1;

    return 0;
}