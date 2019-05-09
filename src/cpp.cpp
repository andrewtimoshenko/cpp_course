#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
  int q;
  cin >> q;
  int route_cntr = 1;
  /*
   * Не нужно ничего усложнять!
   * Просто нужно использовать те вещи, которые дали в уроках
   * и не придумывать лишнего!
   */

  map <set<string>, int> routes_m;

  for (int i = 0; i < q; ++i) {
    int stops_number = 0;
    cin >> stops_number;

    set <string> names;
    for (int n = 0; n < stops_number; n++){
    	string stop_name;
    	cin >> stop_name;
    	names.insert(stop_name);
    }
    if (routes_m.find(names) != routes_m.end()){
    	cout << "Already exists for " << routes_m[names] << endl;
    } else {
        routes_m[names] = route_cntr;
        cout << "New bus " << routes_m[names] << endl;
        route_cntr++;
    }
  }

  return 0;
}
