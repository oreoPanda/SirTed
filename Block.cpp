#include "Block.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace Block
{
	Block::Block()
	{
		std::cout << "Constructed block class" << std::endl;
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
		switch(this->type)
		{
			case BLOCK_t:
			{
				switch(this->rotation)
				{
					case ZERO:
					{
						this->position[Y] -= 1;
						this->rotation = NINETY;
						break;
					}
					case NINETY:
					{
						this->rotation = ONEEIGHTY;
						break;
					}
					case ONEEIGHTY:
					{
						this->position[X] += 1;
						this->rotation = TWOSEVENTY;
						break;
					}
					case TWOSEVENTY:
					{
						this->position[X] -= 1;
						this->position[Y] += 1;
						this->rotation = ZERO;
						break;
					}
					default:
					{
						//this should not happen
						break;
					}
				}
				break;
			}
			/*leaving BLOCK_square out, too simple*/
			default:
			{
				//this should not happen
				break;
			}
		}
		return;
	}

	void Block::rotate_left()
	{
		switch(this->type)
		{
			case BLOCK_t:
			{
				switch(this->rotation)
				{
					case ZERO:
					{
						this->position[X] += 1;
						this->position[Y] -= 1;
						this->rotation = TWOSEVENTY;
						break;
					}
					case NINETY:
					{
						this->position[Y] += 1;
						this->rotation = ZERO;
						break;
					}
					case ONEEIGHTY:
					{
						this->rotation = NINETY;
						break;
					}
					case TWOSEVENTY:
					{
						this->position[X] -= 1;
						this->rotation = ONEEIGHTY;
						break;
					}
					default:
					{
						//this should not happen
						break;
					}
				}
				break;
			}
			/*leaving BLOCK_square out, too simple*/
			default:
			{
				//this should not happen
				break;
			}
		}
		return;
	}

	Block::~Block()
	{
		std::cout << "Destroyed block class" << std::endl;
	}
}
