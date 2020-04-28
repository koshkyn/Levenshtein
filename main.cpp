#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int Levenshtein(const string& longs, const string& shorts) {
    vector<int> v1(shorts.size() + 1);
    vector<int> v2(shorts.size() + 1, 0);
    iota(v2.begin(), v2.end(), 0);
    for(size_t i = 1; i <= longs.size(); ++i) {
        swap(v1, v2);
        v2[0] = i;
        for(size_t j = 1; j <= shorts.size(); ++j) {
            v2[j] = min(min((v1[j] + 1), (v2[j - 1] + 1)), v1[j - 1] + (longs[i - 1] != shorts[j - 1]));
        }
    }
    return v2[shorts.size()];
}

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    if(s1.size() > s2.size()) {
        swap(s1, s2);
    }
    cout << Levenshtein(s1,s2) << endl;
    return 0;
}
