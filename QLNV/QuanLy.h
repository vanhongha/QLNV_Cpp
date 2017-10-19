#pragma once
#include <list>
#include <iostream>

#include "NhanVienBienChe.h"
#include "NhanVienCongNhat.h"
#include "NhanVien.h"
#include "Phong.h"
using namespace std;

class QuanLy
{
private:
	list<NhanVien*> *listNV;
	list<Phong*> *listPhong;
public:
	void Init();
	void ThemPhong(Phong *phong);
	void SuaPhong(Phong *phong);
	void XoaPhong(Phong *phong);
	void HienThiPhong();
	int SoLuongPhong();
	Phong *GetPhong(int index);

	void ThemNV(NhanVien *nv);
	NhanVien *NewNVBienChe();
	NhanVien *NewNVCongNhat();
	Phong *NewPhong();
	QuanLy();
	~QuanLy();
};

