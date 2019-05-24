#pragma once

#include"defination.h"
#include"lexical.h"

/*
S�ǿ�ʼ�ĳ�����ڣ�A��main(){B}��B�Ƿֳ���
Def�ǳ�����������֡�
List�ǳ���ı�ʶ�����岿�֣�Ϊ�������ֵ�������
F��ʾ��䲿��
*/

/*
S ����
A main(){B}
B �ֳ���
Def ����˵������
List ��ʶ����
F ��䲿��
X ��ֵ���
Y �������
Z ѭ�����
E ���ʽ
G ��
YZ ����
FY �������
YU ���
YU1 ���1
FI ����

S->A
A->main(){B}
b->Def;F
Def->int LIST
LIST->C LIST'
LIST'->,C LIST'| NONE

F ����䲿�ֵ���˼
YU ��������˼
F1 ��������ݹ������Ķ���

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

<��ʶ��>::=<��ĸ>
<��ʶ��>::=<��ʶ��><��ĸ>
<��ʶ��>::=<��ʶ��><����>
<��ϵ�����>::��<|>|!=|>=|<=|==
<����>::��<�޷�������>
<�޷�������>::=<��������
<��ϵ�����>::��<|>|!=|>=|<=|==
<��������>::=<��������><����>
<��������>::=<����>
<�ӷ������>::�� +|-
<�˷������>::= *|��


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
		// ��1��ʼ
		Fours.push_back(Four());
	}
	void showCode();
	void showFour();
	void debug();
};