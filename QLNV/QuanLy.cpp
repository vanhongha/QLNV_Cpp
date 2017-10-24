#include "QuanLy.h"

void QuanLy::ThemPhong(Phong *phong)
{
	listPhong->push_back(phong);
}

void QuanLy::SuaPhong(Phong * phong)
{
	cout << "Nhap ten phong moi: ";
	cin >> phong->tenPhong;
}

void QuanLy::XoaPhong(Phong *phong)
{
	listPhong->remove(phong);
	delete(phong);
}

void QuanLy::HienThiPhong()
{
	int count = 0;
	cout << "DANH SACH PHONG" << endl;
	cout << "\tMa Phong\tTen Phong" << endl << endl;
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


void QuanLy::ThemNV(NhanVien *nv)
{
	listNV->push_back(nv);
}

void QuanLy::SuaNhanVien(NhanVien * nv)
{
	HienThiPhong();
	int phong;
	cout << "Phong ban:";
	do {
		cin >> phong;
		if (phong > SoLuongPhong() || phong < 1)
			cout << "Nhap phong sai, vui long nhap lai: ";
	} while (phong > SoLuongPhong() || phong < 1);
	nv->SetPhong(*GetPhong(phong));
	cout << "Nhap ho ten nhan vien: ";
	cin >> nv->tenNV;
	cout << "Nhap sdt nhan vien: ";
	cin >> nv->sdt;
	cout << "Nhap ngay - thang - nam sinh nhan vien: ";
	cin >> nv->ngaySinh.Ngay;
	cin >> nv->ngaySinh.Thang;
	cin >> nv->ngaySinh.Nam;

	if (nv->loaiNV == BIEN_CHE)
	{
		cout << "Nhap bac luong: ";
		cin >> ((NhanVienBienChe*)nv)->bacLuong;
		cout << "Nhap luong phu cap: ";
		cin >> ((NhanVienBienChe*)nv)->phuCap;
		nv->luong.SoLuong = ((NhanVienBienChe*)nv)->bacLuong * ((NhanVienBienChe*)nv)->luongThang + ((NhanVienBienChe*)nv)->phuCap;;
	}
	else
	{
		cout << "Nhap so ngay lam: ";
		cin >> ((NhanVienCongNhat*)nv)->soNgayLam;
		nv->luong.SoLuong = ((NhanVienCongNhat*)nv)->luongNgay * ((NhanVienCongNhat*)nv)->soNgayLam;
	}
}

void QuanLy::XoaNhanVien(NhanVien * nv)
{
	listNV->remove(nv);
	delete(nv);
}

NhanVien * QuanLy::GetNhanVien(int index)
{
	int count = 1;
	for (list<NhanVien*>::iterator nv = listNV->begin(); nv != listNV->end(); nv++)
	{
		if (count == index)
			return *nv;
	}
	return nullptr;
	return nullptr;
}

int QuanLy::SoLuongNhanVien()
{
	return listNV->size();
}

void QuanLy::HienThiNhanVienTheoLuong()
{
	listNV->sort(SortType<NhanVien>);
	HienThiNhanVien();
}

NhanVien *QuanLy::NewNVBienChe()
{
	HienThiPhong();
	int phong;

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
	cout << "Phong ban:";
	do {
		cin >> phong;
		if (phong > SoLuongPhong() || phong < 1)
			cout << "Nhap phong sai, vui long nhap lai: ";
	} while (phong > SoLuongPhong() || phong < 1);

	tempNV->SetPhong(*GetPhong(phong));

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
	tempNV->luong.SoLuong = tempNV->bacLuong * tempNV->luongThang + tempNV->phuCap;

	return tempNV;
}

NhanVien * QuanLy::NewNVCongNhat()
{
	HienThiPhong();
	int phong;
	NhanVienCongNhat *tempNV = new NhanVienCongNhat();
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

	cout << "Phong ban:";
	do {
		cin >> phong;
		if (phong > SoLuongPhong() || phong < 1)
			cout << "Nhap phong sai, vui long nhap lai: ";
	} while (phong > SoLuongPhong() || phong < 1);

	tempNV->SetPhong(*GetPhong(phong));

	cout << "Nhap ho ten nhan vien: ";
	cin >> tempNV->tenNV;
	cout << "Nhap sdt nhan vien: ";
	cin >> tempNV->sdt;
	cout << "Nhap ngay - thang - nam sinh nhan vien: ";
	cin >> tempNV->ngaySinh.Ngay;
	cin >> tempNV->ngaySinh.Thang;
	cin >> tempNV->ngaySinh.Nam;
	cout << "Nhap so ngay lam: ";
	cin >> tempNV->soNgayLam;
	tempNV->luong.SoLuong = tempNV->luongNgay * tempNV->soNgayLam;
	return tempNV;
}

void QuanLy::HienThiNhanVien()
{
	int count = 0;
	cout << "DANH SACH NHAN VIEN" << endl;
	cout << "\tMa NV\tTen NV\tLuong\tPhong" << endl << endl;
	for each (NhanVien *_nv in *listNV)
	{
		count++;
		cout << count << ".\t";
		cout << _nv->maNV << "\t" << _nv->tenNV << "\t" << to_string(_nv->luong.SoLuong) << "\t" << _nv->phongBan.tenPhong << endl << endl;
	}
}

void QuanLy::Init()
{
	listNV = new list<NhanVien*>;
	listPhong = new list<Phong*>;
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
