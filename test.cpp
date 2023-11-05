#include<iostream>
using namespace std;

bool isPowerofBase(int n,int b)
{
    if(n==1)
    {
        return true;
    }
    else
    {
        int temp=n/b;
        int ret=n%b;
        if(ret!=0)
        {
            return false;
        }
        return isPowerofBase(temp,b);
    }
}
main()
{
bool result=isPowerofBase(3,8);
cout<<result;
}