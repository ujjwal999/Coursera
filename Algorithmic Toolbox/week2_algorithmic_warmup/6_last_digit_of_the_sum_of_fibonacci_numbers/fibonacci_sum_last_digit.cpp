#include<bits/stdc++.h>
using namespace std;

long long int fib(long long int f[], long long int n)
{
    f[0] = 0;
    f[1] = 1;
    for (long long int i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 10; 
    return f[n];
}
 
int findLastDigit(long long int n)
{  long long int sum=0;
    long long int f[60] = {0};
    fib(f, 60); 
    for (long long int i = 0; i <= n%60; i++)
    sum=sum%10+f[i];
    return sum%10;
}

   int main() {
    long long int n;
    cin>>n;
   if(n<0 || n>1000000000000000000)
    return 0;
    
    	cout << findLastDigit(n) << '\n';
        return 0;
}

