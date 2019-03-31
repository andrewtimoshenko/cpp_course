#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

//enum {                      Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec } current_month;
uint8_t current_month = 0;

uint8_t days_in_month[12] = {31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30, 31};

int count_words(string& s){

	int words = 0;

	for (auto i: s){
		if (isspace(i)){
			words++;
		}
	}

	return ++words;
}

int main() {

	uint32_t Q = 0;
	uint32_t day = 0;
	uint32_t size = 0;
	string business;
	string str;
	vector<string> schedule(31);
//	vector<string> schedule = {"one", "two", "three"};
//
//	cout << schedule.size() << ": ";
//	for (auto s: schedule){
//		cout << s << endl;
//	}
//
//	schedule.resize(2);
//
//	cout << schedule.size() << ": ";
//	for (auto s: schedule){
//		cout << s << endl;
//	}


	cin >> Q;

	for (uint32_t i = 0; i < Q; i++) {

		cin >> str;

		if (str == "ADD") {

			cin >> day;

			if ( day > 0 && day <= days_in_month[current_month] ){ // day for current month
				cin >> business;
				if (business != ""){
					// add some business... check whether elements for businesses
					if (schedule[day - 1] != ""){
						schedule[day - 1] += ' ' + business;
					} else {
						schedule[day - 1] = business;
					}

				}
			}

		} else if (str == "NEXT"){
			// Next bigger than current
			if (days_in_month[current_month + 1] > days_in_month[current_month]){
				schedule.resize(days_in_month[current_month + 1], "");
			} else { // Next less than current

				int diff_days = days_in_month[current_month] - days_in_month[current_month + 1];

				for (int _day = days_in_month[current_month + 1] + 1; _day <= days_in_month[current_month]; _day++ ){
					if (schedule[_day - 1] != ""){ // день для переноса не пустой
						if (schedule[days_in_month[current_month + 1] - 1] != ""){ // день куда переносим не пустой
							schedule[days_in_month[current_month + 1] - 1] += " " + schedule[_day - 1];
						} else{ // пустой - просто пишем
							schedule[days_in_month[current_month + 1] - 1] = schedule[_day - 1];
//							cout << schedule[_day - 1] << " from " << _day - 1 << " to " << days_in_month[current_month + 1] - 1 << endl;
//							cout << "current has: " << (int)days_in_month[current_month] << " days" << endl;
//							cout << "next has: " << (int)days_in_month[current_month + 1] << endl;
						}
					}
				}
				schedule.resize(days_in_month[current_month + 1], "");
//				cout << "size: " << schedule.size() << endl;
			}

			if(current_month < 11){
				current_month++;
			} else if (current_month == 11){
				current_month = 0;
			}

		} else if (str == "DUMP"){
			cin >> day;
			if ( day > 0 && days_in_month[current_month] ){
				size = schedule.size();
				if (schedule[day - 1] != ""){
					cout << count_words(schedule[day - 1]) << ' ' << schedule[day - 1] << endl;
				} else{
					cout << "0" << endl;
				}
			}
		} else if (str == "PRINT"){
			cout << "schedule: " << endl;
			for (uint32_t k = 0; k < schedule.size(); k++){
				if (schedule[k] != ""){
					cout << k + 1 << ". " << schedule[k] << endl;
				}
			}
		}

		day = 0;
		business = "";
	}

	return 0;
}

