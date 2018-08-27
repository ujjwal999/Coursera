#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
main() 
{
    long int n;
    cin>>n;
 if(n<2 || n>200000)
  return 0;
vector<long long int> numbers(n);
   for(int i=0;i<n;++i)
    {
        cin >> numbers[i];
        if(numbers[i]<0 || numbers[i]>200000)
        return 0;
		}

 sort(numbers.begin(),numbers.end());
 long long int x=numbers[n-1]*numbers[n-2];
cout <<x  ;
    return 0;
}
