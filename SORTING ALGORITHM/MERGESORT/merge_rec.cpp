#include <iostream>
using namespace std;
class merge
{
    int *arr;
    int n;

public:
    merge(void)
    {
        cout << "Enter the number of elements you want --> " << endl;
        cin >> n;
        arr = new int[n];
        cout << "Enter the elements -> " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(0, n - 1);
        display();
    }
    void display(void)
    {
        cout << "Your array is --> " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << " , " << arr[i];
        }
    }
    void merging(int i, int mid, int j)
    {
        int x = i;
        int y = mid + 1;
        int ar[n];
        int k = 0;
        while (x != mid + 1 && y != j + 1)
        {
            if (arr[x] > arr[y])
            {
                ar[k++] = arr[y++];
            }
            else
            {
                ar[k++] = arr[x++];
            }
        }
        while (x != mid + 1)
        {
            ar[k++] = arr[x++];
        }
        while (y != j + 1)
        {
            ar[k++] = arr[y++];
        }
        k = 0;
        for (int p = i; p <= j; p++)
        {
            arr[p] = ar[k++];
        }
    }
    void sort(int i, int j)
    {
        int mid = (i + j) / 2;
        if (i < j)
        {
            sort(i, mid);
            sort(mid + 1, j);
            merging(i, mid, j);
        }
    }
};
int main()
{
    merge mg;
}