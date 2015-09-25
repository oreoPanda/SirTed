#define GAMEWIDTH 10
#define GAMEHEIGHT 18

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
struct block
{
	BLOCK type;
	unsigned short int pos[2];
	unsigned short int rotation;
};

int game_area[GAMEWIDTH][GAMEHEIGHT];
struct block falling;
BLOCK next;
