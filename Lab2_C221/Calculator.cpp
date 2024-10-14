#include "Calculator.h"

// ����������� ����������� ������� ��� ���������
std::minus<double> substract;

std::function<double(double, double)>  division = [](const auto& a, const auto& b) {
	if (b==0)
	{
		throw std::invalid_argument("Division by zero");
	}
	return a / b; 
	};

void Calc() {
	double a, b;
	char c;
	//MaxFinder maxfinder;
// ������� ����� ��������
	std::map<char, std::function<double(double, double)>> operations;

	operations['+'] = sum<double>;												//������������� ����������� ���������� �������
	operations['-'] = substract;												//������������� ����������� ������� ����������� ���������� std::minus
	operations['*'] = Multiplication();											//������������� ����������� ��������������� �������
	operations['/'] = division;													//������������� ����������� ������
	operations['^'] = [](double base, double exp) {return std::pow(base, exp); }; //������������� ����������� ������� ����������� ���������� std::pow
	operations['%'] = std::bind(fractional_part, std::bind(std::divides<double>(), std::placeholders::_1, std::placeholders::_2));		//������������� ����������� ������� ����������� ���������� std::bind
	operations['?'] = std::bind(&MaxFinder::maximum, MaxFinder(), std::placeholders::_1, std::placeholders::_2); //������������� ����������� std::bind � ������ ������

	// ���� ���������
	std::cout << "Insert first operand: ";
	std::cin >> a;
	
	// ���� �������� � ���������
	bool isValid = false;
	do
	{
		std::cout << "Insert operations(+, -, *, /, ^, %, ?): " << std::endl;
		std::cin >> c;
		// ���������, �������� �� �������� �������� ����������
		if (operations.find(c) != operations.end())
		{
			isValid = true;
		}
		else
		{
			std::cerr<<"Error: Invalid operation '" << c << "'. Please try again." << std::endl;
		}
	} while (!isValid);// ��������� ����, ���� �� ����� ������� ���������� ��������

    // ���� ������� ��������
	
	// ���� ������� ��������
	std::cout << "Insert second operand: ";
	std::cin >> b;
	
	// ��������� ��������
	try {
		double result = operations[c](a, b);  // �������� ��������
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

}