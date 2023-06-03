#pragma once

// ������ �� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//===============//
// � � � � � � � //
//===============//

#define K_EXIT      27 // Esc
#define K_FORWARD   87 // W
#define K_BACKWARD  83 // S
#define K_LEFTWARD  65 // A
#define K_RIGHTWARD 68 // D

//===========//
// � � � � � //
//===========//

#define RED        RGB(255, 0, 0)
#define WHITE      RGB(255, 255, 255)
#define BLACK      RGB(0, 0, 0)
#define WHITE_GRAY RGB(242, 242, 242)
#define BLUE       RGB(0, 0, 255)
#define GREEN      RGB(16, 255, 0)
#define YELLOW     RGB(254, 253, 0)

//=======================//
// � � � �   � � � � � � //
//=======================//

// �������� �������������� �������
struct HdcPos
{
	const HDC& m_hdc;	// �������� �������
	Position m_pos;		// ������� ����� ��������

	HdcPos(const HDC& _hdc, Position _pos)
		: m_hdc(_hdc), m_pos(_pos) {};
};

// �������� ��������������� �������
struct DrawableObjectContext
{
	const HDC& m_hdc;	// �������� �������
	COLORREF m_color;	// ���� ��������� ����� ��������

	DrawableObjectContext(const HDC& _hdc, COLORREF _color)
		:m_hdc(_hdc), m_color(_color) {};
};

// �������� ������������ ������������ ������
struct HitBoxContext
{
	HitBox m_hitbox;	// ������� ����� ��������

	HitBoxContext(HitBox _hb)
		:m_hitbox(_hb) {};
};

// �������� ���� ����� ��������
struct HitBoxDrawableContext :
	public DrawableObjectContext,
	public HitBoxContext
{
	HitBoxDrawableContext(const HDC& _hdc, COLORREF _color, HitBox _hb)
		: DrawableObjectContext(_hdc, _color), HitBoxContext(_hb){}
};