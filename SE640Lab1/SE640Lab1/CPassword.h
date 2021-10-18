#ifndef CPASSWORD
#define CPASSWORD
#pragma once
#include <string>
#include <vector>
class CPassword
{
	public:
		CPassword();
		CPassword(const CPassword& p1);
		CPassword(std::string);

		bool SetPassword(std::string);
		std::string GetPassword();
		const int m_MinimumPasswordLength = 6;
		const int m_MaximumPasswordLength = 15;
		const std::vector<char> m_SpecialCharList = {'~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+'};
		
	private:
		std::string m_Password;
		bool validatePassword(std::string);
		bool character(std::string);
		bool lower(std::string);
		bool upper(std::string);
		bool digit(std::string);
		bool special(std::string);
};
#endif