#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    int q;
    uint32_t routes_counter = 0;
    cin >> q;
    map<vector<string>, uint32_t> stops_m;

    for (int i = 0; i < q; ++i) {
        uint32_t stops_num = 0;
        cin >> stops_num;

        vector<string> v(stops_num);

        for (uint32_t i = 0; i < stops_num; i++){
        	string stop_name;
        	cin >> stop_name;
        	v.push_back(stop_name);
        }
        auto it = stops_m.find(v);
        if (it != stops_m.cend()){
        	cout << "Already exists for " << it->second << endl;
        } else {
        	++routes_counter;
        	cout << "New bus " << routes_counter << endl;
        	stops_m[v] = routes_counter;
        }
    }

    return 0;
}
