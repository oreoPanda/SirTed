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

	void Block::rotate_right()
	{
		if( this->rotation != TWOSEVENTY )
		{
			rotation += 1;
		}
		else
		{
			this->rotation = NINETY;
		}
		return;
	}

	void Block::rotate_left()
	{
		if( this->rotation != NINETY )
		{
			this->rotation -= 1;
		}
		else
		{
			this->rotation = TWOSEVENTY;
		}
		return;
	}

	Block::~Block()
	{
		cout << "Destroyed block class" << endl;
	}
}
