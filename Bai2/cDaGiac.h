#pragma once
#include "DIEM.h"

class cDaGiac {
private:
    DIEM* dinh;
    int soDinh;
public:
    cDaGiac(int n = 3);
    cDaGiac(const cDaGiac& dg);
    ~cDaGiac();

    void Nhap();
    void Xuat() const;

    double ChuVi() const;
    double DienTich() const;

    void TinhTien(double dx, double dy);
    void Quay(double goc, const DIEM& tam = DIEM(0, 0));
    void PhongToThuNho(double tyLe, const DIEM& tam = DIEM(0, 0));

    bool KiemTraThangHang() const;
};