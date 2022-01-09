#include<bits/stdc++.h>
#include "Read.cpp"
using namespace std;
void RootSearch(const int &op, Book *Data);
void StepSearch(Book *Data);
template<class T>
struct node{//����
	T *u;
	node *next;
};

int cnt = 0;
Book book[10];
bool check[10];//�����Ч����
/*
���ܣ�
1. ������ȷ����
2. ISBN��ȷ����
3. ���ߣ�ȫ������
4. �����������
*/

void Search(){
	string op;
	while(cin >> op){
		if(op == ":return")return;
		RootSearch(op[0], book);
	}
}

void RootSearch(const char op, Book *Data){//��Ĭ�����ݿ⵱������
	//Ĭ������·��ΪData
	string s;//ƥ�䴮
	if('1' <= op && op <= '3'){
		cin >> s;
		for(int i = 0; i <= cnt; i ++){
			if(*Data[i].P[op - '1'] == s){
				Data[i].Print();
			}
		}
	}else if(op == '4'){
		StepSearch(Data);
	}
}

inline void StepSearch(Book *Data){
	string op;//����
	string s;
	while(cin >> op){
		if(op == ":return")return;
		cin >> s;
		int now = op[0] - '1';
		for(int i = 0; i <= cnt; i ++){
			if(Data[i].Divider[now] == s){
				Data[i].Print();
			}
		}
	}
}

void load(){
	//freopen("intest.txt", "r", stdin);//���ļ�intest����
	//����ifstreamģʽ
	ifstream infile;
	infile.open("intest.txt");
	while(infile >> book[cnt]){
		cnt ++;
	}
	//fclose(stdin);
}

int main(){
	load();
	//freopen("con", "r", stdin);//�ض��򵽿���̨
	//ʧ����
	/* test */
	cout << book[3] << endl;
	char op;
	cin >> op;
	RootSearch(op, book);

	return 0;
}
