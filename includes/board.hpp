#ifndef BOARD_HPP
# define BOARD_HPP

# include <cstring>
# include <cstdlib>
# include <iostream>

# define RED 1
# define YEL 2

class	Board {
	
	public:
		Board();
		Board(const Board & ref);
		~Board();

		void	print_board();
		int		play_disc(size_t color, size_t nb);
		int		check_win(int color);
		int		is_full();

	private:
		size_t	_width;
		size_t	_height;
		char	**_tab;
		int		check_up(size_t i, size_t j, int color);
		int		check_right(size_t i, size_t j, int color);
		int		check_ru(size_t i, size_t j, int color);
		int		check_lu(size_t i, size_t j, int color);

};

#endif