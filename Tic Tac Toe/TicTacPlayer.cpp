#include "TicTacPlayer.h"

char Player::GetSymbol()
{
	return m_cSymbol;
}
void Player::initialise(char symbol)
{
	m_cSymbol = symbol;
}