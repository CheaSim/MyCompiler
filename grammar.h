#pragma once

#include"defination.h"
#include"lexical.h"

/*
S是开始的程序入口，A是main(){B}，B是分程序
Def是程序的申明部分。
List是程序的标识符表定义部分，为声明部分的衍生。
F表示语句部分
*/

/*
S 程序
A main(){B}
B 分程序
Def 变量说明部分
List 标识符表
F 语句部分
X 赋值语句
Y 条件语句
Z 循环语句
E 表达式
G 项
YZ 因子
FY 复合语句
YU 语句
YU1 语句1
FI 条件

S->A
A->main(){B}
b->Def;F
Def->int LIST
LIST->C LIST'
LIST'->,C LIST'| NONE

F 是语句部分的意思
YU 是语句的意思
F1 是消除左递归后产生的东西

F->YU F'
F'-> ; YU F'
YU1->YU| FY
YU->X|Y|Z
X->C=E;.KPO
FI->EguanE
E->G|G+E
G->YZ|YZchengG
YZ->C|ang|(E)
FH->{F}
Y->if(FI)YU1 else YU1
Z->while(FI) do YU1

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

<标识符>::=<字母>
<标识符>::=<标识符><字母>
<标识符>::=<标识符><数字>
<关系运算符>::＝<|>|!=|>=|<=|==
<常量>::＝<无符号整数>
<无符号整数>::=<数字序列
<关系运算符>::＝<|>|!=|>=|<=|==
<数字序列>::=<数字序列><数字>
<数字序列>::=<数字>
<加法运算符>::＝ +|-
<乘法运算符>::= *|／


*/

struct Four {
	string op, sym1, sym2, res;
	Four() {}
	Four(string a, string b, string c, string d) {
		op = a;
		sym1 = b;
		sym2 = c;
		res = d;
	}
};
class Grammar {
private:
	void GetNewWord();
	void parseS();
	void parseA();
	void parseB();
	void parseDef();
	void parseList();
	void parseList1();
	void parseF();
	void parseF1();
	void parseCOP();
	void parseYU();
	void parseYU1();
	void parseX();
	void parseDEX(string );
	string parseE();
	string parseG();
	string parseW(string);
	string parseT();
	string parseV(string );
	void parseY();
	void parseZ();
	WORD errors(string );
	void parseCMP();
public:
	void run();
private:
	Lexical lex;
	vector<WORD> errorTable;
	map<string, int> wordID;
	WORD nowWord;
	int regcnt = 0;
	vector<Four> Fours;
	vector<string> Format;
	void makeFour(string, string, string, string);
public:
	Grammar() {
		// 从1开始
		Fours.push_back(Four());
	}
	void showCode();
	void showFour();
	void debug();
};