#include <iostream>
using namespace std;

//class BuffVar
//{
//private:
//	const unsigned char* bfr;
//	unsigned short size;
//public:
//	BuffVar(unsigned short sz, const unsigned char* data): size(sz)
//	{
//		bfr = (const unsigned char*)data;
//	}
//	unsigned short GetSz() { return size; } const
//	
//	const unsigned char* GetBuff (unsigned short* bfLen) const
//	{
//		*bfLen = size;
//		return bfr;
//	}
//
//	~BuffVar()
//	{
//	}
//};

//template <typename T>
//class AnyVar
//{
//private:
//	T x;
//	BuffVar* buff;
//public:
//	AnyVar( const T val) :  x(val)
//	{
//		buff = new BuffVar(sizeof(T), &x);
//	};
//	virtual AnyVar& operator = (const T& right)
//	{
//		x = right;
//		return *this;
//	}
//	virtual operator T() const
//	{
//		return x;
//	}
//
//	virtual operator const unsigned char* () const
//	{
//		return (const unsigned char*) &x;
//	}
//
//	virtual GetSz() const
//	{
//		return sizeof(T);
//	};
//
//	virtual operator const BuffVar* () 
//	{
//		return buff;
//	}
//	~AnyVar() {};
//};
//
//class Printer
//{
//public:
//	Printer() {}
//
//	void Out(const AnyVar<const unsigned char*> any)
//	{
//		unsigned short sz = any.GetSz();
//		const unsigned char* bu = any;// any->GetBuff(&sz);
//		cout << "\n-----------\n";
//		for (int i = 0; i < sz; ++i)
//		{
//			cout << hex << (unsigned int) bu[i] << " ";
//		}
//		cout << "\n-----------\n";
//	}
//	~Printer() {}
//};

int main()
{
    cout << "!!!Hello World!!!\n";
	//AnyVar <int> num(750);
	//AnyVar <unsigned char> bty(32);
	//AnyVar <unsigned short> sss(34000);
	//AnyVar <double> xxx(3.1415);
	//Printer pr;
	//pr.Out(num);
	//pr.Out(bty);
	//pr.Out(sss);
	//pr.Out(xxx);
	//AbstractVar <int> b(77);
	//cout << "b = " <<  b << "\n";
	//b = c;
	//cout << "b = " << b << "\n";
	//c = 999;
	//b = c;
	//cout << "b = " << b << "\n";
	//b = 9876;
	//cout << "b = " << b  << "\n";
	//a = b;
	//cout << "a = " << a << "\n";

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
