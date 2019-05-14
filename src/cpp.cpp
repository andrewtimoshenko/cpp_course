
class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
	  str.push_back(s);
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
	  sort(str.begin(), str.end());
	  return str;
  }
private:
  // приватные поля
  vector <string> str;
};

