/*
实验1
重载流运算符
完成!
*/
#include<bits/stdc++.h>
using namespace std;

class Book{
private:
	string title;
	string writer;
	/*I-S-B-N*/
	string ISBN;
	/* 首字母,数字组合/数字组合  */
	string Divider[3];
public:
	template<class I>
	friend I& operator >>(I& in, Book& book);
	template<class O>
	friend O& operator <<(O& out, const Book& book);
	/*
	用成员方式重载运算符,不能改变参数的个数,二元运算符用成员重载时,只需要一个参数。
	但是由于这个参数是stream类型，所以这样输入就变成了 book>>cin; 很奇怪，所以选择重载为友源。
	另一个参数由this指针传入。如果需要两个参数,那么可以在类外面定义,然后在类里声明为友元。
	*/
};
/* 重载一下输入流 */
template<class I>
I& operator >>(I& in, Book& book){
	in >> book.title >> book.ISBN >> book.writer >> book.Divider[0];
	in.ignore(1024, '\n');//处理多余字符
	for(int i = 0; i < (int)book.Divider[0].size(); i ++){
		if(book.Divider[0][i] == '/'){
			book.Divider[1] = book.Divider[0].substr(i+1);//从i+1到结尾的字符串
			book.Divider[0] = book.Divider[0].substr(0, i);//从0到i-1的字符串
			break;
		}
	}
	return in;
}
/* 重载多数据输入 */
template<class I>
I& operator >>(I& in, Book* book){
	while(in >> *book){
		book ++;
	}
	return in;
}

/* 重载一下输出流 */
template<class O>
O& operator <<(O& out, const Book& book){
	out << book.title << '\n';//考虑是否需要加\n，因为管理员带有写操作，带\n写入虽然说没啥大碍，但总觉得不妥。或者不使用模板，分别重载两个流
	out << book.ISBN << '\n';
	out << book.writer << '\n';
	out << book.Divider[0] << '\n';
	out << book.Divider[1] << '\n';
	return out;
}
/* 重载多数据输出 */
/*
呃好像需要对输入的数据结尾插入标识符...
而且好像没有什么需要，还麻烦，用的时候加循环就可以了
template<class O>
O& operator <<(O& out, Book* book){	}
*/



int main(){
	freopen("intest.txt", "r", stdin);//
	Book book[10];
	cin >> book;
	cout << book[3] << endl;
	return  0;
}