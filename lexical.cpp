#include "lexical.h"

/*
<程序>::＝main（）{<分程序>}
<分程序>::=<变量说明部分>；<语句部分>
<变量说明部分>::=<变量说明><标识符表>
<变量说明>::=int
<标识符表>::=<标识符表>，<标识符>
<标识符表>::=<标识符>
<语句部分>::=<语句部分>；<语句>|<语句>
<语句>::＝<赋值语句>|<条件语句>|<循环语句>|
<赋值语句>::=<标识符>=<表达式>

<条件>::=<表达式><关系运算符><表达式>
<表达式>::=<项>|<表达式><加法运算符><项>

<项>::=<因子>|<项><乘法运算符><因子>
<因子>::＝<标识符>|<常量>|(<表达式>)


<复合语句>::={<语句部分>}
<语句1>::＝<语句>|<复合语句>
<条件语句>::=if（<条件>）<语句1>else<语句1>
<循环语句>::=while（<条件>）do<语句1>
*/
WORD Lexical::getWord() {
	analysis();
	return word;
}
void Lexical::analysis() {
	if (!flag) ch = getchar();
	while (is_blank(ch)) {
		col++;
		if (ch == '\n') {
			row++;
			col = 0;
		}
		ch = getchar();
		flag = true;
	}

	nowWord.clear();
	if (is_char(ch)) {
		col++;
		while (is_char(ch) || is_num(ch)) {
			nowWord += string(1, ch);
			ch = getchar();
			col++;
			flag = true;
		}
		col--;
		if (is_key(nowWord)) {
			word = WORD(nowWord, KEY, row, col);
		} else {
			wordID[nowWord] = ID++;
			word = WORD(nowWord, CHAR, row, col);
		}
	}
	else if (is_num(ch)) {
		col++;
		nowWord.clear();
		while (is_num(ch)) {
			col++;
			nowWord += string(1, ch);
			ch = getchar();
			flag = true;
		}
		col--;
		word = WORD(nowWord, NUMBER, row, col);
		if (is_char(ch)) {
			word = WORD("数字匹配失败", ERROR, row, col);
			flag = false;	
			return;
		}
	}
	else if (ch == '+' || ch == '-') {
		col++;
		nowWord += string(1,ch);
		flag = false;
		word = WORD(nowWord, ADD, row, col);
	}
	else if (ch == '*' || ch == '/') {
		col++;
		nowWord += string(1, ch);
		flag = false;
		word = WORD(nowWord, MUL, row, col);
	}
	else if (is_operator(ch)) {
		col++;
		nowWord += string(1, ch);
		bool fg = false;
		if (ch == '!') fg = true;
		ch = getchar();
		flag = true;
		// 判断关系运算符的时候，对于 '!'这个符号，后面必须
		//跟着 '=' 不然就是失去不等号的匹配 应当报错。
		if (fg && ch != '=') {
			word = WORD("感叹号失配", ERROR, row, col);
			return;
		}
		if (ch == '=') {
			col++;
			nowWord += string(1,ch);
			flag = false;
			word = WORD(nowWord, RELATION, row, col);
		}
		else if(nowWord == "="){
			word = WORD(nowWord, ASSIGN, row, col);
		} else {
			word = WORD(nowWord, RELATION, row, col);
		}
	}
	else if (is_delimiter(ch)) {
		col++;
		nowWord += string(1, ch);
		word = WORD(nowWord, DELIMITER, row, col);
		flag = false;
	}
	else{
		word = WORD("未知符号错误", ERROR, row, col);
		flag = true;
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
bool Lexical::is_operator(char ch) {
	if (ch == '=' || ch == '<' || ch == '>' || ch == '!') return true;
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