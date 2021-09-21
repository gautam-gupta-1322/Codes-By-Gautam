#include <stdio.h>
int x,n;
void lru(int *);
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
    lru(arr);
    return 0;
}
void lru(int * arr)
{
    int ans[x];
    int faults=0,j=0;
    int temp=0;
    ans[0]=arr[0];
    int z,k;
    for(int i=0;i<n;i++)
    {
        if(x>j)
        {
            for(k=0;k<j;k++)
            {
                if(ans[k]==arr[i])
                {
                    temp=arr[i];
                    for(z=k;z<j-1;z++)
                    {
                        ans[z]=ans[z+1];
                    }
                    ans[z]=temp;
                    goto there;    
                }
            }
            ans[j]=arr[i];
            faults++;
            j++;
            there:;
        }
        else
        {
            for(k=0;k<x;k++)
            {
                if(ans[k]==arr[i])
                {
                    temp=arr[i];
                    for(z=k;z<x-1;z++)
                    {
                        ans[z]=ans[z+1];
                    }
                    ans[z]=temp;
                    goto here;
                }
            }
            for(k=0;k<x-1;k++)
            {
                ans[k]=ans[k+1];
            }
            ans[k]=arr[i];
            faults++;
            here:;
        }
    }
    printf("\nTotal no. of page faults from lru algo are -> %d",faults);
}