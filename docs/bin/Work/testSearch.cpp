/*
testSearch
*/
#include<bits/stdc++.h>
using namespace std;
template<class T>//链表
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
	/* 首字母,数字组合/数字组合 */
	string Divider[3];//首字母也得分解...
	//string &P[3] = {title, writer, ISBN};//变量别名，方便按状态码访问
	//尝试失败，c++不允许定义引用类型的数组，引用在声明时必须要初始化，而数组无法用另一个数组初始化。
	string *P[3];//尝试使用指针...
public:
	Book(){//默认构造将指针数组定向到元素方便顺序访问
		//P[3] = {&title, &writer, &ISBN};
		P[0] = &title, P[1] = &writer, P[2] = &ISBN;
	};
	Book(const Book &t){//取消了指针的拷贝
		title = t.title, writer = t.writer, ISBN = t.ISBN;
		for(int i = 0; i < 3; i ++)Divider[0] = t.Divider[0];
	}
	template<class I>
	friend I& operator >>(I& in, Book& book);
	template<class O>
	friend O& operator <<(O& out, const Book& book);
	friend void RootSearch(const int &op);
	void Print(){//查找到之后输出书的全部信息
		cout << "<<" << title << ">>" << endl;
		cout << "Writer: " << writer << endl;
		cout << "ISBN: " << ISBN << endl;
	}//也可以直接使用 cout << 输出数据
};
/* 重载多个输入流 */
template<class I>
I& operator >>(I& in, Book& book){
	in >> book.title >> book.ISBN >> book.writer >> book.Divider[0];
	in.ignore(1024, '\n');//忽略行末所有字符
	for(int i = 0; i < (int)book.Divider[0].size(); i ++){//分解3级分类
		if(book.Divider[0][i] == '/'){
			book.Divider[1] = book.Divider[0].substr(0, i);//从 0 到 i - 1
			book.Divider[2] = book.Divider[0].substr(i + 1);//从i + 1到字符串末尾
			book.Divider[0] = book.Divider[0].substr(0, 1);//首字
			break;
		}
	}
	return in;
}
/* 重载多输入输入流 */
template<class I>
I& operator >>(I& in, Book* book){
	while(in >> *book){
		book ++;
	}
	return in;
}
/* 重载输出流 */
template<class O>
O& operator <<(O& out, const Book& book){
	out << book.title << ' ';//在考虑要不要使用换行，因为book.txt里面使用的是空格，但是好像也没有什么影响。
	out << book.ISBN << ' ';//有个细节就是从book.txt读入的时候末尾有一个 1 ，不知道是不是为了方便作为了标识符。
	out << book.writer << ' ';//应该没什么影响吧，主要怕 in.ignore(1024, '\n'); 这一行出问题
	out << book.Divider[1] << '/';
	out << book.Divider[2].substr(book.Divider[1].size()) << '\n';
	return out;
}

node<Book> Head;//存储链表头

void Borrow(){
	cout << "Do you want to borrow this book?" << endl;
}

/*
功能：
1. 题名精确查找
2. ISBN精确查找
3. 作者，全部查找
4. 三级分类查找
*/
/*
void Search(const int &op, string &s){//状态码,
	if(op == 1){//title
		node<Book> now = Head;
		while(){//顺序遍历链表
			if(now.u -> title == s){
				now.u -> Print();
				Borrow();
				break;
			}
			if(now.next -> u == Head.u)break;
		}
	}else if(op == 2){//ISBN
		node<Book> now = Head;
		while(){//顺序遍历链表
			if(now.u -> ISBN == s){
				now.u -> Print();
				Borrow();
				break;
			}
			if(now.next -> u == Head.u)break;
		}
	}else if(op == 3){//writer
		node<Book> now = Head;
		while(){//顺序遍历链表
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
//写的太差了，感觉需要给每个功能区开个读入池
/*
void Search(int op){//仅由外部传入状态码
	node<Book> HeadTmp = Head;//临时的链表头
	string s;//匹配的文本
	if(1 <= op && op <= 3){
		cin >> s;
		node<Book> now = HeadTmp;//获取链表头
		while(now.next -> u != HeadTmp.u){//顺序遍历链表
			if(*(now.u -> P[op-1]) == s){
				now.u -> Print();
				//Borrow();
				//break;
			}
		}
	}else if(op == 4){//3Divider
		list<Book> q;//用于存放临时变量的队列(为了支持迭代器访问用了list)
		cin >> s;
		node<Book> now = HeadTmp;//获取链表头
		while(now.next -> u != HeadTmp.u){//第一遍顺序遍历链表
			if(now.u -> Divider[0] == s){
				q.push_back(*now.u);
			}
		}
		for(list<Book>::iterator it = q.begin(); it != q.end(); it ++){
			cout << *it ;
		}//第一遍遍历后输出
		for(int i = 1; i <= 2; i ++){//接下来顺序遍历list
			Book Begin = q.back();//获取list尾用于判断循环结束
			Book u = q.front();
			do{
				u = q.front();//list头
				q.pop_front();//弹出已经获取的list头
				if(u -> Divider[i] == s)q.push_back(u);
			}while(q.front() != Begin);
			for(list<Book>::iterator it = q.begin(); it != q.end(); it ++){
				cout << *it ;
			}//第一遍遍历后输出
		}
	}else{
		cout << "Invalid Input!" << endl;
	}
}
*///再次写炸，感觉还不如用纯指针

void Search(const int &op){
	node<Book> HeadTmp = Head;//临时的链表头
	cout << *(Head.u -> P[0]) << endl;
	string s;//匹配文本
	if(1 <= op && op <= 3){
		cin >> s;//读入匹配文本
		node<Book> now = HeadTmp;
		while(now.next -> u != HeadTmp.u){//顺序遍历链表
			if(*(now.u -> P[op-1]) == s){
				now.u -> Print();//找到就输出
			}
		}
	}else if(op == 4){//3Divider
		
	}
}
int main(){
	int op;
	while(cin >> op){
		Search(op);//传入状态码
	}
	return 0;
}

/*
功能实现模块:
功能1:
1.读入池
读入池为层层传入式，每一层先对信息进行过滤，然后传给下一层
2.功能区
函数实现,从存储块中读取和处理数据尽量永远用指针模式
3.存储块
包含缓存存储块,即在程序内部的存储
磁盘存储块,在外部存储。
*/
