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
	vector <string> vec = {"first","second"};
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


		} else if (operation == "STOPS_FOR_BUS") {
			cin >> bus;
			cout << "BUS: " << bus << endl;
			for (auto stop_name: bus_stop_m[bus]){
				cout << stop_name << " ";
			}

		} else if (operation == "ALL_BUSES") {


		}
}

return 0;
}



void print_map(const map<string, string>& m) {
	cout << "Size = " << m.size() << endl;
	for (const auto& item : m) {
		cout << item.first << ": " << item.second << endl;
	}
}

// Буква уже в словаре? Нет - добавляем, Да - инкремент частоты в словаре
void char_counters(string word, map<char, int>& m) {
	// Each letter
	for (auto ch : word) {
		++m[ch];
	}
}

