#include "CommandParser.h"
#include <string>
#include <iostream>

using namespace std;

unsigned short CommandParser::parseCommand()
{
	string input; //String type for simplicity

	cin >> input;

	if (!input.compare("insert"))
		return 1;
	if (!input.compare("delete"))
		return 2;
	else if (!input.compare("find"))
		return 3;
	else if (!input.compare("traverseInorder"))
		return 4;

	return 0; //Return 0 in all cases, excluding the ones written above; We assume that a valid command is always given!
}