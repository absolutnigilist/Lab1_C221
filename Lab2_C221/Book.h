#pragma once
#include <iostream>
#include <tuple>
#include <string>



class book {
	std::tuple<std::string, std::string, int> data;
	
public:
	// ����������� � �������������� �������
	book(const std::string& author, const std::string& title, int year);

	// ������ ��� ��������� ��������� ����������� �����
	
	const std::string& get_author()const;		//�������� ������
	
	const std::string& get_title()const; 		//�������� ��������
	
	const int& get_year()const;						//������� ��� �������
	
	//�������� ��������� ����

	bool operator<(const book& other) const;	//������������������ ��������� ��������
	
	bool operator==(const book& other) const;	// �������� �� ��������� ��������

	// �������� ������ ��� �����
	friend std::ostream& operator<<(std::ostream& os, const book& other);
	
};
