/*
testSearch
*/
#include<bits/stdc++.h>
using namespace std;
template<class T>//����
struct node{
	T *u;
	node *next;
};
void Search(const int &op, char *s);
class Book{
private:
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* ����ĸ,�������/������� */
	string Divider[3];//����ĸҲ�÷ֽ�...
	//string &P[3] = {title, writer, ISBN};//�������������㰴״̬�����
	//����ʧ�ܣ�c++���������������͵����飬����������ʱ����Ҫ��ʼ�����������޷�����һ�������ʼ����
	string *P[3];//����ʹ��ָ��...
public:
	Book(){//Ĭ�Ϲ��콫ָ�����鶨��Ԫ�ط���˳�����
		//P[3] = {&title, &writer, &ISBN};
		P[0] = &title, P[1] = &writer, P[2] = &ISBN;
	};
	Book(const Book &t){//ȡ����ָ��Ŀ���
		title = t.title, writer = t.writer, ISBN = t.ISBN;
		for(int i = 0; i < 3; i ++)Divider[0] = t.Divider[0];
	}
	template<class I>
	friend I& operator >>(I& in, Book& book);
	template<class O>
	friend O& operator <<(O& out, const Book& book);
	friend void RootSearch(const int &op);
	void Print(){//���ҵ�֮��������ȫ����Ϣ
		cout << "<<" << title << ">>" << endl;
		cout << "Writer: " << writer << endl;
		cout << "ISBN: " << ISBN << endl;
	}//Ҳ����ֱ��ʹ�� cout << �������
};
/* ���ض�������� */
template<class I>
I& operator >>(I& in, Book& book){
	in >> book.title >> book.ISBN >> book.writer >> book.Divider[0];
	in.ignore(1024, '\n');//������ĩ�����ַ�
	for(int i = 0; i < (int)book.Divider[0].size(); i ++){//�ֽ�3������
		if(book.Divider[0][i] == '/'){
			book.Divider[1] = book.Divider[0].substr(0, i);//�� 0 �� i - 1
			book.Divider[2] = book.Divider[0].substr(i + 1);//��i + 1���ַ���ĩβ
			book.Divider[0] = book.Divider[0].substr(0, 1);//����
			break;
		}
	}
	return in;
}
/* ���ض����������� */
template<class I>
I& operator >>(I& in, Book* book){
	while(in >> *book){
		book ++;
	}
	return in;
}
/* ��������� */
template<class O>
O& operator <<(O& out, const Book& book){
	out << book.title << ' ';//�ڿ���Ҫ��Ҫʹ�û��У���Ϊbook.txt����ʹ�õ��ǿո񣬵��Ǻ���Ҳû��ʲôӰ�졣
	out << book.ISBN << ' ';//�и�ϸ�ھ��Ǵ�book.txt�����ʱ��ĩβ��һ�� 1 ����֪���ǲ���Ϊ�˷�����Ϊ�˱�ʶ����
	out << book.writer << ' ';//Ӧ��ûʲôӰ��ɣ���Ҫ�� in.ignore(1024, '\n'); ��һ�г�����
	out << book.Divider[1] << '/';
	out << book.Divider[2].substr(book.Divider[1].size()) << '\n';
	return out;
}

node<Book> Head;//�洢����ͷ

void Borrow(){
	cout << "Do you want to borrow this book?" << endl;
}

/*
���ܣ�
1. ������ȷ����
2. ISBN��ȷ����
3. ���ߣ�ȫ������
4. �����������
*/
/*
void Search(const int &op, string &s){//״̬��,
	if(op == 1){//title
		node<Book> now = Head;
		while(){//˳���������
			if(now.u -> title == s){
				now.u -> Print();
				Borrow();
				break;
			}
			if(now.next -> u == Head.u)break;
		}
	}else if(op == 2){//ISBN
		node<Book> now = Head;
		while(){//˳���������
			if(now.u -> ISBN == s){
				now.u -> Print();
				Borrow();
				break;
			}
			if(now.next -> u == Head.u)break;
		}
	}else if(op == 3){//writer
		node<Book> now = Head;
		while(){//˳���������
			if(now.u -> writer == s){
				now.u -> Print();
			}
			if(now.next -> u == Head.u)break;
		}
		Borrow();
	}else if(op == 4){//3Divider
		
	}else{
		cout << "Invalid Input!" << endl;
	}
}
*/
//д��̫���ˣ��о���Ҫ��ÿ�����������������
/*
void Search(int op){//�����ⲿ����״̬��
	node<Book> HeadTmp = Head;//��ʱ������ͷ
	string s;//ƥ����ı�
	if(1 <= op && op <= 3){
		cin >> s;
		node<Book> now = HeadTmp;//��ȡ����ͷ
		while(now.next -> u != HeadTmp.u){//˳���������
			if(*(now.u -> P[op-1]) == s){
				now.u -> Print();
				//Borrow();
				//break;
			}
		}
	}else if(op == 4){//3Divider
		list<Book> q;//���ڴ����ʱ�����Ķ���(Ϊ��֧�ֵ�������������list)
		cin >> s;
		node<Book> now = HeadTmp;//��ȡ����ͷ
		while(now.next -> u != HeadTmp.u){//��һ��˳���������
			if(now.u -> Divider[0] == s){
				q.push_back(*now.u);
			}
		}
		for(list<Book>::iterator it = q.begin(); it != q.end(); it ++){
			cout << *it ;
		}//��һ����������
		for(int i = 1; i <= 2; i ++){//������˳�����list
			Book Begin = q.back();//��ȡlistβ�����ж�ѭ������
			Book u = q.front();
			do{
				u = q.front();//listͷ
				q.pop_front();//�����Ѿ���ȡ��listͷ
				if(u -> Divider[i] == s)q.push_back(u);
			}while(q.front() != Begin);
			for(list<Book>::iterator it = q.begin(); it != q.end(); it ++){
				cout << *it ;
			}//��һ����������
		}
	}else{
		cout << "Invalid Input!" << endl;
	}
}
*///�ٴ�дը���о��������ô�ָ��

void Search(const int &op){
	node<Book> HeadTmp = Head;//��ʱ������ͷ
	cout << *(Head.u -> P[0]) << endl;
	string s;//ƥ���ı�
	if(1 <= op && op <= 3){
		cin >> s;//����ƥ���ı�
		node<Book> now = HeadTmp;
		while(now.next -> u != HeadTmp.u){//˳���������
			if(*(now.u -> P[op-1]) == s){
				now.u -> Print();//�ҵ������
			}
		}
	}else if(op == 4){//3Divider
		
	}
}
int main(){
	int op;
	while(cin >> op){
		Search(op);//����״̬��
	}
	return 0;
}

/*
����ʵ��ģ��:
����1:
1.�����
�����Ϊ��㴫��ʽ��ÿһ���ȶ���Ϣ���й��ˣ�Ȼ�󴫸���һ��
2.������
����ʵ��,�Ӵ洢���ж�ȡ�ʹ������ݾ�����Զ��ָ��ģʽ
3.�洢��
��������洢��,���ڳ����ڲ��Ĵ洢
���̴洢��,���ⲿ�洢��
*/
