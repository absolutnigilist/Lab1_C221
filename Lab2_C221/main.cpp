#include "Header.h"
#include "Point.h"
#include "Book.h"
#include "Library.h"
#include <tuple>

int main() {
	//1. std::tuple<>, std::tuple_size<>::value,
	//	���������� ������� ������ ������ tuple, ��������:
	std::tuple t1{ 1, 2.2, "abc"};
	std::cout << t1;
	printTuple(t1);

	std::tuple t2{ std::string("abc"), 1, 2.2, Point(1,2) };
	printTuple(t2);

	book b1("A","B",123);
	std::cout << b1;

    // �������� ���������� � �������
    book my_favorite_book{ "Willims", "Parallel C++", 2014 };
    library l = { {"Straustrup", "C++", 2000}, my_favorite_book };

    // ���������� ����
    l.add({ {"Straustrup", "C++", 2000}, {"Straustrup", "C++", 2010}, {"Golovic", "Advanced", 2008} });

    // ����� ���� �� ������
    std::cout << "Books by author:" << std::endl;
    l.ByAuthor();

    // ����� ���� �� ��������
    std::cout << "Books by title:" << std::endl;
    l.ByTitle();

    // ����� ���� �� ����
    std::cout << "Books by year:" << std::endl;
    l.ByYear();

    // �������� �����
    l.remove({ "Straustrup", "C++", 2000 });
	return 0;
}