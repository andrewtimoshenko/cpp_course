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

	map<string, vector<string>> bus_stop_m;
//	map<string, vector<string>> stop_bus_m;

	vector <string> v = {"first", "second"};

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
			uint8_t bus_exist  = 0;

			cin >> bus;
//			auto it = bus_stop_m.begin(); // TODO: отказаться от обращения [], сделать поиск через find
			// проверить на простых примерах
			// NEW_BUS 1 5 q w e r t
			// STOPS_FOR_BUS 2
			// ALL_BUSES

			for (auto s: bus_stop_m[bus]){

				bus_exist = 1;
				interchange = 0;
				cout << "Stop " << s << ": ";
				for (auto b: bus_stop_m){
					for (auto st: b.second){
						if (st == s && b.first != bus){
							cout << b.first << " ";
							interchange = 1;
						}
					}
				}

			if (interchange == 0){
				cout << "no interchange";
			}
				cout << endl;
			}
			if (bus_exist == 0){
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
