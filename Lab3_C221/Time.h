#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <map>
#include <string>
#include <ctime>
#include <variant>

// ������������ ��� ������� ������������
enum class What { Year, Month, Day, WeekDay };

// ������� ��� ��������� ��� ������ � ��������� ����
std::string get_weekday(int wday);

// �������, ������� ���������� ������ � ����������� �� ������� ������������
std::string get_date_part(const std::variant<What>& what);