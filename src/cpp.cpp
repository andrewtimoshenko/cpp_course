#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
  int q;
  cin >> q;

  /*
   * Не нужно ничего усложнять!
   * Просто нужно использовать те вещи, которые дали в уроках
   * и не придумывать лишнего!
   */


  map<string, set<string>> synonyms;

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "ADD") {

      string first_word, second_word;
      cin >> first_word >> second_word;

      // второе слово добавляем в список синонимов первого...
      synonyms[first_word].insert(second_word);
      // и наоборот
      synonyms[second_word].insert(first_word);
      // Не нужно искать есть ли уже слово в словаре или во множестве
      // дубли не будут добавляться и контейнеры уже отсортированы!
    } else if (operation_code == "COUNT") {

      string word;
      cin >> word;
      cout << synonyms[word].size() << endl;
      // для вывода кол-ва синонимов просто выводим размер множества соответствующего слова!
    } else if (operation_code == "CHECK") {

      string first_word, second_word;
      cin >> first_word >> second_word;

      // ищём второе слово во множестве синонимов первого
      // (можно было сделать и наоборот)
      if (synonyms[first_word].count(second_word) == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      // просто по соответствующему слову ищем в его множестве синоним
    }
  }

  return 0;
}
