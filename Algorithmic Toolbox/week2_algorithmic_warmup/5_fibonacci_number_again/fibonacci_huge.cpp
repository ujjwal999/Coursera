#include <iostream>
using namespace std;

long long pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long huge(long long n, long long m) {
    long long remainder = n % pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    if(n<0 || n>1000000000000000000||m<2||m>1000)
    return 0;
    cout << huge(n, m) << '\n';
}
