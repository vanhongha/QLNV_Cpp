#ifndef NhanVien_H
#define NhanVien_H

#include "ThoiGian.h"
#include <string.h>
#include <string>

using namespace std;

enum PhongBan
{
	PhongA,
	PhongB,
	PhongC
};

class NhanVien{
public:		
	string maNV;
	string tenNV;
	string sdt;
	PhongBan phongBan;
	ThoiGian ngaySinh;

	NhanVien();
	~NhanVien();
};

#endif