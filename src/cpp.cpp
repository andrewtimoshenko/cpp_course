#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {

	uint32_t q = 0;
	cin >> q;

	map <string, set<string>> synonyms;

	for (uint32_t i = 0; i < q; i++){
		string operation;
		cin >> operation;

		if (operation == "ADD"){ // ADD word1 word2
			string word1, word2;
			cin >> word1 >> word2;

			if (synonyms.find(word1) != synonyms.end()){
				synonyms[word1].insert(word2);
			} else {
				set<string> s;
				s.insert(word2);
				synonyms[word1] = s;

				if (synonyms.find(word2) != synonyms.end()){
					synonyms[word2].insert(word1);
				} else {
					s.clear();
					s.insert(word1);
					synonyms[word2] = s;
				}
			}

		} else if (operation == "COUNT"){ // COUNT word
			string word;
			cin >> word;
			if (synonyms.find(word) != synonyms.end()){
				cout << synonyms[word].size() << endl;
			} else {
				cout << 0 << endl;
			}

		} else if (operation == "CHECK"){ //CHECK word1 word2
			string word1, word2;
			cin >> word1 >> word2;

			if (((synonyms.find(word1) != synonyms.end()) && (synonyms[word1].count(word2) > 0)) ||
				((synonyms.find(word2) != synonyms.end()) && (synonyms[word2].count(word1) > 0))){
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}

    return 0;
}
