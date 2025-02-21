#include <iostream>
#include <string>
#include <set>

using namespace std;
int countStrings(const string& S) {
	set<string> strings;
	for (int i = 0; i < S.size(); i++) {
		for (int j = i + 1; j <= S.size(); j++)
			strings.insert(S.substr(i, j - i));
	}
	return strings.size();
}

int main() {
	string S;
	cin >> S;
	int result = countStrings(S);
	cout << result << ' ';
	return 0;
}
