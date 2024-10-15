#include "Split.h"

std::vector<std::string_view>split_string(const char* s) {

	std::string_view sv(s); //����������� ������ � string_view
	std::vector<std::string_view> result;

	while (!sv.empty())
	{
		size_t space_pos = sv.find(' ');
		//���� ������ �� ������, ��������� ������� ������
		if (space_pos == std::string_view::npos) {
			result.push_back(sv);
			break;
		}
		// ��������� ����� ����� ��������
		if (space_pos>0)
		{
			result.push_back(sv.substr(0, space_pos));
		}
		// ������� ������������ ����� ������
		sv.remove_prefix(space_pos + 1);
	}
	return result;
}
	