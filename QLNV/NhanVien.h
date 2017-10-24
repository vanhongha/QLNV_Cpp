#ifndef NhanVien_H
#define NhanVien_H

#include "Luong.h"
#include "ThoiGian.h"
#include "Phong.h"
#include <string.h>
#include <string>

using namespace std;

enum LoaiNV
{
	BIEN_CHE,
	CONG_NHAT
};

class NhanVien{
public:		
	string maNV;
	string tenNV;
	string sdt;
	Luong luong;
	ThoiGian ngaySinh;
	Phong phongBan;
	LoaiNV loaiNV;

	void SetPhong(Phong phong);
	NhanVien();
	~NhanVien();
};

#endif