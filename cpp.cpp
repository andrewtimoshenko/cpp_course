#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int A = 0;
	int B = 0;

	cin >> A >> B;

	if (A <= B && A >= 1 && B <= 30000){
		for (int x = A; x <= B; ++x){
			if (x % 2 == 0) {
			  // x - чётное число
				cout << x << " ";
			} else {
			  // x - нечётное число
			}
		}
	}

	return 0;
}

