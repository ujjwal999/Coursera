#include <cassert>
#include<vector>
#include <iostream>
using namespace std;
int main()
{
    long long int n1, n2,n3,a,b;
    cin>>n1>>n2;
    a=n1;
    b=n2;
    if(n2<1 || n2>2000000000||n1<1 || n1>2000000000)
    return 0;
    while(n2!=0)
    {
        n3=n1%n2;
        n1=n2;
        n2=n3;
    }
    n3=a*b/n1;
    cout<<n3;
    return 0;
}
