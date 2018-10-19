#ifndef LEXICAL_H_INCLUDED
#define LEXICAL_H_INCLUDED
#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
#include<fstream>
using namespace std;

class Lexical {
private:
	const string key[6] = { "main","int","if","else","while","do" };
	string nowRow;
	int row = 0;
	const int keyNum = 6;
	map<string, int> wordID;
	int ID = 6;
private:
	void analysis();
	bool get_line();
	bool is_char(char);
	bool is_num(char);
	bool is_key(string);
	bool is_blank(char);
	bool is_operator(string);
	bool is_delimiter(char);
	string get_word(string,int,int);
public:
	void run();
};


#endif // LEXICAL_H_INCLUDED
