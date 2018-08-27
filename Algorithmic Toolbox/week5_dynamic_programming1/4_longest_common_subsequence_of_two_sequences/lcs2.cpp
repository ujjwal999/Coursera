#include <iostream>
#include <vector>
#define max(a,b) (a>b?a:b)
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
    int dp[102][102] = {0};
    int la = a.size(), lb = b.size();
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
                if (a[i - 1] == b[j - 1] ) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j]= max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
    return dp[la][lb];
}
int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
