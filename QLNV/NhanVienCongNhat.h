#pragma once
#ifndef NVCN
#define NVCN
#endif
#include "NhanVien.h"

class NhanVienCongNhat : public NhanVien{
public:
	int soNgayLam;
	double luongNgay = 100000;

	NhanVienCongNhat();
	~NhanVienCongNhat();
};

