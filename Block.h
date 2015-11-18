#ifndef BLOCK_H_
#define BLOCK_H_

#define X 0
#define Y 1

typedef enum
{
	BLOCK_t,
	BLOCK_square,
	BLOCK_l_normal,
	BLOCK_line,
	BLOCK_s,
	BLOCK_z,
	BLOCK_l_mirror,
	BLOCK_number
}BLOCK;

typedef enum
{
	ZERO,
	NINETY,
	ONEEIGHTY,
	TWOSEVENTY
}ROTATION;

namespace Block
{
	class Block
	{
		public:
			Block();
			~Block();

			BLOCK BlockType();
			void rotate_right();
			void rotate_left();

		private:
			BLOCK type;
			ROTATION rotation;
			unsigned short int pos[2];

	};
}

#endif /* BLOCK_H_ */
