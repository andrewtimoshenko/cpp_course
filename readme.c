/*

stdin	            stdout
100 110 120 5 10	100
115 110 120 5 10	109.25
150 110 120 5 12.5 	131.25

#include <iostream>
using namespace std;

#include <iostream>

using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > b) {
        n *= (1 - y / 100);
    } else if (n > a) {
        n *= (1 - x / 100);
    }
    cout << n;

    return 0;
}

 */
