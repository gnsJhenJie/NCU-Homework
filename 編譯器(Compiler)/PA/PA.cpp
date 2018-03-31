#include<iostream>
#include<string>
using namespace std;

bool IsInt(string s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	string id;
	string equal;
	string num;
	cin >> id;
	cin >> equal;
	cin >> num;
	if (id[0] >= 97 && id[0] <= 122 && id.length() == 1) {
		if (equal == "=") {
			if (IsInt(num)) {
				cout << "id " << id << endl << "assign " << equal << endl << "inum " << num;
			}
			else {
				cout << "valid input";
			}
		}
		else {
			cout << "valid input";
		}
	}
	else {
		cout << "valid input";
	}
	
	


	system("pause");
	return 0;
}