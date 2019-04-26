#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stl_pair.h>

using namespace std;

void print_map(const map<string, string>& m);
void char_counters(string word, map<char, int>& m);

int main() {

	int Q = 0;

	string operation;
	string bus;
	string stop;
	int stop_count = 0;

	map <string, vector<string>> bus_stop_m =
	{
	   {"b2", {"s2", "s1", "s3"}},
	   {"b3", {"s1", "s2", "s3"}},
	   {"b1", {"s1", "s2", "s3"}}
	};

	for (auto key: bus_stop_m){
		cout << key.first << ": ";
		for (auto value: key.second){
			cout << value << " ";
		}
		cout << endl;
	}

	cout << endl;
	auto it = bus_stop_m.end();
	it--;
	for (it; it != bus_stop_m.begin(); ){
		cout << it->first << ": ";
		for (auto value: it->second){
			cout << value << " ";
		}
		cout << endl;
		it--;
	}

	cin >> Q;

	for (int q = 0; q < Q; q++) {

		cin >> operation;

		// NEW_BUS bus stop_count stop1 stop2 ...
		if (operation == "NEW_BUS") {
			cin >> bus >> stop_count;
			string str;
			for (int i = 1; i <= stop_count; i++){
				cin >> str;
				bus_stop_m[bus].push_back(str);
			}


		} else if (operation == "BUSES_FOR_STOP") {
			uint8_t stop_exist = 0;
			cin >> stop;
			for (auto b: bus_stop_m){
				for (auto s: b.second){
					if (s == stop){
						cout << b.first << " ";
						stop_exist = 1;
					}
				}
			}
			if (stop_exist == 0){
				cout << "No stop";
			}
			cout << endl;

		} else if (operation == "STOPS_FOR_BUS") {
			uint8_t interchange = 0;

			cin >> bus;
/*
4
NEW_BUS b2 3 s2 s1 s3
NEW_BUS b3 3 s1 s2 s3
NEW_BUS b1 3 s1 s2 s3
STOPS_FOR_BUS b2

Stop s2: b3 b1
Stop s1: b3 b1
Stop s3: b3 b1
 */
			auto it = bus_stop_m.find(bus);
			// Если автобус существует
			if (it != bus_stop_m.cend()) {
				for(auto s: it->second){
					cout << "Stop " << s << ": ";
					for ( auto b: bus_stop_m ){ // TODO: сделать обратный перебор автобусов
						for ( auto st: b.second ){
							if (st == s && b.first != bus ){
								cout << b.first << " ";
								interchange = 1;
							}
						}
					}
					if (interchange == 0){
						cout << "no interchange";
					} else{
						interchange = 0;
					}
					cout << endl;
				}
			} else {
				cout << "No bus" << endl;
			}

		} else if (operation == "ALL_BUSES") {
			if (bus_stop_m.size() == 0){
				cout << "No buses" << endl;
			}
			for (auto b: bus_stop_m){
				cout << "Bus " << b.first << ": ";
				for (auto s: b.second){
					cout << s << " ";
				}
				cout << endl;
			}
		}
}

	return 0;
}
