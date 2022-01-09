/*
���ڲ��������Զ�������������
��ɹ���
*/
#include<bits/stdc++.h>
using namespace std;

class Book{
public:
	int uid;
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* ����ĸ,�������/������� */
	string Divider[3];//�����˲���,�ּ��ȽϷ���ΪD1,D12,D123
	//����ֱ�ӳ鼶��ѯ
	//string &P[3] = {title, writer, ISBN};//�������������㰴״̬�����
	string *P[3];//����ʹ��ָ��...
	bool flag;
	Book(){//Ĭ�Ϲ��콫ָ�����鶨��Ԫ�ط���˳�����
		//P[3] = {&title, &writer, &ISBN};
		flag = false;
		P[0] = &title, P[1] = &writer, P[2] = &ISBN;
	};
	Book(const Book &t){//������ָ��Ŀ���
		flag = t.flag;
		P[0] = &title, P[1] = &writer, P[2] = &ISBN;
		title = t.title, writer = t.writer, ISBN = t.ISBN;
		for(int i = 0; i < 3; i ++)Divider[i] = t.Divider[i];
	}
	bool SetDivider(const string &s){
		Divider[0] = s;
		bool flag = 0;
		for(int i = 0; i < (int)Divider[0].size(); i ++){//�ֽ�3������
			if(Divider[0][i] == '/'){
				Divider[1] = Divider[0].substr(1, i - 1);//�� 0 �� i - 1
				Divider[2] = Divider[0].substr(i + 1);//��i + 1���ַ���ĩβ
				Divider[0] = Divider[0].substr(0, 1);//����
				Divider[1] = Divider[0] + Divider[1];//D2��ΪD12
				Divider[2] = Divider[1] + Divider[2];//D3��ΪD123
				flag = 1;
				break;
			}
		}
		return flag;
	}
	template<class I>
	friend I& operator >>(I& in, Book& book);
	template<class O>
	friend O& operator <<(O& out, const Book& book);
	//friend void test(const int &op);
	void Print(){//���ҵ�֮��������ȫ����Ϣ
		cout << "<<" << title << ">>" << endl;
		cout << "Writer: " << writer << endl;
		cout << "ISBN: " << ISBN << endl;
	}//Ҳ����ֱ��ʹ�� cout << �������
};

/* ���ض�������� */
template<class I>
I& operator >>(I& in, Book& book){
	book.flag = true;//����
	in >> book.title >> book.ISBN >> book.writer >> book.Divider[0];
	in.ignore(1024, '\n');//������ĩ�����ַ�
	for(int i = 0; i < (int)book.Divider[0].size(); i ++){//�ֽ�3������
		if(book.Divider[0][i] == '/'){
			book.Divider[1] = book.Divider[0].substr(1, i - 1);//�� 0 �� i - 1
			book.Divider[2] = book.Divider[0].substr(i + 1);//��i + 1���ַ���ĩβ
			book.Divider[0] = book.Divider[0].substr(0, 1);//����
			book.Divider[1] = book.Divider[0] + book.Divider[1];//D2��ΪD12
			book.Divider[2] = book.Divider[1] + book.Divider[2];//D3��ΪD123
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
	out << book.Divider[2].substr(book.Divider[1].size()) << '\n';//��ԭ���ݸ�ʽ
	return out;
}
/* ���ض��������� */
/*
���������ֺ��񲢲��Ǻ����ף���Ҫ���صĻ�������Ҫ������ĩβ��ӽ�����־(������)��
������Ҫ�������ʱ�򲢲��Ǻܶ࣬��Ҫ�Ļ�ֱ�Ӱ�������ѭ������ɡ�
template<class O>
O& operator <<(O& out, Book* book){	}
*/


/*
int main(){
	freopen("intest.txt", "r", stdin);//���ļ�intest����
	Book book[10];
	cin >> book;
	cout << book[3] << endl;
	//cout << "����GBK!" << endl;
	return  0;
}

*/