#include "CPassword.h"
using namespace std;

CPassword::CPassword()
{
	m_Password = "";
}

CPassword::CPassword(const CPassword &p1)
{
	SetPassword(p1.m_Password);
}

CPassword::CPassword(string password)
{
	SetPassword(password);
}

bool CPassword::SetPassword(string newPassword)
{

	if (validatePassword(newPassword))
	{
		m_Password = newPassword;
		return true;
	}
	return false;
}

string CPassword::GetPassword()
{
	return m_Password;
}

bool CPassword::validatePassword(string newPassword)
{
	bool validPassword = true;
	validPassword = validPassword && character(newPassword);
	validPassword = validPassword && lower(newPassword);
	validPassword = validPassword && upper(newPassword);
	validPassword = validPassword && digit(newPassword);
	validPassword = validPassword && special(newPassword);

	return validPassword;
}

bool CPassword::character(string newPassword)
{
	return (newPassword.length() <= m_MaximumPasswordLength && newPassword.length() >= m_MinimumPasswordLength);
}

bool CPassword::lower(string newPassword)
{
	for (char c : newPassword)
	{
		if (isalpha(c))
		{
			if (islower(c))
				return true;
		}
	}
	return false;
}

bool CPassword::upper(string newPassword)
{
	for (char c : newPassword)
	{
		if (isalpha(c))
		{
			if (isupper(c))
				return true;
		}
	}
	return false;
}

bool CPassword::digit(string newPassword)
{
	for (char c : newPassword)
	{
		if (isdigit(c))
			return true;
	}
	return false;
}

bool CPassword::special(string newPassword)
{
	int specialCharCount = 0;
	int supportedSpecialCharCount = 0;
	for (char c : newPassword)
	{
		if (!isdigit(c) && !isalpha(c))
		{
			specialCharCount++;
			for (char specialChar : m_SpecialCharList)
			{
				if (c == specialChar)
				{
					supportedSpecialCharCount++;
					break;
				}
				//its not a digit, an alpha character, or a special character. It is unsupported.
				//return false;
			}
		}
	}
	return (supportedSpecialCharCount > 0 && supportedSpecialCharCount == specialCharCount);
}