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
                /*rotation cases for BLOCK_t*/
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
                            this->rotation = TWOSEVENTY;
                            break;
                        }
                        case TWOSEVENTY:
                        {
                            this->position[Y] += 1;
                            this->rotation = ZERO;
                            break;
                        }
                        default:
                        {
                            //this should not happen
                            std::cout << "Error: Invalid rotation value of BLOCK_t!\n";
                            break;
                        }
                    }
                    break;
                }
                /*leaving BLOCK_square out, too simple*/
                /*rotation cases for BLOCK_l_normal*/
                case BLOCK_l_normal:
                {
                    switch(this->rotation)
                    {
                        case ZERO:
                        {
                            this->position[X] -= 1;
                            this->position[Y] -= 1;
                            this->rotation = NINETY;
                            break;
                        }
                        case NINETY:
                        {
                            this->position[X] += 1;
                            this->position[Y] -= 1;
                            this->rotation = ONEEIGHTY;
                            break;
                        }
                        case ONEEIGHTY:
                        {
                            this->position[X] += 1;
                            this->position[Y] += 2;
                            this->rotation = TWOSEVENTY;
                            break;
                        }
                        case TWOSEVENTY:
                        {
                            this->position[X] -= 1;
                            this->rotation = ZERO;
                            break;
                        }
                        default:
                        {
                            //this should not happen
                            std::cout << "Error: Invalid rotation value of BLOCK_l_normal!\n";
                            break;
                        }
                    }
                }
                /*rotation cases for BLOCK_l_mirror*/
                case BLOCK_l_mirror:
                {
                    switch(this->rotation)
                    {
                        case ZERO:
                        {
                            this->position[X] -= 1;
                            break;
                        }
                        case NINETY:
                        {
                            this->position[X] += 1;
                            this->position[Y] -= 2;
                            break;
                        }
                        case ONEEIGHTY:
                        {
                            this->position[X] += 1;
                            this->position[Y] += 1;
                            break;
                        }
                        case TWOSEVENTY:
                        {
                            this->position[X] -= 1;
                            this->position[Y] += 1;
                            break;
                        }
                        default:
                        {
                            //this should not happen
                            std::cout << "Error: Invalid rotation value of BLOCK_l_mirror!\n";
                            break;
                        }
                    }
                }
                default:
                {
                    //this should not happen
                    std::cout << "Error: Invalid block value!\n";
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
