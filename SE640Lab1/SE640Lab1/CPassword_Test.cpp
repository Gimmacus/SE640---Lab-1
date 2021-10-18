#define BOOST_TEST_MODULE CPassword_tests
#include <boost/test/included/unit_test.hpp>
#include <string>
#include "CPassword.h"
using namespace std;

BOOST_AUTO_TEST_CASE(Constructor_test)
{
	CPassword pw0;
	BOOST_TEST(pw0.GetPassword() == "");
	CPassword pw1("1Asdfg!");
	BOOST_TEST(pw1.GetPassword() == "1Asdfg!");
	CPassword pw2("xyz!");
	BOOST_TEST(pw2.GetPassword() == "");
	CPassword pw3(pw1);
	BOOST_TEST(pw3.GetPassword() == "1Asdfg!");
	CPassword pw4(pw2);
	BOOST_TEST(pw4.GetPassword() == "");
}

BOOST_AUTO_TEST_CASE(PasswordParamUpper_test)
{
	CPassword pw0;
	BOOST_TEST(pw0.SetPassword("asdfg1!") == false);
	BOOST_TEST(pw0.GetPassword() == "");
	BOOST_TEST(pw0.SetPassword("Asdfg1!") == true);
	BOOST_TEST(pw0.GetPassword() == "Asdfg1!" );
	BOOST_TEST(pw0.SetPassword("1asDfg!") == true);
	BOOST_TEST(pw0.GetPassword() == "1asDfg!");
	BOOST_TEST(pw0.SetPassword("!1asdfG") == true);
	BOOST_TEST(pw0.GetPassword() == "!1asdfG");
	BOOST_TEST(pw0.SetPassword("!1ASDFg") == true);
	BOOST_TEST(pw0.GetPassword() == "!1ASDFg");
}

BOOST_AUTO_TEST_CASE(PasswordParamLower_test)
{
	CPassword pw0;
	BOOST_TEST(pw0.SetPassword("ASDFG1!") == false);
	BOOST_TEST(pw0.SetPassword("aSDFG1!") == true);
	BOOST_TEST(pw0.SetPassword("1ASdFG!") == true);
	BOOST_TEST(pw0.SetPassword("!1ASDFg") == true);
	BOOST_TEST(pw0.SetPassword("!1Asdfg") == true);

}

//SE640 Lab 1 Unit Test
//Shawn Eidem

BOOST_AUTO_TEST_CASE(PasswordParamSpecial_test)
{
	CPassword pw0;
	string base = "Asdfg1";

	BOOST_TEST(pw0.SetPassword(base) == false);
	BOOST_TEST(pw0.SetPassword("!" + base) == true);
	BOOST_TEST(pw0.GetPassword() == ("!" + base));
	BOOST_TEST(pw0.SetPassword("Asd!fg1") == true);
	BOOST_TEST(pw0.GetPassword() == "Asd!fg1");
	BOOST_TEST(pw0.SetPassword("!" + base + "!") == true);
	BOOST_TEST(pw0.GetPassword() == ("!" + base + "!"));
	BOOST_TEST(pw0.SetPassword(base + "!") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "!"));
	BOOST_TEST(pw0.SetPassword(base + "@") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "@"));
	BOOST_TEST(pw0.SetPassword(base + "#") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "#"));
	BOOST_TEST(pw0.SetPassword(base + "$") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "$"));
	BOOST_TEST(pw0.SetPassword(base + "%") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "%"));
	BOOST_TEST(pw0.SetPassword(base + "^") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "^"));
	BOOST_TEST(pw0.SetPassword(base + "&") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "&"));
	BOOST_TEST(pw0.SetPassword(base + "*") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "*"));
	BOOST_TEST(pw0.SetPassword(base + "(") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "("));
	BOOST_TEST(pw0.SetPassword(base + ")") == true);
	BOOST_TEST(pw0.GetPassword() == (base + ")"));
	BOOST_TEST(pw0.SetPassword(base + "_") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "_"));
	BOOST_TEST(pw0.SetPassword(base + "+") == true);
	BOOST_TEST(pw0.GetPassword() == (base + "+"));
	BOOST_TEST(pw0.SetPassword(base + "[") == false);
	BOOST_TEST(pw0.GetPassword() == (base + "+"));
}

BOOST_AUTO_TEST_CASE(PasswordParamDigit_test)
{
	CPassword pw0;
	BOOST_TEST(pw0.SetPassword("Password!") == false);
	BOOST_TEST(pw0.GetPassword() == "");
	BOOST_TEST(pw0.SetPassword("1Password!") == true);
	BOOST_TEST(pw0.GetPassword() == "1Password!");
	BOOST_TEST(pw0.SetPassword("Pass1word!") == true);
	BOOST_TEST(pw0.GetPassword() == "Pass1word!");
	BOOST_TEST(pw0.SetPassword("Password!1") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!1");
	BOOST_TEST(pw0.SetPassword("Password!2") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!2");
	BOOST_TEST(pw0.SetPassword("Password!3") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!3");
	BOOST_TEST(pw0.SetPassword("Password!4") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!4");
	BOOST_TEST(pw0.SetPassword("Password!5") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!5");
	BOOST_TEST(pw0.SetPassword("Password!6") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!6");
	BOOST_TEST(pw0.SetPassword("Password!7") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!7");
	BOOST_TEST(pw0.SetPassword("Password!8") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!8");
	BOOST_TEST(pw0.SetPassword("Password!9") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!9");
	BOOST_TEST(pw0.SetPassword("Password!0") == true);
	BOOST_TEST(pw0.GetPassword() == "Password!0");
	BOOST_TEST(pw0.SetPassword("3Pass22word!1") == true);
	BOOST_TEST(pw0.GetPassword() == "3Pass22word!1");

}

BOOST_AUTO_TEST_CASE(PasswordParamSize_test)
{
	CPassword pw0;
	string length5 = ("Len1!");
	string length6 = ("Leng1!");
	string length10 = ("Length1!Le");
	string length15 = ("Length1!Length1");
	string length16 = ("Length1!Length1!");
	BOOST_TEST(pw0.SetPassword(length5) == false);
	BOOST_TEST(pw0.GetPassword() == "");
	BOOST_TEST(pw0.SetPassword(length6) == true);
	BOOST_TEST(pw0.GetPassword() == length6);
	BOOST_TEST(pw0.SetPassword(length10) == true);
	BOOST_TEST(pw0.GetPassword() == length10);
	BOOST_TEST(pw0.SetPassword(length15) == true);
	BOOST_TEST(pw0.GetPassword() == length15);
	BOOST_TEST(pw0.SetPassword(length16) == false);
	BOOST_TEST(pw0.GetPassword() == length15);
}