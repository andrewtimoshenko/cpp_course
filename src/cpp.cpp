/* Задание по программированию: Имена и фамилии — 1 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {

public:

	// добавить факт изменения имени на first_name в год year
	void ChangeFirstName(int year, const string& first_name) {

	}

	// добавить факт изменения фамилии на last_name в год year
	void ChangeLastName(int year, const string& last_name) {

	}

	// получить имя и фамилию по состоянию на конец года year
	string GetFullName(int year) {
		string fullname;

		return fullname;
	}

private:
	map <int, string> firstnames;
	map <int, string> lastnames;
};

/* */

int main() {

	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");

	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");

	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");

	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

/*

Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova

*/

  return 0;
}
