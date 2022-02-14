#include "board.hpp"

int turn(Board & bb, int color)
{
	std::string	buf;
	int	input = 0;

	while (input < 1 || input > 7)
	{
		switch (color)
		{
			case(RED):
				std::cout << "🔴 RED TURN : ";
				break;
			case(YEL):
				std::cout << "🔶 YELLOW TURN : ";
				break;
		}
		std::getline(std::cin, buf);
		input = atoi(buf.c_str());
		if (bb.play_disc(color, input - 1) <= 0)
			input = 0;
	}
	bb.print_board();
	if (bb.check_win(color))
	{
		switch (color)
		{
			case(RED):
				std::cout << "⭕ RED WON ⭕" << std::endl;
				break;
			case(YEL):
				std::cout << "💛 YELLOW WON 💛" << std::endl;
				break;
		}
		return(1);
	}
	return (0);
}

int main()
{
	Board 		bb;
	int			end = 0;

	bb.print_board();
	while(!end && !bb.is_full())
	{
		end = turn(bb, RED);
		if (!end && !bb.is_full())
			end = turn(bb, YEL);
	}
	if (bb.is_full() && !bb.check_win(YEL) && !bb.check_win(RED))
		std::cout << "👔 TIE 👔" << std::endl;
}
