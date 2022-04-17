
#pragma once

#include <vector>
#include <string>

class Binary
{
private:
	std::vector<bool> m_bits;

	static std::vector<bool> BitsFromDecimal(int decimalValue);

public:
	Binary(const std::vector<bool>& bits);

	Binary(int decimalValue);

	Binary();

	std::vector<bool> GetBits();

	bool IsPalindrom();

	std::string ToString();
};
