#pragma once
#include <AbstractSlave.h>


enum ECT_CMD_SET
{
	ECT_C0 = 0,
	PHY_INC_RD = 1,
	PHY_INC_W = 2,
	PHY_INC_RW = 3,
	PHY_RD = 4,
	PHY_W = 5,
	PHY_RW = 6,
	BRO_RD = 7,
	BRO_W = 8,
	BRO_RW = 9,
	LO_RD = 10,
	LO_W = 11,
	LO_RW = 12,
	ECT_C13 = 13,
	PHY_RD_MPL_WR = 14,
	ECT_CMD_NUM
};

#pragma pack(push, 1)
struct Datagramm
{
	//Physical io
	Datagramm(Direction dir, unsigned short slaveN, unsigned short rg, unsigned short len, unsigned char* data);
	//Broadcast
	Datagramm(Direction dir, unsigned short rg, unsigned short len, unsigned char* data);
	//logical
	Datagramm(unsigned long logAddr, unsigned char* data);


	unsigned char cmd;
	unsigned char index;
	unsigned short addr;  //phys addr in physIO/ log addr in commands with logical addressing
	unsigned short shift; //reg or mem addr in phys, physInc or broadcast cmd / log addr in commands with logical addressing

	unsigned short dtLen : 11;
	unsigned short reserv : 3;
	unsigned short isCyrc : 1;//Circulating frame
	unsigned short notLast : 1;// 0 - last, 1 not last datagram
	unsigned char* data;
	unsigned short wCnt; 
};
#pragma pack(push)

class AbstractPacket
{
public:
	virtual void AddRx(unsigned short slaveN, unsigned short rg, unsigned short len);
	virtual void AddTx(unsigned short slaveN, unsigned short rg, unsigned short len, const unsigned char* data);
	virtual void Add
	virtual ~AbstractPacket() {}
};



class AbstractMaster
{
public:
// Recognizes the network configuration. Initializes all slaves to operational state.
// Returns a pointer to an array of initialized slaves.
// In the variable nSlaves returns the number of active slaves
	virtual const AbstractSlave* Ini(unsigned short& nSlaves) = 0;
	virtual	~AbstractMaster() {}
};
