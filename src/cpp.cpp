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
  vector <string> strings;
  if (n >= 0 && n <= 1000){
	  for (int i = 0; i < n; ++i) {
		  string str;
		  cin >> str;
		  if (str.size() >= 1 && str.size() <= 15){
			  strings.push_back(str);
		  }
	  }

	  sort(strings.begin(), strings.end(), [](string a, string b){ // a.size() > b.size() &&
		  for (auto &ch: a){
			  ch = tolower(ch);
		  }
		  for (auto &ch: b){
			  ch = tolower(ch);
		  }
		  if(a < b) {
			  return true;
		  } else {
			  return false;
		  }
	  });

	  for (auto i: strings){
		  cout << i << ' ';
	  }
  } else {
	  return 1;
  }

  return 0;
}
