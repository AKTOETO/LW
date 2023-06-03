#include <iostream>

using namespace std;

// ��������� ���������������
class IElectricalAppliance
{
protected:
	// ������������ �������������
	virtual void ConsumeElectricity(int&) = 0;

public:
	// ���������� ��������� ��������
	// ����������� - ���������
	// ������ - �������
	// ������������� - ��������
	virtual void MainFunction() = 0;
};

// ��������������
class Position
{
protected:
	int m_x;
	int m_y;
public:
	Position(int _x, int _y) :m_x(_x), m_y(_y) {};
	Position() = delete;

	void SetX(int _x) { m_x = _x; }
	void SetY(int _y) { m_y = _y; }

	const int& GetX() const { return m_x; }
	const int& GetY() const { return m_y; }
};

// ����������� ����� ��������� ������������
class KitchenAppliance :
	public IElectricalAppliance,
	public Position
{
protected:
	// ��� �������
	string m_name;

	// ������ �������������
	int m_electricity_consumption;

	// ���������� ������� ������� �������������
	virtual void ConsumeElectricity(int& _cur_electricity) override
	{
		_cur_electricity -= m_electricity_consumption;
		cout << m_name << " consume electricity. cur level: " << m_electricity_consumption << endl;
	}
public:
	KitchenAppliance(int _x, int _y, int _el_cons, string _name) :
		Position(_x, _y), m_electricity_consumption(_el_cons), m_name(_name)
	{
		cout << "kitchen appliance creating\n";
	};

	virtual ~KitchenAppliance()
	{
		cout << "kitchen appliance destroying\n";
	};

	virtual void MainFunction() override
	{
		cout << m_name << ": ";
	};

	virtual void Draw() = 0;
};

// �����������
class Fridge :
	public KitchenAppliance
{
protected:
	int m_current_temp;
	int m_temp_reducing;

public:
	Fridge(int _cur_temp, int _x, int _y)
		:KitchenAppliance(_x, _y, 10, "fridge"), m_temp_reducing(1), m_current_temp(_cur_temp)
	{
		cout << "fridge creating\n";
	}

	virtual ~Fridge() override
	{
		cout << "fridge destroying\n";
	};

	// ���������� ����������� ��������� � ������������
	virtual void MainFunction() override
	{
		KitchenAppliance::MainFunction();
		m_current_temp -= m_temp_reducing;
		cout << " current temp: " << m_current_temp << endl;
	}

	virtual void Draw() override
	{
		cout << "drawing fridge at position:" << GetX() << " " << GetY() << endl;
	}
};

// �������������
class Kettle :
	public KitchenAppliance
{
private:
	int m_water_temp;
	int m_heating_temp;

public:
	Kettle(int _water_temp, int _x, int _y)
		:KitchenAppliance(_x, _y, 5, "kettle"), m_heating_temp(10), m_water_temp(_water_temp)
	{
		cout << "kettle creating\n";
	}
	virtual ~Kettle() override
	{
		cout << "kettle destroying\n";
	};

	// ���������� ����������� ���� � �������
	virtual void MainFunction() override
	{
		KitchenAppliance::MainFunction();
		m_water_temp += m_heating_temp;
		cout << " current water temp: " << m_water_temp << endl;
	}

	virtual void Draw() override
	{
		cout << "drawing kettle at position:" << GetX() << " " << GetY() << endl;
	}
};

// �������������
class Squeezer :
	public KitchenAppliance
{
private:
	int m_degree_of_readiness;
	int m_readiness_increase;

public:
	Squeezer(int _deg, int _x, int _y)
		:KitchenAppliance(_x, _y, 1, "jucier"), m_readiness_increase(10), m_degree_of_readiness(_deg)
	{
		cout << "Squeezer creating\n";
	}
	virtual ~Squeezer() override
	{
		cout << "Squeezer destroying\n";
	};

	// ���������� ����������� ���� � �������
	virtual void MainFunction() override
	{
		KitchenAppliance::MainFunction();
		m_degree_of_readiness += m_readiness_increase;
		cout << " current readiness degree: " << m_degree_of_readiness << endl;
	}

	virtual void Draw() override
	{
		cout << "drawing Squeezer at position:" << GetX() << " " << GetY() << endl;
	}
};

int main()
{
	const int num = 3;

	//// ������� �����
	//KitchenAppliance* kitchen[num] =
	//{
	//	new Fridge(20, 10, 15),
	//	new Kettle(15, 50, 20),
	//	new Squeezer(0, 30, 20)
	//};

	//// ��������� �������� �����
	//for (int i = 0; i < num; i++)
	//{
	//	kitchen[i]->MainFunction();
	//	kitchen[i]->Draw();
	//}

	//// �������� ������� �����
	//for (int i = 0; i < num; i++)
	//	delete kitchen[i];
	return 0;
}