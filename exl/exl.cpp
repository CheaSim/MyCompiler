// 编译原理作业1.cpp : Defines the entry point for the console application.
//
#include "lexical.h"

bool Lexical::get_line() {
	row++;
	return getline(cin, nowRow);
}
void Lexical::analysis() {
	int col = 0;
	int len = nowRow.size();
	for (col; col < len; col++) {
		char ch = nowRow[col];
		if (is_char(ch)) {
			int ed = col+1;
			while (ed < len && (is_num(nowRow[ed]) || is_char(nowRow[ed])))
				ed++;
			string nowWord = get_word(nowRow,col,ed);
			if (is_key(nowWord)) {
				cout << "(  " << nowWord << "  )" << "保留字" << endl;
			}
			else{
				if (wordID[nowWord] == 0) wordID[nowWord] = ID++;
				cout << "(  " << nowWord << "  )" << "标识符ID:" <<wordID[nowWord]<< endl;
			}
			col = ed-1;
		}
		else if (is_num(ch)) {
			int ed = col+1;
			while (ed < len && (is_num(nowRow[ed])))
				ed++;
			if (is_char(nowRow[ed])) {
				cout <<"标识符匹配错误     "<< "error at row " << row << " colum" << col << "!" << endl;
				while (is_char(nowRow[ed])) ed++;
				col = ed;
				continue;
			}
			string nowWord = get_word(nowRow, col, ed);
			cout << "(  " << nowWord << "  )" << "无符号整数"  << endl;
			col = ed-1;
		}
		else if (is_operator(string(1,ch))) {
			int ed = col+1;
			int cnt = 0;
			if (ed < len && nowRow[ed] == '=') ed++;
			string nowWord = get_word(nowRow, col, ed);
			if (is_operator(nowWord)) {
				if (nowWord[0] == '-' || nowWord[0] == '+') {
					cout << "(  " << nowWord << "  )" << "加法运算符"
						<< endl;
				}
				else if (nowWord[0] == '*' || nowWord[0] == '/') {
					cout << "(  " << nowWord << "  )" << "乘法运算符"
						<< endl;
				}
				else if(nowWord.size() == 2){
					if (nowWord[1]=='=') {
						cout << "(  " << nowWord << "  )" << "关系运算符"
							<< endl;
					}
				}else if(nowWord == "!"){
                        cout << "运算符匹配错误   " << "error at row " << row << " colum" << col << "!" << endl;
                }
			}
			else if(nowWord.size()==2){
				cout <<"运算符匹配错误   "<< "error at row " << row << " colum" << col << "!" << endl;
			}
			col = ed-1;
		}
		else if (is_delimiter(ch)) {
			cout << "(  " << ch << "  )" << "分界符"
				<< endl;
		}
		else if (is_blank(ch)) {

		}
		else {
			cout << "未知字符     " << "error at row " << row << " colum" << col << "!" << endl;
		}
	}
}
bool Lexical::is_char(char _ch) {
	if (_ch <= 'z' && 'a' <= _ch)
		return true;
	if (_ch <= 'Z' && 'A' <= _ch)
		return false;
	return false;
}
bool Lexical::is_num(char _ch) {
	if (_ch <= '9' && '0' <= _ch)
		return true;
	return false;
}
bool Lexical::is_blank(char _ch) {
	if (_ch == ' ' || _ch == '\t' || _ch == '\n') return true;
	return false;
}
bool Lexical::is_operator(string s) {
	if (s.size() == 1 && s == "=" || s == "!") return true;
	if (s.size() == 1 && s == "+" || s == "-" || s == "*" || s == "/" || s == "<" || s == ">"
		) return true;
	if(s.size() == 2 && s == "!=" || s == ">=" || s == "<=" || s == "==")
		return true;
	return false;
}
bool Lexical::is_delimiter(char _ch) {
	if (_ch == ',' || _ch == ';' || _ch == '(' || _ch == ')' || _ch == '{' || _ch == '}')
		return true;
	return false;
}
bool Lexical::is_key(string _s) {
	for (int i = 0; i < keyNum; i++) {
		if (_s == key[i]) return true;
	}
	return false;
}
string Lexical::get_word(string str, int st, int ed) {
	string temp;
	for (int i = st; i < ed; i++)
		temp += str[i];
	return temp;
}
void Lexical::run() {
	while (get_line()) {
		analysis();
	}
	cout << "程序运行结束咯！" << endl;
}
int main()
{
    ifstream in;
    freopen("input.txt","r",stdin);
	Lexical lex;
	lex.run();
	in.close();
	return 0;
}
