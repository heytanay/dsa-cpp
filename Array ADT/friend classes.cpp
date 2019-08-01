#include <iostream>

class Your;

class My{
	public:
		friend Your;
	private:
		int m;
};

class Your{
	public:
		My m1;
		m1.m = 100;
		int show(){
			std::cout<<m1.m<<std::endl;
		}
};

int main(){
	Your y1;
	y1.show();
}
