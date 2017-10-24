#include "QuanLy.h"
#include <map>
#include <iostream>
using namespace std;

QuanLy *quanLy;

#pragma region Define function  
void OnShowMenu();
void OnSelectOption();

void ThemPhong();
void SuaPhong();
void XoaPhong();
void HienThiPhong();

void ThemNhanVien();
void TimNhanVien();
void SuaNhanVien();
void HienThiNhanVien();

void ThemNVBienChe();
void ThemNVCongNhat();
#pragma endregion

void main()
{
	quanLy = new QuanLy();
	quanLy->Init();

	OnShowMenu();

}


void OnShowMenu()
{
	cout << "*****************************************************************" << endl;
	cout << "*\tQUAN LY NHAN VIEN\t\t\t\t\t*" << endl;
	cout << "*---------------------------------------------------------------*" << endl;
	cout << "*\tPHONG BAN:\t\t\t\t\t\t*" << endl;
	cout << "*\t1. Them phong \t\t\t\t\t\t*" << endl;
	cout << "*\t2. Sua phong \t\t\t\t\t\t*" << endl;
	cout << "*\t3. Xoa phong \t\t\t\t\t\t*" << endl;
	cout << "*\t4. Hien thi danh sach phong\t\t\t\t*" << endl;
	cout << "*---------------------------------------------------------------*" << endl;
	cout << "*\tNHAN VIEN:\t\t\t\t\t\t*" << endl;
	cout << "*\t5. Them Nhan Vien \t\t\t\t\t*" << endl;
	cout << "*\t6. Sua Nhan Vien \t\t\t\t\t*" << endl;
	cout << "*\t7. Xoa Nhan Vien \t\t\t\t\t*" << endl;
	cout << "*\t8. Hien thi danh sach Nhan Vien\t\t\t\t*" << endl;
	cout << "*\t9. Hien thi danh sach Nhan Vien co luong tang dan\t*" << endl;
	cout << "*****************************************************************" << endl;
	cout << "\tLua chon cua ban: ";
	OnSelectOption();
}

void OnSelectOption()
{
	int choice;
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		ThemPhong();
		system("cls");
		OnShowMenu();
		break;
	case 2:
		SuaPhong();
		break;
	case 3:
		XoaPhong();
		break;
	case 4:
		HienThiPhong();
		break;
	case 5:
		if (quanLy->SoLuongPhong() < 1)
		{
			cout << "VUI LONG THEM PHONG TRUOC KHI THEM NHAN VIEN" << endl << endl;
			ThemPhong();
			system("cls");
		}
		ThemNhanVien();
		system("cls");
		HienThiNhanVien();
		break;
	case 6:
		SuaNhanVien();
		break;
	case 7:
		break;
	case 8:
		HienThiNhanVien();
		break;
	}
}

#pragma region PHONG HANDLER

void ThemPhong()
{
	int sl;
	cout << "Nhap so phong can them: ";
	cin >> sl;
	for (int i = 0; i < sl; i++)
	{
		quanLy->ThemPhong(quanLy->NewPhong());
	}
}

void SuaPhong()
{
	int choice;

	HienThiPhong();

	cout << "Lua chon phong can sua: ";
	cin >> choice;
	do {
		if (choice <= 0 || choice > quanLy->SoLuongPhong())
		{
			cout << "Noi dung khong thich hop, nhap lai: ";
			cin >> choice;
		}
	} while (choice <= 0 || choice > quanLy->SoLuongPhong());

	cout << "Nhap thong tin moi cua phong: " << endl;
	quanLy->SuaPhong(quanLy->GetPhong(choice));
	cout << "Thong tin phong sau thay doi." << endl;
	HienThiPhong();
}

void XoaPhong()
{
	int choice;

	HienThiPhong();

	cout << "Lua chon phong can xoa: ";
	cin >> choice;
	do {
		if (choice <= 0 || choice > quanLy->SoLuongPhong())
		{
			cout << "Noi dung khong thich hop, nhap lai: ";
			cin >> choice;
		}
	} while (choice <= 0 || choice > quanLy->SoLuongPhong());
	quanLy->XoaPhong(quanLy->GetPhong(choice));
	HienThiPhong();
}

void HienThiPhong()
{
	quanLy->HienThiPhong();
}
#pragma endregion

#pragma region NHANVIEN HANDLER

void ThemNhanVien()
{
	int soLuong;
	int loai;
	cout << "\tLoai nhan vien:" << endl;
	cout << "\t1. Nhan vien cong nhat" << endl;
	cout << "\t2. Nhan vien bien che" << endl;
	cout << "Nhap loai nhan vien can them: ";
	cin >> loai;

	cout << "Nhap so luong nhan vien can them: ";
	cin >> soLuong;
	if (soLuong <= 0)
		cout << "Nhap so luong khong hop le!";
	else
		if (loai == 1)
			for (int i = 0; i < soLuong; i++)
			{
				cout << " * Nhap thong tin nhan vien " << i << endl;
				quanLy->ThemNV(quanLy->NewNVCongNhat());
			}
		else
			for (int i = 0; i < soLuong; i++)
			{
				cout << " * Nhap thong tin nhan vien " << i << endl;
				quanLy->ThemNV(quanLy->NewNVBienChe());
			}
	OnShowMenu();
}

void TimNhanVien()
{

}

void SuaNhanVien()
{
	int choice;
	HienThiNhanVien();
	cout << "Lua chon nv can sua: ";
	cin >> choice;
	do {
		if (choice <= 0 || choice > quanLy->SoLuongNhanVien())
		{
			cout << "Noi dung khong thich hop, nhap lai: ";
			cin >> choice;
		}
	} while (choice <= 0 || choice > quanLy->SoLuongNhanVien());

	cout << "Nhap thong tin moi cua nhan vien: " << endl;
	quanLy->SuaNhanVien(quanLy->GetNhanVien(choice));
	cout << "Thong tin nhan vien sau thay doi." << endl;
	HienThiNhanVien();
}

void HienThiNhanVien()
{
	quanLy->HienThiNhanVien();
}

#pragma endregion