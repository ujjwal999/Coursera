#include <iostream>
#include <cassert>
#include<vector>
using namespace std;
int main() {
    long long int n = 0;
    cin>>n;
   if(n<0 || n>10000000)
    return 0;
   long long int a[n];
    a[0]=0;
	a[1]=1;
	for(long long int i=2;i<=n;i++)
		a[i]=(a[i-1]+a[i-2])%10;

    	cout << a[n] << '\n';
    return 0;
}
