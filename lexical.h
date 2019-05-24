#pragma once
#ifndef LEXICAL_H_INCLUDED
#define LEXICAL_H_INCLUDED
#pragma once

#include"defination.h"
using namespace std;

/*
	��ʵ��Ҫ�ķ�������Ϊanalysis(),
	key������6���ؼ���
	row��col��¼�˵�ǰ�кź͵�ǰ�к�
	wordID����¼��ʶ����ʹ����map�����ݽṹ��map�Ǻ�����ṹ������Ҹ��Ӷ� O(nlog(n))
*/
class Lexical {
private:
	const string key[6] = { "main","int","if","else","while","do" };
	WORD word;
	string nowRow;
	int row = 1; int col = 1;
	const int keyNum = 6;
	map<string, int> wordID;
	int ID = 6;
	string nowWord;
	/*
	ch, flag,����������ʹ�����ǿ��Զ������ӵĵ��ʽ��з�������Ȼ�ȶ�����һ���ַ�֮�󣬺�����ٶ�����һ���ַ�
	eg: int a=b;   ���ж�a��ʱ�����ǻ����a�����һ���ַ�����ʱ��Ͱ� '=' �����ȥ�ˡ� ����һ���жϵ�ʱ�򣬾Ͳ���ֱ�Ӷ�����һ���ַ�
	����ʹ���ϴζ�����ַ���
	*/
	char ch;
	bool flag;
private:
	void analysis();

	bool is_char(char); // �ж��Ƿ�Ϊ��ĸ
	bool is_num(char); // �ж��Ƿ�������
	bool is_key(string);  // �ж��Ƿ��ǹؼ���
	bool is_blank(char);  // �ж��Ƿ�Ϊ�ո� ���� �Ʊ�
	bool is_operator(char);  // �ж��Ƿ�Ϊ��ϵ�����
	bool is_delimiter(char); // �ж��Ƿ��Ƿֽ��
public:
	WORD getWord();
};


#endif // LEXICAL_H_INCLUDED