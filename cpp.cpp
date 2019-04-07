#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stl_pair.h>

using namespace std;

void print_map(const map<char, int>& m){
//	cout << "Size = " << m.size() << endl;
	for (const auto& item: m){
		cout << item.first << ": " << item.second << endl;
	}
}

// Буква уже в словаре? Нет - добавляем, Да - инкремент частоты в словаре
void char_counters(string word, map <char, int>& m){
	// Each letter
	for(auto ch: word){
		++m[ch];
	}
}

int main()
{
	int N = 0;
	map <char, int> char_freq_word1;
	map <char, int> char_freq_word2;
	string word1;
	string word2;

	char_counters(word1, char_freq_word1);

	cin >> N;

	for(int n = 0; n < N; n++){
		cin >> word1 >> word2;

		char_counters(word1, char_freq_word1);
		char_counters(word2, char_freq_word2);

		if(char_freq_word1 == char_freq_word2){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

		word1 = "";
		word2 = "";
		char_freq_word1.clear();
		char_freq_word2.clear();
}

	return 0;
}
