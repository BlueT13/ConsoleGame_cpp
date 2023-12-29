#pragma once
class StatusUnit
{
public:
	int GetSpeed();
	int GetMinAtt();
	int GetMaxAtt();

	void SetSpeed(int _Speed);
	void SetMinAtt(int _MinAtt);
	void SetMaxAtt(int _MaxAtt);
	void SetName(const char* _Name);
	void StatusRender();


protected:
	char Name[100] = "None";
	int Hp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 0;
};

