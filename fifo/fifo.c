#include <stdio.h>
int x,n;
void fifo(int *);
int main()
{
    printf("Enter the no. of entries you want -.>");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the sequence in which pages will be executed ->");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the no. of frames ->");
    scanf("%d",&x);
    fifo(arr);
    return 0;
}
void fifo(int *arr)
{
    int ans[x];
    int top=0,faults=0,j=0;
    ans[0]=arr[0];
    for(int i =0; i<n;i++)
    {
        if(x>j)
        {
            for(int k=0;k<j;k++)
            {
                if(ans[k]==arr[i])
                goto there;
                
            }
            ans[j]=arr[i];
            faults++;
            j++;
            there:;
        }
        else
        {
            for(int j=0;j<x;j++)
            {
                if(ans[j]==arr[i])
                goto here;
                
            }
            ans[top]=arr[i];
            top=(top+1)%x;
            faults++;
        }
        here:;
    }
    printf("\nNo. of page faults -> %d",faults);
}