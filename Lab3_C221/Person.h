#pragma once

#include <string>
#include <optional>
#include <iostream>

class Person {
public:
	std::string m_name;
	unsigned int m_age;
	std::optional<std::string> m_nick; // std::optional ��� ��������

	Person(const std::string& name, unsigned int age, std::optional<std::string> nick = std::nullopt);
	
	// ����� ��� ����������� ���������� � ��������
	void print()const;


};
