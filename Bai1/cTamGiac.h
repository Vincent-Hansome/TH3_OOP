#pragma once
#include "DIEM.h"

class cTamGiac {
private:
    DIEM A, B, C;
public:
    cTamGiac();
    cTamGiac(const DIEM& a, const DIEM& b, const DIEM& c);
    ~cTamGiac();

    void Nhap();
    void Xuat() const;

    bool LaTamGiac() const;
    bool LaTamGiacDeu() const;
    bool LaTamGiacCan() const;
    bool LaTamGiacVuong() const;

    double ChuVi() const;
    double DienTich() const;

    void TinhTien(double dx, double dy);
    void Quay(double goc, const DIEM& tam = DIEM(0, 0));
    void PhongToThuNho(double tyLe, const DIEM& tam = DIEM(0, 0));
};
