#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
string generate_password(int password_length) {
	string password;
	string uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
	string alphanumeric_chars = "0123456789";
	string special_chars = "!#$%&<=>?@~";

	short int char_type;
	for(int i=0;i<password_length;++i) {
		char_type = rand() % 4;

		switch(char_type) {
			case 0:
				password += uppercase_chars[rand()%26];
				break;
			case 1:
				password += lowercase_chars[rand()%26];
				break;
			case 2:
				password += alphanumeric_chars[rand()%10];
				break;
			case 3:
				password += special_chars[rand()%11];
				break;
		}
	}
	return password;
}

int main(int argc,char *argv[]) {
	srand(time(0));
	int password_length;
	if(argc != 2)
		cout<<"Incorrect arguments\n";
	try {
		password_length = stoi(argv[1]);
	}
	catch(const invalid_argument& ia) {
		cerr<<"Invalid Argument :"<<ia.what()<<endl;
		return 0;
	}
	if(password_length > 30 || password_length < 7) {
		cout<<"Password length must be between 7 and 30\n";
		return 0;
	}

	string s = generate_password(password_length);
	cout<<"Generated Password is : "<<s<<endl;
	return 0;
}