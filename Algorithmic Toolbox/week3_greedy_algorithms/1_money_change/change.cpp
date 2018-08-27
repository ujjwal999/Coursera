#include <iostream>
int main() {
  int m;
  std::cin >> m;
  if(m<1||m>1000)
  return 0;
  std::cout << (m/10+((m%10)/5)+m%5)<< '\n';
}
