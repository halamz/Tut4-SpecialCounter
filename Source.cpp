#include<iostream>

using namespace std;

class SpecialCount
{
private:
	int starting;
	int stoping;
	int StepInc;
	int StepDec;
public:
	SpecialCount();
	void Start(int start);
	void Stop(int stop);
	void stepInc(int stepSize);
	void stepDec(int stepSize);
	SpecialCount operator + (SpecialCount);
	SpecialCount operator - (SpecialCount);
	int getStarting();
	int getStoping();
	void plus1();
	void minus1();
	~SpecialCount();
};

int SpecialCount::getStarting()
{
	return starting;
}

int SpecialCount::getStoping()
{
	return stoping;
}
SpecialCount::SpecialCount()
{
	starting = 0;
	stoping = 255;
	StepInc = 1;
	StepDec = 1;
}

void SpecialCount::Start(int start)
{
	starting = start;
}

void SpecialCount::Stop(int stop)
{
	stoping = stop;
}

void SpecialCount::stepInc(int Stepsize)
{
	StepInc = Stepsize;
}

void SpecialCount::stepDec(int Stepsize)
{
	StepDec = Stepsize;
}

SpecialCount operator + (SpecialCount count)
{
	int value=count.getStarting();
	value = +1;
	count.Start(value);
	return count;
}

SpecialCount operator - (SpecialCount count)
{
	int value=count.getStarting();
	value = -1;
	count.Start(value);
	return count;
}

void SpecialCount::plus1()
{
	starting += StepInc;
}
void SpecialCount::minus1()
{
	stoping -= StepDec;
}
SpecialCount::~SpecialCount()
{

}
int main()
{
	SpecialCount obj,obj1,obj2;
	obj.Start(20);
	obj.Stop(210);
	obj.stepInc(3);
	obj.stepDec(3);
	obj1 = obj;
	obj2 = obj;
	cout << "Counting up\n" << obj1.getStarting() << endl;
	while (obj1.getStarting() <= obj1.getStoping())
	{
		obj1.plus1();
		cout << obj1.getStarting() << endl;
	}
	
	cout << "\n\n Counting Down\n" << obj2.getStoping()<< endl;
	while (obj2.getStarting() <= obj2.getStoping())
	{
		obj2.minus1();
		cout << obj2.getStoping() << endl;
	}
}