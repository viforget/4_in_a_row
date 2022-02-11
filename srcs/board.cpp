#include "board.hpp"

Board::Board() : _width(7), _height(6)
{
	this->_tab = new char* [this->_width];
	for (size_t i = 0; i < this->_width; i++)
	{
		this->_tab[i] = new char [this->_height];
		memset(this->_tab[i], 0, this->_height);
	}
}

Board::Board(const Board & ref) : _width(ref._width), _height(ref._height)
{
	this->_tab = new char* [this->_width];
	for (size_t i = 0; i < this->_width; i++)
	{
		this->_tab[i] = new char [this->_height];
		memcpy(this->_tab[i], ref._tab[i], this->_height);
	}
}

Board::~Board()
{
	for (size_t i = 0; i < this->_width; i++)
		delete this->_tab[i];
	delete this->_tab;
}

void	Board::print_board()
{
	std::system("clear");
	std::cout << std::endl;
	for (size_t i = this->_height - 1; i != static_cast<size_t>(-1); i--)
	{
		for (size_t j = 0; j < this->_width; j++)
		{
			switch (this->_tab[j][i])
			{
				case RED:
					std::cout << "🔴";
					break;
				case YEL:
					std::cout << "🔶";
					break;
				default :
					std::cout << "⚪";
					break;
			}
		}
		std::cout << std::endl;
	}
	std::cout << "1 2 3 4 5 6 7" << std::endl << "--------------" << std::endl;
}

int		Board::play_disc(size_t color, size_t nb)
{
	size_t	i = 0;

	if (nb >= this->_width) {return(-1);}
	while (i < this->_height)
	{
		if (this->_tab[nb][i] == 0)
		{
			this->_tab[nb][i] = color;
			return (1);
		}
		i++;
	}
	return (0);
}

int		Board::check_right(size_t i, size_t j, int color)
{
	if (j <= this->_height - 4)
	{
		if (this->_tab[j][i] == color
			&& this->_tab[j + 1][i] == color
			&& this->_tab[j + 2][i] == color
			&& this->_tab[j + 3][i] == color)
			return (1);
	}
	return (0);
}

int		Board::check_up(size_t i, size_t j, int color)
{
	if (i <= this->_width - 4)
	{
		if (this->_tab[j][i] == color
			&& this->_tab[j][i + 1] == color
			&& this->_tab[j][i + 2] == color
			&& this->_tab[j][i + 3] == color)
			return (1);
	}
	return (0);
}

int		Board::check_ru(size_t i, size_t j, int color)
{
	if (j <= this->_width - 4 && i <= this->_height - 4)
	{
		if (this->_tab[j][i] == color
			&& this->_tab[j + 1][i + 1] == color
			&& this->_tab[j + 2][i + 2] == color
			&& this->_tab[j + 3][i + 3] == color)
			return (1);
	}
	return (0);
}

int		Board::check_lu(size_t i, size_t j, int color)
{
	if (j >= 4 && i <= this->_height - 4)
	{
		if (this->_tab[j][i] == color
			&& this->_tab[j - 1][i + 1] == color
			&& this->_tab[j - 2][i + 2] == color
			&& this->_tab[j - 3][i + 3] == color)
			return (1);
	}
	return (0);
}

int		Board::check_win(int color)
{
	for (size_t j = 0; j < this->_width; j++)
	{
		for (size_t i = 0; i < this->_height; i++)
		{
			if (this->_tab[j][i] == color)
			{
				if (check_up(i, j, color) || check_right(i, j, color)
				|| check_ru(i, j, color) || check_lu(i, j, color))
					return (1);
			}
		}
	}
	return(0);
}
