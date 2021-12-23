#include<bits/stdc++.h>
using namespace std;

class node{
private:
	int x, y;
public:
	/* 以模板的方式重载了多个流 */
	template<class I>
	friend I& operator >>(I& in, node& a);
	template<class O>
	friend O& operator <<(O& in, const node& a);
}e;
template<class I>
I& operator >>(I& in, node& a){
	in >> a.x >> a.y;
	return in;
}

template<class O>
O& operator <<(O& out, const node& a){
	out << a.x <<"  "<< a.y << endl;
	return out;
}


int main(){
	
	cin >> e;
	cout << e;

	return 0;
}