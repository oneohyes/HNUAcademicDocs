#include<bits/stdc++.h>
using namespace std;
class Manager{
private:
	int num;//�û����� 
	int bnum;
	string mcode;//����Ա���� 
	string mid="����֮��";//����Ա�˺� 
	bool flag=false;
public:
	void ManagerCode(string &s)
	{
		mcode="123456";
		mcode = s;
	}
	bool Managerin(string &s1,string &s2)//�˺ŵ�½ 
	{
		if(s1==mid&&s2==mcode)flag=true;
		return flag;
	}
    void addAccount() //���ѧУ�û�Ĭ���˺ź����� 
	{
		User *user;
		int addNum = 0;//������� 
		cin >> addNum;
		if (addNum <= 0) {
			
			cin >> addNum;
		}
		int newSize = this->num + addNum;//�¿ռ�����=ԭ����¼������+���ڼ��������
		//�����¿ռ�
		User** newSpace = new User * [newSize];

		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->array != NULL) {
			for (int i = 0; i < this->num; i++) {
				newSpace[i] = this->array[i];
			}
		}
		//���������
		for (int j = 0; j < addNum; j++) {
		     string id;
		     cin>>id;
		     string code="123456";
		     user=new User(id,code);
		     newSpace[this->num+j]=user;
		 }
		//�ͷ�ԭ�еĿռ�
		delete[]this->array;
		//�����¿ռ��ָ��
		this->array = newSpace;
		//�����µ�ְ������
		this->num = newSize;
    }
    void deleteAccount() {
		string id;
		cin >> id;
		int index; 
		if(index>0)
		{
			//������ǰ�ƣ���ָ��Ԫ�ؽ���ɾ����
			for (int i = index; i < this->num - 1; i++) {
				this->array[i] = this->array[i + 1];
			}
			this->num--;//���������м�¼����Ա����
		}
	}
	void changeBook()
	{
		
	    string s;//ƥ���ı�
	    cin >> s;//����ƥ���ı�
	    Book book[10];
	    cin >> book;
		node<Book> now = Head;
		while(){//˳���������
			if(now.u -> title == s)
			{
				now.u=book[10]; 
				break;
			}
			if(now.next -> u == Head.u)
			{
			    now.u=book[10]; 
			    break;
			}
		}
	}
    void addBook() //���ѧУ�û�Ĭ���˺ź�����
	{
		Book *book;
		int addNumbook = 0;//������� 
		cin >> addNumbook;
		if (addNumbook <= 0) {
			
			cin >> addNumbook;
		}
		int Size = this->bnum + addNumbook;//�¿ռ���=ԭ����¼����+���ڼ������ 
		//�����¿ռ�
		Book** Space = new Book * [Size];

		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->books != NULL) {
			for (int i = 0; i < this->bnum; i++) {
				Space[i] = this->books[i];
			}
		}
		//���������
		for (int j = 0; j < addNumbook; j++) {
		     Book book1[10];
	         cin >> book1;
		     //book=new Book();
		     book=book1;
		     Space[this->bnum+j]=book;
		 }
		//�ͷ�ԭ�еĿռ�
		delete[]this->books;
		//�����¿ռ��ָ��
		this->books = Space;
		//�����鱾�� 
		this->bnum = Size;
		
    }
    void deleteBook() {
		string s;
		cin >> s;
		int bindex; 
		if(bindex>0){
			//������ǰ�ƣ���ָ��Ԫ�ؽ���ɾ����
			for (int i = bindex; i < this->bnum - 1; i++) {
				this->books[i] = this->books[i + 1];
			}
			this->bnum--;//���������м�¼����Ա����
		}
	}
};
class User{
	string code;//�û����� 
	string id="blabla";//�û��˺� 
	bool bflag=false;
	void UserCode(string &s)
	{
		code="123456";
		strcpy(code,s);
		
	}
	bool Userin(string &s1,string &s2)//�˺ŵ�½ 
	{
		if(s1==id&&s2==code)bflag=true;
		return bflag;
	}
	friend void Sign(int &uid);
};
