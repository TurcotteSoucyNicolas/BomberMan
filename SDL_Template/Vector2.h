#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	int GetX() { return m_X; };
	int GetY() { return m_Y; };
	void SetVector(int x, int y) { m_X = x, m_Y = y; };

private:
	int m_X;
	int m_Y;
};

