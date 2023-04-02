#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;

class someException
{
	string message;

public:
	someException(const string& input)
	{
		message = "\"" + input + "\" does not exist, please try again.";
	}

	char const* what()const
	{
		return message.c_str();
	}
};