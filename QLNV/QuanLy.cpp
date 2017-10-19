#include "QuanLy.h"

void QuanLy::Init()
{
	listNV = new list<NhanVien*>;
	listPhong = new list<Phong*>;
}

void QuanLy::ThemPhong(Phong *phong)
{
	listPhong->push_back(phong);
}

void QuanLy::SuaPhong(Phong * phong)
{
	XoaPhong(phong);
	ThemPhong(NewPhong());
}

void QuanLy::XoaPhong(Phong *phong)
{
	listPhong->remove(phong);
}

void QuanLy::ThemNV(NhanVien *nv)
{
	listNV->push_back(nv);
}

void QuanLy::HienThiPhong()
{
	int count = 0;
	cout << "DANH SACH PHONG" << endl;
	cout << "\tMa Phong\tTen Phong" << endl;
	for each (Phong *_phong in *listPhong)
	{
		count++;
		cout << count << ".\t";
		cout << _phong->maPhong << "\t\t" << _phong->tenPhong << endl;
	}
}

int QuanLy::SoLuongPhong()
{
	return listPhong->size();
}

Phong *QuanLy::GetPhong(int index)
{
	int count = 1;
	for (list<Phong*>::iterator p = listPhong->begin(); p != listPhong->end(); p++)
	{
		if (count == index)
			return *p;
	}
	return nullptr;
}

NhanVien *QuanLy::NewNVBienChe()
{
	NhanVienBienChe *tempNV = new NhanVienBienChe();
	cout << "Nhap ma nhan vien: ";
	cin >> tempNV->maNV;
	
	for each (NhanVien *nv in *listNV)
	{
		do
		{
			if (strcmp(nv->maNV.c_str(), tempNV->maNV.c_str()) == 0)
			{
				cout << "Da ton tai ma NV: " << nv->maNV << "\nVui long nhap lai ma NV: ";
				cin >> tempNV->maNV;
			}
		} while (strcmp(tempNV->maNV.c_str(), nv->maNV.c_str()) == 0);
	}

	cout << "Nhap ho ten nhan vien: ";
	cin >> tempNV->tenNV;
	cout << "Nhap sdt nhan vien: ";
	cin >> tempNV->sdt;
	cout << "Nhap ngay - thang - nam sinh nhan vien: ";
	cin >> tempNV->ngaySinh.Ngay;
	cin >> tempNV->ngaySinh.Thang;
	cin >> tempNV->ngaySinh.Nam;
	cout << "Nhap bac luong: ";
	cin >> tempNV->bacLuong;
	cout << "Nhap luong phu cap: ";
	cin >> tempNV->phuCap;

	return tempNV;
}

NhanVien * QuanLy::NewNVCongNhat()
{
	NhanVienCongNhat *tempNV = new NhanVienCongNhat();
	cout << "Nhap ma nhan vien: ";
	getline(cin, tempNV->maNV);

	for each (NhanVien *nv in *listNV)
	{
		do
		{
			if (strcmp(nv->maNV.c_str(), tempNV->maNV.c_str()) == 0)
			{
				cout << "Da ton tai ma NV: " << nv->maNV << "\nVui long nhap lai ma NV: ";
				cin >> tempNV->maNV;
			}
		} while (strcmp(tempNV->maNV.c_str(), nv->maNV.c_str()) == 0);
	}

	cout << "Nhap ho ten nhan vien: ";
	getline(cin, tempNV->tenNV);
	cin.ignore();
	cout << "Nhap sdt nhan vien: ";
	getline(cin, tempNV->sdt);
	cout << "Nhap ngay - thang - nam sinh nhan vien: ";
	cin >> tempNV->ngaySinh.Ngay;
	cin >> tempNV->ngaySinh.Thang;
	cin >> tempNV->ngaySinh.Nam;
	cout << "Nhap bac luong: ";
	cin >> tempNV->soNgayLam;
	return tempNV;
}

Phong * QuanLy::NewPhong()
{
	Phong *tempPhong = new Phong();

	cout << "\tNhap ma phong: ";
	cin >> tempPhong->maPhong;
	for each (Phong *phong in *listPhong)
	{
		do
		{			
			if (strcmp(tempPhong->maPhong.c_str(), phong->maPhong.c_str()) == 0)
			{
				cout << "\tDa ton tai ma phong: " << phong->maPhong << endl << "\tVui long nhap lai ma phong: ";
				cin >> tempPhong->maPhong;
			}
		} while (strcmp(tempPhong->maPhong.c_str(), phong->maPhong.c_str()) == 0);
	}
	cout << "\tNhap ten phong: ";
	cin >> tempPhong->tenPhong;
	cout << endl;

	return tempPhong;
}

QuanLy::QuanLy()
{
}


QuanLy::~QuanLy()
{
}
