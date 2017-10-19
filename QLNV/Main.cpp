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
void HienThiPhong();

void OnThemNhanVien();
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
	cout << "*\t\t\tQUAN LY NHAN VIEN\t\t\t*" << endl;
	cout << "*---------------------------------------------------------------*" << endl;
	cout << "*\t\t\tPHONG BAN:\t\t\t\t\t*" << endl;
	cout << "*\t\t\t1. Them phong \t\t\t*" << endl;
	cout << "*\t\t\t2. Sua phong \t\t\t*" << endl;
	cout << "*\t\t\t3. Xoa phong \t\t\t*" << endl;
	cout << "*\t\t\t4. Hien thi danh sach phong\t\t*" << endl;
	cout << "*---------------------------------------------------------------*" << endl;
	cout << "*\t\t\tOption:\t\t\t\t\t*" << endl;
	cout << "*\t\t\t5. Them Nhan Vien \t\t\t*" << endl;
	cout << "*\t\t\t6. Sua Nhan Vien \t\t\t*" << endl;
	cout << "*\t\t\t7. Xoa Nhan Vien \t\t\t*" << endl;
	cout << "*\t\t\t8. Hien thi danh sach Nhan Vien\t\t*" << endl;
	cout << "*****************************************************************\n" << endl;
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
		break;
	case 2:
		SuaPhong();
		break;
	case 3:
		SuaNhanVien();
		break;
	case 4:
		HienThiNhanVien();
		break;
	}
}

void ThemPhong()
{
	int sl;
	cout << "Nhap so phong can them: ";
	cin >> sl;
	for (int i = 0; i < sl; i++)
	{
		quanLy->ThemPhong(quanLy->NewPhong());
	}
	system("cls");
	OnShowMenu();
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

void HienThiPhong()
{
	quanLy->HienThiPhong();
}

void OnThemNhanVien()
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
				ThemNVCongNhat();
			}
		else
			for (int i = 0; i < soLuong; i++)
			{
				cout << " * Nhap thong tin nhan vien " << i << endl;
				ThemNVBienChe();
			}
}

void ThemNVBienChe()
{
	NhanVienBienChe *tempNV = new NhanVienBienChe();

}

void ThemNVCongNhat()
{

}

void TimNhanVien()
{

}

void SuaNhanVien()
{

}

void HienThiNhanVien()
{

}
