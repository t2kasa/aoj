#define SUBMIT

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C
// Search - Dictionary

#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

int main() {
    int n;
    set<string> dict;
    vector<string> outputs;

    string s;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        if (s[0] == 'i') { // insert
            auto str = s.substr(7);
            dict.emplace(str);
        }
        else { // find
            auto str = s.substr(5);
            if (dict.find(str) != dict.end()) {
                outputs.emplace_back("yes");
            } else {
                outputs.emplace_back("no");
            }
        }
    }

    for (const auto& o: outputs) {
        cout << o << endl;
    }
    return 0;
}