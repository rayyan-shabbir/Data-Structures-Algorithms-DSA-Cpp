#include "iostream"
using namespace std;


int main() {
	string str = {" "};
	cin >> str;

	int l = 0, count = 0;

	while(l < str.length()) {
		if(str[l] == ',') count++;

		l++;
	}

	string *digits;
	digits = new string[count+1];

	int *num = new int[count+1];

	int j = 0;
	int i = 0;

	while(i < str.length()) {
		if(str[i] != ',') digits[j] += str[i];
		else {
			num[j] = stoi(digits[j]);
			j++;
		}
		i++;
	}
	
	for(int i = 0; i < count+1; i++)
		cout << num[i] << endl;
	return 0;
}