#include<iostream>
#include<string>
#include<regex>
using namespace std;
int main() {
	regex pattern("[a-zA-Z0-9$_]*cpy[a-zA-Z0-9$_]*");
	smatch sm;
	string s;
	getline(cin, s);
	while (s != "") {
		while (regex_search(s,sm,pattern)) {
			for (int i = 0; i < sm.size();i++) {
				cout << sm[i] << endl;
			}
			s = sm.suffix().str();
		}
		getline(cin, s);
	}
	system("pause");
	return 0;
}
