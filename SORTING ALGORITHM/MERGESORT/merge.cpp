#include <iostream>
using namespace std;
class merge
{
    int *arr;
    int n;

public:
    merge(void)
    {
        cout << "Enter the number of elements you want -> " << endl;
        cin >> n;
        arr = new int[n];
        cout << "Enter the elements -->" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sot();
    }
    void merges(int l, int m, int h)
    {
        int ar[h + 1];
        int k = 0;
        int i = l, j = m + 1;
        while (i <= m && j < h + 1)
        {
            if (arr[i] > arr[j])
            {
                ar[k++] = arr[j++];
            }
            else
            {
                ar[k++] = arr[i++];
            }
        }
        for (; i <= m; i++)
        {
            ar[k++] = arr[i];
        }
        for (; j < h + 1; j++)
        {
            ar[k++] = arr[j];
        }
        for (int i = 0; i < k; i++)
        {
            arr[l++] = ar[i];
        }
    }
    void sot(void)
    {
        int i = 0, p = 1;
        for (p = 2; p <= n; p = p * 2)
        {
            for (i = 0; i + p - 1 < n; i = i + p)
            {
                int m = (i + i + p - 1) / 2;
                merges(i, m, i + p - 1);
            }
            if ((n - i) > (p / 2))
            {
                int m = i + (p / 2) - 1;
                merges(i, m, n - 1);
            }
        }
        p = p / 2;
        if (n % p != 0)
        {
            merges(0, p - 1, n - 1);
        }
        display();
    }
    void display(void)
    {
        cout << "array after sorting --> ";
        for (int i = 0; i < n; i++)
        {
            cout << " " << arr[i];
        }
    }
};
int main()
{
    merge mg;
}