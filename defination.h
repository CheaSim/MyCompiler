#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
#include<fstream>

using namespace std;
enum words {
	CHAR,KEY,NUMBER,ADD,MUL,RELATION, ASSIGN, DELIMITER,ERROR,UNDEFINED
	,FUZHI
};
// ��ʶ�� �ؼ��� ���� �ӷ�
struct WORD {

	string word;
	int type;
	int row;
	int col;
	WORD() {}
	WORD(string wd, words tp, int r, int l) {
		word = wd;
		type = tp;
		row = r;
		col = l;
	}
};