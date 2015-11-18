#include "Block.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

namespace Block
{
	Block::Block();
	{
		cout << "Constructed block class" << endl;
	}

	BLOCK Block::BlockType ()
	{
		time_t t;
		time(&t);
		srand((unsigned int)t);

		return rand() % BLOCK_number;
	}

	Block::~Block()
	{
		cout << "Destroyed block class" << endl;
	}
}
