#pragma once
class Base
{
private:
	int x, y, z;
public:
	virtual void DoSomething() = 0;
	Base()
	{
		x = 5;
		y = 10;
		z = 15;
	}
};

class Level1a : Base
{
private:
	float a;
	double b;
public:
	virtual void DoSomething()
	{

	};
	Level1a()
	{
		a = 3.124;
		b = 5.67889;
	}
};

class Base2
{
private:
	int data[10];
public:
	virtual void SomeMethod() = 0;

	Base2()
	{
		for (int i = 0; i < 10; i++)
		{
			data[i] = i;
		}
	}
};

class Level2 : Base2
{
private:
	int ab;
	int bc;
	float fl;
public:
	virtual void SomeMethod() = 0;

	Level2()
	{
		ab = 10000;
		bc = 20000;
		fl = 123.456;
	}
};

class Level3 : Level1a, Level2
{
private:
	int ghi;
	float test[5];
public:
	virtual void Something() = 0;
	virtual void SomeMethod()
	{
		for (int i = 0; i < 5; i++)
		{
			test[i] = 2.4 * i;
		}
	};
};

class Level4 : Level3
{
private:
	double mno[10];
public:
	virtual void Something()
	{

	};
	Level4()
	{
		for (int i = 0; i < 10; i++)
		{
			mno[i] = i * 124.5;
		}
	}
};

class Level5 : public Level4
{
private:
	int data[5];
public:
	Level5()
	{
		for (int i = 0; i < 5; i++)
		{
			data[i] = i * 10;
		}
	}
};

class Level6 : public Level5
{
private:
	int data[5];
public:
	Level6()
	{
		for (int i = 0; i < 5; i++)
		{
			data[i] = i * 10;
		}
	}
};

class Level7 : public Level6
{
private:
	int data[5];
public:
	Level7()
	{
		for (int i = 0; i < 5; i++)
		{
			data[i] = i * 10;
		}
	}
};

class Level8 : public Level7
{
private:
	int data[5];
public:
	Level8()
	{
		for (int i = 0; i < 5; i++)
		{
			data[i] = i * 10;
		}
	}
};

class Level9 : public Level8
{
private:
	int data[5];
public:
	Level9()
	{
		for (int i = 0; i < 5; i++)
		{
			data[i] = i * 10;
		}
	}
};

class Level10 : public Level9
{
private:
	int data[5];
public:
	Level10()
	{
		for (int i = 0; i < 5; i++)
		{
			data[i] = i * 10;
		}
	}
};

class Level11 : public Level10
{
private:
	int data[5];
public:
	Level11()
	{
		for (int i = 0; i < 5; i++)
		{
			data[i] = i * 15;
		}
	}
};