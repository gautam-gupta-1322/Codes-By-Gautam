// vignere cypher 
#include<stdio.h>
#include<string.h>
int main()
{
    char pt[100],k[20],rk[100],ct[100],ch;
    int i,j,c,x,y;
    printf("Enter the plain text -> ");
    scanf("%[^\n]s",pt);
    printf("\nEnter key -> ");
    scanf(" %[^\n]s",k);
    x=strlen(pt);
    y=strlen(k);
    for(i=0,j=0;i<=x;i++,j++)
    {
        {
            if(i==x)
            {
                rk[i]=0;
                break;
            }
            else if(pt[i]==' ')
            {
                rk[i]=' ';
                j--;
                continue;
            }
            else
            {
                rk[i]=k[j];
            }
        }
        if(j==y-1)
        j=-1;
    }
    printf("\nDo you want to encrypt(e) or decrypt(d) -> ");
    scanf(" %c",&ch);
    if(ch=='e')
    {
        for(i=0;i<=x;i++)
        {
            c=(pt[i]-97)+(rk[i]-97);
            if(c>=26)
            c=c-26;
            if(pt[i]==' ')
            ct[i]=' ';
            else if(i==x)
            ct[i]=0;
            else
            ct[i]=c+97;
        }
        printf("\nCipher text -> %s",ct);
    }
    else 
    {
        for(i=0;i<=x;i++)
        {
            c=(pt[i]-97)-(rk[i]-97);
            if(c<0)
            c=c+26;
            if(c>=26)
            c=c-26;
            if(pt[i]==' ')
            ct[i]=' ';
            else if(i==x)
            ct[i]=0;
            else
            ct[i]=c+97;
        }
        printf("\ndecrypted text -> %s",ct);
    }
    return 0;
}