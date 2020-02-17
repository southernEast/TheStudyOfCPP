#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

bool noSym(char ch) {
	if (ch == '.' || ch == ',' || ch == '!'
		|| ch == ';' || ch == ':' || ch == '('
		|| ch == ')')
		return false;
	else
		return true;
}

bool testPalindrome(string str) {
	string noSymStr, reStr;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	copy_if(str.begin(), str.end(), back_inserter(noSymStr), noSym);
	/*for (auto elem : noSymStr)
		cout << elem;*/
	reStr = noSymStr;
	reverse(reStr.begin(), reStr.end());
	for (int i = 0; i < noSymStr.size(); ++i) {
		if (noSymStr[i] != reStr[i])
			return false;
	}
	return true;
}

int main() {
	string str;
	getline(cin, str);
	cout << boolalpha << testPalindrome(str);

	return 0;
}
