#include<iostream>
#include<string>
#include<regex>
using namespace std;
int main() {

	regex pattern(".*noodles.*");
	int Fs, Ns;
	string s;

	getline(cin, s);
	Fs = s.find("Favorite", 0);
	getline(cin, s);
	while (s != ""){
		if (regex_match(s, pattern)) {
			Ns = s.find("noodles", 0);
			if (Fs == Ns) {
				cout << s << endl;
			}
		}
		getline(cin, s);
	}

	system("pause");
	return 0;
}