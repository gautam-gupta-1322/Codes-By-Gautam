#include <iostream>
using namespace std;
class quick
{
    int *arr;
    int n;

public:
    quick(void)
    {
        cout << "Enter the total number of elements you want ->" << endl;
        cin >> n;
        arr = new int[n + 1];
        cout << "Enter the elements --> " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        arr[n] = INT32_MAX;
        sort(0, n);
    }
    int partition(int l, int h)
    {
        int i = l, j = h;
        do
        {
            do
            {
                i++;
            } while (arr[i] <= arr[l] && i < j);

            do
            {
                j--;
            } while (arr[j] > arr[l]);
            if (i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } while (i < j);
        int temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;
        return j;
    }
    void sort(int l, int h)
    {
        if (l < h)
        {
            int x = partition(l, h);
            sort(l, x);
            sort(x + 1, h);
        }
    }
    void display(void)
    {
        cout << "Your sorted array --> " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    quick sr;
    sr.display();
}