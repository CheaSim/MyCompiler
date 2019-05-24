#pragma once
#ifndef LEXICAL_H_INCLUDED
#define LEXICAL_H_INCLUDED
#pragma once

#include"defination.h"
using namespace std;

/*
	其实主要的分析函数为analysis(),
	key保存了6个关键字
	row和col记录了当前行号和当前列号
	wordID来记录标识符，使用了map的数据结构，map是红黑树结构，最坏查找复杂度 O(nlog(n))
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
	ch, flag,这两个变量使得我们可以对于连接的单词进行分析，不然先读入了一个字符之后，后面就少读入了一个字符
	eg: int a=b;   在判断a的时候我们会读入a后面的一个字符，这时候就把 '=' 读入进去了。 在下一次判断的时候，就不能直接读入下一次字符
	而是使用上次读入的字符。
	*/
	char ch;
	bool flag;
private:
	void analysis();

	bool is_char(char); // 判断是否为字母
	bool is_num(char); // 判断是否是数字
	bool is_key(string);  // 判断是否是关键字
	bool is_blank(char);  // 判断是否为空格 换行 制表
	bool is_operator(char);  // 判断是否为关系运算符
	bool is_delimiter(char); // 判断是否是分界符
public:
	WORD getWord();
};


#endif // LEXICAL_H_INCLUDED