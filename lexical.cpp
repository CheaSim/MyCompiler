#include "lexical.h"

/*
<����>::��main����{<�ֳ���>}
<�ֳ���>::=<����˵������>��<��䲿��>
<����˵������>::=<����˵��><��ʶ����>
<����˵��>::=int
<��ʶ����>::=<��ʶ����>��<��ʶ��>
<��ʶ����>::=<��ʶ��>
<��䲿��>::=<��䲿��>��<���>|<���>
<���>::��<��ֵ���>|<�������>|<ѭ�����>|
<��ֵ���>::=<��ʶ��>=<���ʽ>

<����>::=<���ʽ><��ϵ�����><���ʽ>
<���ʽ>::=<��>|<���ʽ><�ӷ������><��>

<��>::=<����>|<��><�˷������><����>
<����>::��<��ʶ��>|<����>|(<���ʽ>)


<�������>::={<��䲿��>}
<���1>::��<���>|<�������>
<�������>::=if��<����>��<���1>else<���1>
<ѭ�����>::=while��<����>��do<���1>
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
			word = WORD("����ƥ��ʧ��", ERROR, row, col);
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
		// �жϹ�ϵ�������ʱ�򣬶��� '!'������ţ��������
		//���� '=' ��Ȼ����ʧȥ���Ⱥŵ�ƥ�� Ӧ������
		if (fg && ch != '=') {
			word = WORD("��̾��ʧ��", ERROR, row, col);
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
		word = WORD("δ֪���Ŵ���", ERROR, row, col);
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