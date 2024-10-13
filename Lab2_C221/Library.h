#pragma once

#include "Book.h"
#include "Sort.h"`1	
#include <set>
#include <vector>
#include <functional>

extern std::vector<std::function<bool(const book&, const book&)>>comparators;

class library {
	std::multiset<book> books;
public:
	// ����������� �� ��������� (������ ����������)
	library() = default;
	
	// ����������� � �������������� ����
	library(std::initializer_list<book> initBooks);

	// ��������� ����������� � ������������
	library(const library&) = delete;
	library& operator=(const library&) = delete;

	// ��������� �����������
	library(library&&) = delete;
	library& operator=(library&&) = delete;

	// ���������� ���� � ����������
	void add(std::initializer_list<book>newBooks) {
		books.insert(newBooks.begin(), newBooks.end());
	}
	// ��������������� ������� ��� ������ ��������������� ����������
	void printSorted(const std::function<bool(const book&, const book&)>& comp)const;
	
	// ������� ��� ������ ���� 
	void printBook(const std::vector<book>& booksToPrint)const;
	
	// ����� ����������, ��������������� �� ������
	void ByAuthor()const;

	// ����� ����������, ��������������� �� ��������
	void ByTitle()const;

	//����� ����������, ��������������� �� ����
	void ByYear()const;
	
	// �������� ����� (����� ����� �� ���� ����������)
	bool remove(const book& b);
};


