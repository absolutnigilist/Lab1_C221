#pragma once

#include <functional>
#include <map>
#include <cmath>
#include <iostream>

//����������� ������� ���������� �������
template<typename T> T sum(const T& a, const T& b) {

	return a + b;
}

// ���������� ������ std::minus ��� ���������
extern std::minus<double> substract;

//����������� ��������������� �������
struct Multiplication {

	template<typename T> 
	T operator()(const T& a, const T& b) {
		return a * b;
	}
};

//����������� ������
extern std::function<double(double, double)> division;


// ����� ��� ���������� ���������
class MaxFinder {
public:
	double maximum(double a, double b)const {
		return a > b ? a : b;
	}
};

// ������� ��� ���������� ������� �����
inline double fractional_part(double a) {
	return a - static_cast<int>(a);
}

void  Calc();



