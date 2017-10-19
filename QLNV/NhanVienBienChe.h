#pragma once
#ifndef NHANVIENBIENCHE_H
#define NHANVIENBIENCHE_H

#include "NhanVien.h"
class NhanVienBienChe : public NhanVien
{
public:
	double luongThang = 3000000;
	float bacLuong;
	double phuCap;

	NhanVienBienChe();
	//NhanVienBienChe(string _maNV, string _hoTen, string _sdt, PhongBan _phongBan, ThoiGian _ngaySinh);
	~NhanVienBienChe();
};
#endif
