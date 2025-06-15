#include "cTamGiac.h"
#include <iostream>
#include <cmath>

cTamGiac::cTamGiac() : A(0, 0), B(1, 0), C(0, 1) {}

cTamGiac::cTamGiac(const DIEM& a, const DIEM& b, const DIEM& c) : A(a), B(b), C(c) {}

cTamGiac::~cTamGiac() {}

void cTamGiac::Nhap() {
    std::cout << "Nhap diem A:\n";
    A.Nhap();
    std::cout << "Nhap diem B:\n";
    B.Nhap();
    std::cout << "Nhap diem C:\n";
    C.Nhap();
}

void cTamGiac::Xuat() const {
    std::cout << "A"; A.Xuat();
    std::cout << "  B"; B.Xuat();
    std::cout << "  C"; C.Xuat();
    std::cout << std::endl;
}

bool cTamGiac::LaTamGiac() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    return (a + b > c) && (a + c > b) && (b + c > a);
}

bool cTamGiac::LaTamGiacDeu() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    return LaTamGiac() && std::fabs(a - b) < 1e-6 && std::fabs(b - c) < 1e-6;
}

bool cTamGiac::LaTamGiacCan() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    return LaTamGiac() &&
        (std::fabs(a - b) < 1e-6 || std::fabs(b - c) < 1e-6 || std::fabs(a - c) < 1e-6);
}

bool cTamGiac::LaTamGiacVuong() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    double a2 = a * a, b2 = b * b, c2 = c * c;
    return LaTamGiac() &&
        (std::fabs(a2 + b2 - c2) < 1e-6 ||
            std::fabs(a2 + c2 - b2) < 1e-6 ||
            std::fabs(b2 + c2 - a2) < 1e-6);
}

double cTamGiac::ChuVi() const {
    return A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A);
}

double cTamGiac::DienTich() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::TinhTien(double dx, double dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void cTamGiac::Quay(double goc, const DIEM& tam) {
    A.Quay(goc, tam);
    B.Quay(goc, tam);
    C.Quay(goc, tam);
}

void cTamGiac::PhongToThuNho(double tyLe, const DIEM& tam) {
    A.PhongToThuNho(tyLe, tam);
    B.PhongToThuNho(tyLe, tam);
    C.PhongToThuNho(tyLe, tam);
}