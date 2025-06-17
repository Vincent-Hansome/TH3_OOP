#include "cDaGiac.h"
#include <iostream>
#include <cmath>

cDaGiac::cDaGiac(int n) : soDinh(n > 2 ? n : 3) {
    dinh = new DIEM[soDinh];
}

cDaGiac::cDaGiac(const cDaGiac& dg) : soDinh(dg.soDinh) {
    dinh = new DIEM[soDinh];
    for (int i = 0; i < soDinh; ++i)
        dinh[i] = dg.dinh[i];
}

cDaGiac::~cDaGiac() {
    delete[] dinh;
}

void cDaGiac::Nhap() {
    std::cout << "Nhap so dinh cua da giac (>=3): ";
    std::cin >> soDinh;
    if (soDinh < 3) soDinh = 3;
    delete[] dinh;
    dinh = new DIEM[soDinh];
    for (int i = 0; i < soDinh; ++i) {
        std::cout << "Nhap dinh thu " << i + 1 << ":\n";
        dinh[i].Nhap();
    }
}

void cDaGiac::Xuat() const {
    for (int i = 0; i < soDinh; ++i) {
        std::cout << "Dinh " << i + 1;
        dinh[i].Xuat();
        std::cout << "  ";
    }
    std::cout << std::endl;
}

double cDaGiac::ChuVi() const {
    double cv = 0;
    for (int i = 0; i < soDinh; ++i)
        cv += dinh[i].KhoangCach(dinh[(i + 1) % soDinh]);
    return cv;
}

double cDaGiac::DienTich() const {
    double s = 0;
    for (int i = 0; i < soDinh; ++i) {
        int j = (i + 1) % soDinh;
        s += dinh[i].getX() * dinh[j].getY() - dinh[j].getX() * dinh[i].getY();
    }
    return std::fabs(s) / 2;
}

void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < soDinh; ++i)
        dinh[i].TinhTien(dx, dy);
}

void cDaGiac::Quay(double goc, const DIEM& tam) {
    for (int i = 0; i < soDinh; ++i)
        dinh[i].Quay(goc, tam);
}

void cDaGiac::PhongToThuNho(double tyLe, const DIEM& tam) {
    for (int i = 0; i < soDinh; ++i)
        dinh[i].PhongToThuNho(tyLe, tam);

}
bool cDaGiac::KiemTraThangHang() const {
        if (soDinh < 3) return true;
        double x0 = dinh[0].getX(), y0 = dinh[0].getY();
        double x1 = dinh[1].getX(), y1 = dinh[1].getY();
        for (int i = 2; i < soDinh; ++i) {
            double xi = dinh[i].getX(), yi = dinh[i].getY();
            double s = (x1 - x0) * (yi - y0) - (y1 - y0) * (xi - x0);
            if (std::fabs(s) > 1e-6)
                return false;
        }
        return true;
    }