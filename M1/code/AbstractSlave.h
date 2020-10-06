#pragma once
#include <SyncManager.h>

enum Direction
{
	M2SL,
	SL2M,
	BI_DIR
};

enum DataType
{
	DO_TYPE_UNKNOWN = 0,
	DO_DT_BOOLEAN = 1,
	DO_DT_INT8 = 2,
	DO_DT_INT16 = 3,
	DO_DT_INT32 = 4,
	DO_DT_U_INT8 = 5,
	DO_DT_U_INT16 = 6,
	DO_DT_U_INT32 = 7,
	DO_DT_REAL32 = 8,

	DO_DT_VISIBLE_STR = 9,
	DO_DT_OCTET_STR = 0xA,
	DO_DT_UNICODE_STR = 0xB,

	DO_DT_INT24 = 0x10,
	DO_DT_REAL64 = 0x11,
	DO_DT_INT64 = 0x15,
	DO_DT_U_INT24 = 0x16,
	DO_DT_U_INT64 = 0x1B,

	DO_DT_PDO_MAPPING = 0x21,
	DO_DT_IDENTITY = 0x23,

	DO_DT_BIT1 = 0x30,
	DO_DT_BIT2 = 0x31,
	DO_DT_BIT3 = 0x32,
	DO_DT_BIT4 = 0x33,
	DO_DT_BIT5 = 0x34,
	DO_DT_BIT6 = 0x35,
	DO_DT_BIT7 = 0x36,
	DO_DT_BIT8 = 0x37
};

const unsigned short DO_DATA_SZ[0x38] = { 0,  8, 8, 16, 32,  8, 16, 32, 32,  //8

0xFFFF, 0xFFFF, 0xFFFF, 0, 0, 0, 0, //0xA

24, 64, 0, 0, 0, 64, 24,      0, 0, 0, 0, 64,// 0x1B
0, 0, 0, 0, 0,//0x20
0xFFFF, 0, 0xFFFF, 0,    0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, //0x2F
8, 8, 8, 8,  8, 8, 8, 8 };


struct Variable
{
	DataType type;
	char* name;
	unsigned short size;
	void* data;
};

struct DataObj
{
	Direction dir;
	unsigned short varCount;
	Variable* varList;
};


struct SLaveInfo
{
	char* name;
	char* subName;
	char* gropName;
	unsigned long vendID;
	unsigned long productCode;
	unsigned long revision;
	unsigned long serial;
	unsigned char dtObjCount;
	DataObj* objList;
};


class AbstractSlave
{
public:
	virtual bool Ini(unsigned short phAddr) = 0;
	virtual const SLaveInfo* GetInfo() = 0;
//Add 
//	virtual void AddToLogGroup(unsigned long groupNum)
	virtual ~AbstractSlave() {}
};


//struct SlaveParam
//{
//	unsigned short physAddr;
//	unsigned char smNum;
//	SyncMng* smList;
//};
