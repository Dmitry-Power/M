#pragma once
enum IOType
{
	IO_BUFFERED,
	IO_MAIL_BX
};


//
//struct Entry
//{
//	DO_DType dtType;
//	char* name;
//};
//
//struct FMMU
//{
//	unsigned 
//};
//
//struct SyMPrm
//{
//	SyMPrm() : sz(0) {}
//	SyMPrm(unsigned short len, unsigned short shift, Direction smDir, IOType ioTp, unsigned char nFM,
//		char* nameDt, unsigned short nEnt, Entry* entrs) :
//		sz(len), offset(shift), dir(smDir), type(ioTp), fmmu(nFM), 
//		pdoName(nameDt),  entryNum(nEnt), entryList(entrs)
//	{}
//	unsigned short sz;
//	unsigned short offset;
//	Direction dir;
//	IOType type;
//	unsigned char fmmu;// associated FMMU
//	char* pdoName;
//	unsigned short entryNum;// number of variables controlled by this sync ìanager
//	Entry* entryList;
//	SyMPrm& operator = (const SyMPrm& right)
//	{
//		if (this == &right)
//		{
//		}
//		else
//		{
//			sz = right.sz;
//			offset = right.offset;
//		}
//		return *this;
//	}
//};
//
//class SyncMng
//{
//public:
//	SyncMng() : prms.sz(0) {}
//	SyncMng(SyMPrm* sParam) : prms(*sParam) {}
//	void SetParam(SyMPrm* sParam)
//	{
//		prms = *sParam;
//	}
//	const SyMPrm* GetPrm()
//	{
//		return &prms;
//	}
//	~SyncMng() {}
//private:
//	SyMPrm prms;
//};
//
