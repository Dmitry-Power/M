#pragma once
#include <AbstractSlave.h>

class AbstarctMaster;

class BuffVar
{
private:
	unsigned short slaveN;
	unsigned short varN;
	unsigned short sz;
	const unsigned char* buff;
public:
	BuffVar(unsigned short sNum, unsigned short vNum, unsigned short size, const unsigned char* data) :
		 slaveN(sNum), varN(vNum), sz(size), buff (data)
	{
	}
	const unsigned char* GetBuff(unsigned short* dtLen) const
	{
		*dtLen = sz;
		return buff;
	}
	unsigned short GetSlaveNum() const { return slaveN; }
	unsigned short GetVarNum() const { return varN; }
	virtual ~BuffVar() {}
};

class AbstractMaster
{
public:
// Recognizes the network configuration. Initializes all slaves to operational state.
// Returns a pointer to an array of initialized slaves.
// In the variable nSlaves returns the number of active slaves
	virtual const AbstractSlave* Ini(unsigned short& nSlaves) = 0;
//Adds cmd containing the x variable to the packet.
//if the command has already been added, updates the x value in it
	AbstractMaster& operator += (const BuffVar& v) = 0;
//Adds cmd containing the register read or write to the packet.
//if the command has already been added, updates the x value in it
	virtual void WriteReg (const BuffVar& v) = 0;
	virtual void ReadReg(const BuffVar& v) = 0;
//Send packet.
	virtual void Send () = 0;

	virtual	~AbstractMaster() {}
};

template <typename T>
class AnyVar
{
private:
	AbstarctMaster* mstr;
	unsigned short slaveN;
	unsigned short varN;
	T x;
	unsigned short dtSize;
	BuffVar* bfV;
public:
	AnyVar(AbstractMaster* m, unsigned short sNum, unsigned short vNum, const T val) :
	mstr(m), slaveN(sNum), varN(vNum), x(val), dtSise(sizeof(T))
	{
		//BuffVar(unsigned short sNum, unsigned short vNum, unsigned short size, const unsigned char* data)
		bfV = new BuffVar(slaveN, varN, dtSize, (const unsigned char*)x);
	};
//passing the variable to the master to add it to the buffer
	virtual AnyVar& operator = (const T& right)
	{
		x = right;
		*mstr += bfV;
		return *this;
	}
//  Return value of variable, reading in last exchange. 
//	Passing the variable to the master to add it to the buffer for next exchange
	virtual operator T()
	{
		*mstr += bfr;
		return x;
	}
	virtual ~AnyVar() { delete bfr; }
};
template <typename T>
class RegVar
{
private:
	AbstarctMaster* mstr;
	unsigned short slaveN;
	unsigned short regAdr;
	T x;
	unsigned short dtSize;
	BuffVar* bfV;
public:
	RegVar(AbstractMaster* m, unsigned short sNum, unsigned short vNum, const T val) :
		mstr(m), slaveN(sNum), regAdr(vNum), x(val), dtSise(sizeof(T))
	{
		//BuffVar(unsigned short sNum, unsigned short vNum, unsigned short size, const unsigned char* data)
		bfV = new BuffVar(slaveN, varN, dtSize, (const unsigned char*)x);
	};
	//passing the variable to the master to add it to the buffer
	virtual RegVar& operator = (const T& right)
	{
		x = right;
		mstr->WriteReg(bfV);
		return *this;
	}
	//  Return value of variable, reading in last exchange. 
	//	Passing the variable to the master to add it to the buffer for next exchange
	virtual operator T()
	{
		mstr->ReadRef(bfV);
		return x;
	}
	virtual ~RegVar() { delete bfr; }
};


//struct EVar
//{
//	unsigned short slaveN;
//	unsigned short varN;
//	unsigned short len;
//	unsigned char* data;
//};
//
//struct EReg
//{
//	unsigned short slaveN;
//	unsigned short regN;
//	unsigned short len;
//	unsigned char* data;
//};
//

//class AbstractPacket
//{
//public:
//
//	virtual AbstractPacket& operator += (const EVar& right) = 0;
//	virtual AbstractPacket& operator += (const EReg& right) = 0;
//
//
//	//add rx cmd to packet buffer
//	virtual void AddRx(unsigned short slaveN, unsigned short rg, unsigned short len) = 0;
//	//add rx cmd to packet buffer & send packet
//	virtual void AddSendRx(unsigned short slaveN, unsigned short rg, unsigned short len) = 0;
//
//	//add tx cmd to packet buffer
//	virtual void AddTx(unsigned short slaveN, unsigned short rg, unsigned short len, const unsigned char* data) = 0;
//	//add tx cmd to packet buffer & send packet
//	virtual void AddSendTx(unsigned short slaveN, unsigned short rg, unsigned short len, const unsigned char* data) = 0;
//
//
//
//
//	//add log cmd to packet buffer
//	virtual void AddLog(unsigned long logAddr, unsigned short len, unsigned char* data) = 0;
//	//add log cmd to packet buffer & send packet
//	virtual void AddSendLog(unsigned long logAddr, unsigned short len, unsigned char* data) = 0;
//	//Parse recieved packet. Read data from log addr. Put to data* variable with subindex subId.  
//	//return  number of byte in variable. If no valid data recieved, return 0;
//	virtual unsigned short Get(unsigned long logAddr, unsigned short subId, unsigned char* data) = 0;
//	virtual unsigned short Get(unsigned short slaveN, unsigned short rg, unsigned char* data) = 0;
//	//send packet and erase packet buffer
//	virtual void Send() = 0;
//	//erase packet buffer
//	virtual void Reset() = 0;
//	virtual ~AbstractPacket() {}
//};