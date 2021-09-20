#include <iostream>
#include<string>
using namespace std;
class intopo;
class stack
{
protected:
    int top;
    int n;
    int *arr;

public:
    friend class intopo;
    stack(int y)
    {
        top = -1;
        n = y;
        arr = new int[n];
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop(void)
    {
        return arr[top--];
    }
};
class intopo : protected stack
{
    string s;
    int st;

public:
    int isoperator(char ch)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            return 1;
        else
            return 0;
    }
    int imp(char ch)
    {
        if (ch == '+' || ch == '-')
        {
            return 1;
        }
        if (ch == '*' || ch == '/')
        {
            return 2;
        }
        if (ch == '^')
        {
            return 3;
        }
        else 
        return 0;
    }
    intopo(int q ,string k):stack(q)
    {
        s = k;
        st = s.length();
        convert();
    }
    void convert()
    {
        int k = 0;
        char a[st + 1];
        int i = 0;
        while (s[i] != '\0')
        {
            if (s[i] == '(')
            {
                push(s[i++]);
            }
            else if (isoperator(s[i]))
            {
                if (top == -1)
                    push(s[i++]);
                else if (imp(arr[top]) < imp(s[i]))
                {
                    push(s[i++]);
                }
                else if (imp(arr[top]) > imp(s[i]))
                {
                    while ((arr[top]) > imp(s[i]))
                    {
                        a[k++] = pop();
                    }
                }
                else if (imp(arr[top]) == imp(s[i]))
                {
                    a[k++] = pop();
                }
            }
            else if (s[i] == ')')
            {
                while (arr[top] != '(')
                {
                    a[k++] = pop();
                }
                pop();
                i++;
            }
            else
            {
                a[k++] = s[i++];
            }
        }
        while (top != -1)
        {
            a[k++] = pop();
        }
        a[k]='\0';
        cout << "Postfix - > " << a << endl;
    }
};
int main()
{
    string x;
    cout<<"Enter Infix expression ->"<<endl;
    cin>>x;
    intopo helu(x.length(),x);
}