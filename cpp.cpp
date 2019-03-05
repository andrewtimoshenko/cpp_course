#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<string> str;

	string a(30, ' ');
	string b(30, ' ');
	string c(30, ' ');

	cin >> a >> b >> c;

	str.push_back(a);
	str.push_back(b);
	str.push_back(c);

	sort(str.begin(), str.end());

	cout << str[0];

	return 0;
}
