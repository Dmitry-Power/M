#pragma once
#include <AbstractMaster.h>

const unsigned char M2S_ECAT_FR_HDR[14] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 1, 1, 1, 1, 1, 1, 0x88, 0xa4 };
const unsigned short CMD_OFFSET = 0x10;

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

class Master : public AbstarctMaster
{
public:
	// Recognizes the network configuration. Initializes all slaves to operational state.
	// Returns a pointer to an array of initialized slaves.
	// In the variable nSlaves returns the number of active slaves
	virtual const AbstractSlave* Ini(unsigned short& nSlaves);
	//Adds cmd containing the x variable to the packet.
	//if the command has already been added, updates the x value in it
	AbstractMaster& operator += (const BuffVar& v);
	//Adds cmd containing the register read or write to the packet.
	//if the command has already been added, updates the x value in it
	virtual void WriteReg(const BuffVar& v);
	virtual void ReadReg(const BuffVar& v);
	//Send packet.
	virtual void Send();

	virtual	~Master() {}
};

