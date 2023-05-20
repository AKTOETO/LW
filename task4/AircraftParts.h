
// ����� ������������ ��������� �����������
// �������� ������������ �������
enum class Dir
{
	STOP,   // ��� ��������
	UP,     // �����
	DOWN,   // ����
	LEFT,   // �����
	RIGHT   // ������
};

// ��������������
class Position
{
protected:
	int m_x;
	int m_y;
public:
	Position(int _x, int _y) :m_x(_x), m_y(_y) {};
	Position(const Position& _pos)
	{
		this->m_x = _pos.m_x;
		this->m_y = _pos.m_y;
	}
	Position() = delete;

	Position* SetX(int _x) { m_x = _x; return this; }
	Position* SetY(int _y) { m_y = _y; return this; }

	const int& GetX() const { return m_x; }
	const int& GetY() const { return m_y; }
};

// ��������� �����
class IAircraftPart
{
	// ��������� ������
	virtual void Draw(const Position&) = 0;

	// ����� ����� ��������
	virtual void Move(Dir) = 0;
};

// ����� ��������
class AircraftPart :
	public IAircraftPart
{
private:
	// ������� ����� ��������
	Position* m_pos;


};

// ����������� ����� ����
class Body :
	public IAircraftPart
{

};

// ��������� ������
class ITail
{

};