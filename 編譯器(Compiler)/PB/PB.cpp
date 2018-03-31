#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main() {
	regex sReg("^\"[a-z0-9A-Z]*\"$"),idReg("^[a-oqrt-z]$");
	bool valid = false;
	string insS, insP, idS, idP, s;
	cin >> insS; cin >> idS; cin >> s; cin >> insP; cin >> idP;
	if (insS == "s" && regex_match(idS, idReg) && regex_match(s, sReg) && insP == "p" && regex_match(idP,idReg))
		valid = true;
	if (valid)
		cout << "strdcl s" << endl << "id " << idS << endl << "quote \"" << endl << "string " << s.substr(1,s.length()-2) << endl << "quote \"" << endl << "print p" << endl << "id " << idP;
	else
		cout << "valid input";

	/*if (regex_match(s, sReg)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}*/

	//cout << insS << endl << idS << endl << s << endl << insP << endl << idP;

	system("pause");
	return 0;
}