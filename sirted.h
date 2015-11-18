#ifndef SIRTED_H
#define SIRTED_H

#define GAMEWIDTH 10
#define GAMEHEIGHT 18

#define X 0
#define Y 1

struct block
{
	BLOCK type;
	unsigned short int pos[2];
	unsigned short int rotation;
};

#endif //SIRTED_H
