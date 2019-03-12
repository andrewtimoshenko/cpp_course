#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double N = 0;
	double A = 0;
	double B = 0;
	double X = 0;
	double Y = 0;

	double total_cost = 0;

	cin >> N >> A >> B >> X >> Y;

	if(A <= B){

		// Скидка 0
		if (N <= A) {
			total_cost = N;
			cout << total_cost;
		}

		// Скидка X%
		if (N > A && N <= B){
			total_cost = N - (N*X)/100;
			cout << total_cost;
		}

		// Скидка Y%
		if (N > B){
			total_cost = N - (N*Y)/100;
			cout << total_cost;
		}

	}

	return 0;
}

