
#include "Binary.h"
#include <cmath>

std::vector<bool> Binary::BitsFromDecimal(int decimalValue)
{
	size_t n = static_cast<size_t>(ceil(log2(decimalValue + 1)));
	std::vector<bool> result(n);

	for (size_t i = 0; i < n; ++i)
	{
		int a = static_cast<int>(pow(2, n - i - 1));
		if (decimalValue >= a)
		{
			result[i] = true;
			decimalValue -= a;

			if (decimalValue == 0)
			{
				break;
			}
		}
	}

	return result;
}

Binary::Binary(const std::vector<bool>& bits)
{
	m_bits = bits;
}

Binary::Binary(int decimalValue) : Binary(BitsFromDecimal(decimalValue)) {}

Binary::Binary() : Binary(0) {}

std::vector<bool> Binary::GetBits()
{
	return m_bits;
}

bool Binary::IsPalindrom()
{
	size_t length = static_cast<size_t>(m_bits.size() / 2);

	for (int i = 0; i < length; ++i)
	{
		if (m_bits[i] != m_bits[m_bits.size() - i - 1])
		{
			return false;
		}
	}

	return true;
}

std::string Binary::ToString()
{
	const char ZERO_CHAR = '0';
	const char ONE_CHAR = '1';
	const std::string ZERO_VALUE = "0";

	size_t size = m_bits.size();
	if (size == 0)
	{
		return ZERO_VALUE;
	}

	std::string result(size, ZERO_CHAR);

	for (int i = 0; i < size; ++i)
	{
		if (m_bits[i])
		{
			result[i] = ONE_CHAR;
		}
		else
		{
			result[i] = ZERO_CHAR;
		}
	}

	return result;
}
