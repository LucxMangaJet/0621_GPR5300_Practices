#pragma once

#include <iostream>

struct  Vector2Int
{
//public:	<- default to public
	int X;
	int Y;

	Vector2Int() 
	{
		X = 0;
		Y = 0;
	}

	Vector2Int(int x, int y)
	{
		X = x;
		Y = y;
	}

	Vector2Int operator + (const Vector2Int& other) 
	{
		return Vector2Int(Y + other.X, Y + other.Y);
	}

};



class Engine
{
public:
	explicit Engine(int size); //explicit => requires explicit call: Engine e = Engine(10) or Engine e {10};
	//Engine(int size); 
	//implicit => does not require explicit call: 
	//Engine e = 10; <- this would correctly call the Engine(int size) constructor BUT is not a good use because its not readable
	//There should NOT be a direct conversion between int and Engine!

	void Move(int dx, int dy);
	
	std::wstring Draw();

private:

	int m_size;
	Vector2Int m_playerPosition;
};

