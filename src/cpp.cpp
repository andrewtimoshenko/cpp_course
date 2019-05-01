#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;


int main() {
    int q;
    cin >> q;

    set <string> str_s;

    for (int i = 0; i < q; ++i) {

    	string str;
    	cin >> str;

    	str_s.insert(str);
    }

    int i = 0;
    for (auto item: str_s) {
    	if (str_s.count(item) == 1){
    		++i;
    	}
    }

    cout << i;

    return 0;
}
