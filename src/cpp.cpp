#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  /*
   * Не нужно ничего усложнять!
   * Просто нужно использовать те вещи, которые дали в уроках
   * и не придумывать лишнего!
   */
  vector <int> array;
  if (n >= 0 && n <= 1000){
	  for (int i = 0; i < n; ++i) {
		  int x;
		  cin >> x;
		  array.push_back(x);
		  if (x >= -1000000 && x <= 1000000){
		  } else {
			  return 1;
		  }
	  }
  } else {
	  return 1;
  }

  sort(array.begin(), array.end(), [](int a, int b){
	  if (abs(a) < abs(b)){
		  return true;
	  } else {
		  return false;
	  }
  });

  for (auto i: array){
	  cout << i << ' ';
  }

  return 0;
}
