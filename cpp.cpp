#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stl_pair.h>

using namespace std;

void print_map(const map<string, string>& m) {
//	cout << "Size = " << m.size() << endl;
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

int main() {
	int Q = 0;
	string operation;
	map<string, string> list;
	string new_capital;
	string old_country_name;
	string new_country_name;
	string country;

	auto list_begin = list.begin();

	cin >> Q;

	for (int q = 0; q < Q; q++) {

		cin >> operation;

		if (operation == "CHANGE_CAPITAL") {

			cin >> country >> new_capital;

//			, либо создать

			auto it = list.find(country);
			if (it != list.cend()) {
				// название столицы совпадает с предыдущим
				if (new_capital == it->second){
					cout << "Country " << country << " hasn't changed its capital"  << endl;
				}
				// название столицы не совпадает с предыдущим
				if (new_capital != it->second){
					cout << "Country " << country << " has changed its capital from " << it->second << " to " << new_capital <<endl;
					it->second = new_capital; // Для страны задать новую столицу
				}

			} else {
				list[country] = new_capital;
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}

		} else if (operation == "RENAME") {
			cin >> old_country_name >> new_country_name;
			auto it = list.find(old_country_name);

			// Есть запись с ключом old_country_name
			if (it != list.cend()) {
                if (list.find(new_country_name) == list.cend()) // такой записи не было
                {
                	list[new_country_name] = it->second;
                	list.erase(it); // удаляем предыдущую запись
                	cout << "Country " << old_country_name << " with capital " << it->second << " has been renamed to " << new_country_name << endl;
                }
                else {
                	cout << "Incorrect rename, skip" << endl;
                }
			} else {
				// нечего переименовывать
				cout << "Incorrect rename, skip" << endl;
			}

		} else if (operation == "ABOUT") {
			cin >> country;
			auto it = list.find(country);
			if (it != list.cend()) {
				cout << "Country " << country << " has capital " << it->second << endl;
			} else {
				cout << "Country " << country << " doesn't exist" << endl;
			}

		} else if (operation == "DUMP") {
			if(list.size() == 0){
				cout << "There are no countries in the world" << endl;
			} else{
				for (auto item: list){
					cout << item.first << "/" << item.second << " ";
				}
				cout << endl;
			}
		}

	country.clear();
	new_capital.clear();
	old_country_name.clear();
	new_country_name.clear();

//	print_map(list);
}

return 0;
}
