/*
��������ͼ��ݵĸ��ֲ��ҹ���
*/
#include<bits/stdc++.h>
using namespace std;


class Book{
private:
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* ����ĸ,�������/������� */
	string Divider[3];
public:
	void SetDivider(const string &&_Divider){
		Divider[0] = _Divider.substr(0, i);//�� 0 �� i - 1
		Divider[1] = _Divider.substr(i + 1);//��i + 1���ַ���ĩβ
	}
	Book(){}
	Book(const string &&_title, const string &&_writer, const string &&_ISBN){
		title = _title, writer = _writer, ISBN = _ISBN;
	};
	//~Book(){}��Ϊû��ָ�����Ĭ�ϵ�����
};


template<class T>//����
struct node{
	T u;
	*T next;
};

class Lib{//ͼ��ݹ���
private:
	//Book *books;//����ṹͼ��
	Book *head;//����ṹͼ��ͷ
public:
	//Lib(){};
	void load(){}
	void run(){};
};

void Lib::load(){//�������ݣ�

}

/*
���ܣ�
1. ������ȷ����
2. ISBN��ȷ����
3. ���ߣ�ȫ������
4. �����������
*/

/*
���ȳ���ȫ��ʹ�ñ����ķ�ʽ����
*/

void search(int op, const char *s){
	if(op == 1){//
		
	}
}

void Lib::run(){
	/*����ʵ��һ��ȫ�ֵĶ����*/
	string UsrInput;//�û�����
	int Page = 0;//�û�ҳ��״̬�룬���ڱ���û����ĸ�ҳ��
	while(cin >> UsrInput){//���д�������ˢ��
		search(UserInput);
	}
}

int main(){
	sync_with_stdio(false);//�ر�ͬ������
	cin.tie(0);
	Lib Test;
	Test.load();
	Test.run();
	return 0;
}