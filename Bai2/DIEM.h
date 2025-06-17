#pragma once
#include <iostream>
#include <cmath>

class DIEM {
private:
    double x, y;
public:
    DIEM(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);

    void Nhap();
    void Xuat() const;

    double KhoangCach(const DIEM& d) const;

    void TinhTien(double dx, double dy);
    void Quay(double goc, const DIEM& tam = DIEM(0, 0));
    void PhongToThuNho(double tyLe, const DIEM& tam = DIEM(0, 0));
};
