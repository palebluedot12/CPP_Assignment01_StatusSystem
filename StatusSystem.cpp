#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void addPotion(int count, int* p_HPPotion, int* p_MPPotion);

int main()
{
	const int SIZE = 4;

	// HP, MP, 공격력, 방어력
	int status[SIZE] = { 0, };

	do
	{
		cout << "HP와 MP를 입력해주세요 : " << endl;
		cin >> status[0] >> status[1];

		if (status[0] <= 50 || status[1] <= 50)
		{
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요" << endl;
		}

	} while (status[0] <= 50 || status[1] <= 50);

	do
	{
		cout << "공격력과 방어력을 입력해주세요 : " << endl;
		cin >> status[2] >> status[3];

		if (status[2] <= 0 || status[3] <= 0)
		{
			cout << "공격력과 방어력중 하나가 0이하입니다. 다시 입력해주세요" << endl;
		}

	} while (status[2] <= 0 || status[3] <= 0);

	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
	cout << "=============================================" << endl;
	cout << "<스탯 관리 시스템>" << endl;
	cout << "1. HP UP" << endl;
	cout << "2. MP UP" << endl;
	cout << "3. 공격력 UP" << endl;
	cout << "4. 방어력 UP" << endl;
	cout << "5. 현재 능력치" << endl;
	cout << "6. Level Up" << endl;
	cout << "0. 나가기" << endl;
	cout << "번호를 선택해주세요 : " << endl;

	int HP_Potion = 0;
	int MP_Potion = 0;
	int Level = 1;
	int LevelCount = 0;

	setPotion(5, &HP_Potion, &MP_Potion);

	bool exitProgram = false; // 프로그램 종료용 플래그
	int choice;

	while (!exitProgram)
	{
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (HP_Potion <= 0)
			{
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			status[0] += 20;
			HP_Potion--;
			cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
			cout << "현재 HP :" << status[0] << endl;
			cout << "남은 포션 수 : " << HP_Potion << endl;
			break;

		case 2:
			if (MP_Potion <= 0)
			{
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			status[1] += 20;
			MP_Potion--;
			cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
			cout << "현재 MP :" << status[1] << endl;
			cout << "남은 포션 수 : " << MP_Potion << endl;
			break;

		case 3:
			status[2] *= 2;
			cout << "* 공격력이 2배로 증가되었습니다." << endl;
			cout << "현재 공격력 : " << status[2] << endl;
			break;

		case 4:
			status[3] *= 2;
			cout << "* 방어력이 2배로 증가되었습니다." << endl;
			cout << "현재 방어력 : " << status[3] << endl;
			break;

		case 5:
			cout << "* HP : " << status[0] << ", MP : " << status[1] <<
				", 공격력 : " << status[2] << ", 방어력 : " << status[3] << ", 레벨 : " << Level << endl;
			cout << "남은 포션 수 : " << HP_Potion << "/" << MP_Potion << endl;
			break;

		case 6:
			cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
			addPotion(1, &HP_Potion, &MP_Potion);
			LevelCount++;
			cout << "남은 HP/MP 포션 수 : " << HP_Potion << "/" << MP_Potion << endl;
			if (LevelCount >= 6)
			{
				Level++;
				LevelCount = 0;
			}
			break;

		case 0:
			cout << "프로그램을 종료합니다." << endl;
			exitProgram = true;
			break;

		default:
			cout << "0부터 6까지의 숫자 중 입력해주세요" << endl;
			break;

		}
	}

}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void addPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion += count;
	*p_MPPotion += count;
}