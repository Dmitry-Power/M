#include <iostream>
using namespace std;

template <typename T>
class AVar
{
private:
	T x;
public:
	AVar( const T val) :  x(val)
	{
	};
	virtual AVar& operator = (const T& right)
	{
		x = right;
		return *this;
	}
	virtual operator T() const
	{
		return x;
	}

	virtual operator const unsigned char* () const
	{
		return (const unsigned char*) &x;
	}
	~AVar() {};
};

//template <typename T1>
//void Out(const AVar<T1>* any)
//{
//	cout << "Any:" <<  (T1) *any << "\n";
//}

template <class  T> 
void Out(T any)
{
	cout << "Any:" << any << "\n";
};

//void Out(const AVar<int>* any)
//{
//	cout << "Any:" << *any << "\n"
//}

int main()
{
    cout << "!!!Hello World!!!\n";
	AVar <int> num(750);
	AVar <unsigned char> bty(32);
	AVar <unsigned short> sss(34000);
	AVar <double> xxx(3.1415);
	int nuM = 750;
	double xxX = 3.1415;
//	Out(nuM);
//	Out(xxX);
	//Printer pr;
	Out(num);
	//Out(bty);
	//Out(sss);
	Out(xxx);
}



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



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
