#include <iostream>
using namespace std;
class heap
{
    int *arr;
    int n;
    int y;

public:
    heap(int x)
    {
        arr = new int[x];
        n = -1;
        y = x;
        insert();
        delet();
        cout << "After sorting --> " << endl;
        print();
    }
    void insert(void)
    {
        int i = 0, x;
        cout << "Enter elements --> ";
        while (i < y)
        {
            cin >> arr[i];
            n = i;
            x = arr[i];
            while (i > 0 && x > arr[int((i / 2.0) - 0.5)])
            {
                arr[i] = arr[int((i / 2.0) - 0.5)];
                i = int((i / 2.0) - 0.5);
            }
            arr[i] = x;
            i = n;
            i++;
        }
    }
    void delet(void)
    {
        int x = y - 1;
        int i, j = 0;

        while (x > 0)
        {
            i = 0;
            j = (i * 2) + 1;
            if (arr[i] < arr[x])
            {
                break;
            }
            int temp = arr[i];
            arr[i] = arr[x];
            arr[x] = temp;

            while (j < x - 1)
            {
                if (arr[j] < arr[j + 1])
                {
                    j = j + 1;
                }
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i = j;
                    j = (i * 2) + 1;
                }
                else
                    break;
            }
            x--;
        }
    }
    void print(void)
    {
        int i = 0;
        while (i < y)
        {
            cout << arr[i] << endl;
            i++;
        }
    }
};
int main()
{
    int x;
    cout << "Enter the total number of elements you want in your heap -->" << endl;
    cin >> x;
    heap hp(x);
}