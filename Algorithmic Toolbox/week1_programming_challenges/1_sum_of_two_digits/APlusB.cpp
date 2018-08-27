#include <iostream>

int main()
{
  int a,b = 0;
  std::cin >> a>>b;
  if(a>=0 && b>=0 && a<=9 && b<=9)
  std::cout << a+b;
  return 0;
}
