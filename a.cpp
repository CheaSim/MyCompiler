// 编译原理作业1.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
using std::string;
class sym{
private:
	const int al = 32;
	string getword();
	bool is_char(char);
	bool is_num(char);
	bool is_blank(char);
	bool is_operator(char);
	bool is_delimiter(char);
	const string key[6] = { "main","int","if","else","while","do" };
public:
	void init();
	string prog;
};
int main()
{
    return 0;
}
void sym::init() {
	char ch;
	do {
		std::cin >> ch;
		prog += ch;
	} while (ch != EOF);
}
string sym::getword() {
	int st = 0;
	// str means the word
	do {
		std::cin >> ch;
	} while (ch == ' ');
	if (is_num(ch)) {
		str += ch;

	}
	return str;
}
bool sym::is_char(char _ch) {
	if (_ch <= 'z' && 'a' <= _ch) 
		return true;
	if (_ch <= 'Z' && 'A' <= _ch)
		return true;
	return false;
}
bool sym::is_num(char _ch) {
	if (_ch <= '9' && '0' <= _ch)
		return true;
	return false;
}
bool sym::is_blank(char _ch) {
	if (_ch == ' ' || _ch == '\t' || _ch == '\n') return true;
	return false;
}
bool sym::is_operator(char _ch) {
	if (_ch == '+' || _ch == '*' || _ch == '-' || _ch == '/' || _ch == '<' ||
		_ch == '>' || _ch == '!=' || _ch == '>=' || _ch == '<=' || _ch == '==')
		return true;
	return false;
}
bool sym::is_delimiter(char _ch) {
	if (_ch == ',' || _ch == ';' || _ch == '(' || _ch == ')' || _ch == '{' || _ch == '}')
		return true;
	return false;
}