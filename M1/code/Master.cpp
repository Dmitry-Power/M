#include <Master.h>

Master::Master():  currPos(0x10)
{
}

const AbstractSlave* Master::Ini(unsigned short& nSlaves)
{
	return nullptr;
}

template <class T>
Master& Master::operator += (const T& v)
{

	return *this;
}

void Master::Send()
{
}
