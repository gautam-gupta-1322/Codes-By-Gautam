#include <stdio.h>
int x, n;
void opr(int *);
int main()
{
    printf("Enter the no. of entries you want -.>");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sequence in which pages will be executed ->");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the no. of frames ->");
    scanf("%d", &x);
    opr(arr);
    return 0;
}
void opr(int *arr)
{
    int ans[x];
    int index[x];
    int max = 0, y;
    int top = 0, faults = 0, j = 0, z;
    ans[0] = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (x > j)
        {
            for (int k = 0; k < j; k++)
            {
                if (ans[k] == arr[i])
                    goto there;
            }
            ans[j] = arr[i];
            faults++;
            for (z = i + 1; z < n; z++)
            {
                if (ans[j] == arr[z])
                {
                    index[j] = z;
                    break;
                }
            }
            if (z == n)
            {
                index[j] = n;
            }
            j++;
        there:;
        }
        else
        {
            for (int j = 0; j < x; j++)
            {
                if (ans[j] == arr[i])
                    goto here;
            }
            for (int j = 0, max = 0; j < x; j++)
            {
                if (index[j] >= max)
                {
                    max = index[j];
                    y = j;
                }
                if (index[j] == n)
                {
                    y = j;
                    break;
                }
            }
            ans[y] = arr[i];
            for (z = i + 1; z < n; z++)
            {
                if (arr[i] == arr[z])
                {
                    index[y] = z;
                    break;
                }
            }
            if (z == n)
            {
                index[y] = n;
            }
            faults++;
        here:;
        }
    }
    printf("\nNo. of page faults -> %d", faults);
}