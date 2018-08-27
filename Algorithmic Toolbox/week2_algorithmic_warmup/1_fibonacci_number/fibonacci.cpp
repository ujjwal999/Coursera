#include <iostream>
#include <cassert>
#include<vector>
using namespace std;
int main() {
    int n = 0;
    cin>>n;
   if(n<0 || n>45)
    return 0;
    int a[n];
    a[0]=0;
	a[1]=1;
	for(int i=2;i<=n;i++)
		a[i]=a[i-1]+a[i-2];

    	cout << a[n] << '\n';
    return 0;
}
