#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

class CommandParser
{
public:
	//0 - Exit, 1 - Insert, 2 - Delete, 3 - Find, 4 - Traverse In Order
	unsigned short parseCommand();
};

#endif