#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
#include <conio.h>

#define WEAPON_STAR 25
using namespace std;

int main() {
	string name[WEAPON_STAR] = {
		"일검",
		"이검",
		"삼검",
		"사검",
		"오검",
		"육검",
		"칠검",
		"팔검",
		"구검",
		"십검",
		"십일검",
		"십이검",
		"십삼검",
		"십사검",
		"십오검",
		"십육검",
		"십칠검",
		"십팔검",
		"십구검",
		"이십검",
		"이십일검",
		"이십이검",
		"이십삼검",
		"이십사검",
		"이십오검",
	};
	int level = 0;
	int free = 100;
	int plusticket = 1;
	int probability = 100;
	int myprobability;
	int number;

	srand((int)time(NULL));

	cout << "제작자: 유한대학교 학생" << endl;

	Sleep(2000);

	while (true)
	{
		system("cls");

		cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
		cout << "" << endl;
		cout << "                                        ┌─────────────────────────────────┐" << endl;
		cout << "                                        │ 유한 강화소에 오신걸 환영합니다.│" << endl;
		cout << "                                        └─────────────────────────────────┘" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "                       소지금 : " << free << " Coin" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "                       강화 레벨 : " << level << "강" <<  endl;
		cout << "                       강화 확률 : " << probability << "%" << endl;
		cout << "" << endl;
		cout << "                       무기 이름 : " << name[level] << endl;
		cout << "                       무기 가격 : " << plusticket << " Coin" << endl;
		cout << "" << endl;
		cout << "                      ┌─────┐" << endl;
		cout << "                      │ 메뉴│" << endl;
		cout << "                      └───┬─┘" << endl;
		cout << "                          ├ [ 1 ] 무기 강화" << endl;
		cout << "                          ├ [ 2 ] 무기 판매" << endl;
		cout << "                          └ [ 3 ] 게임 종료" << endl;
		cout << "" << endl;
		cout << "└┬─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
		cout << " └ 입력 : ";
		cin >> number; 

		switch (number) {
		case 1: {
			if (free > 0) {
				system("cls");

				cout << "강화 중..." << endl;

				Sleep(1500);

				myprobability = rand() % 100;

				if (myprobability <= probability) {
					system("cls");

					cout << "강화 성공!" << endl;
					probability -= 5;
					level++;
					plusticket += 2;
					free--;

					Sleep(500);
				} else {
					system("cls");

					cout << "강화 실패!" << endl;
					free--;

					Sleep(500);
				}

				if (level == WEAPON_STAR - 1) {
					cout << "이름 : " << name[level] << endl;
					cout << "게임 클리어!" << endl;
					cout << "축하드립니다." << endl << endl;
					cout << "게임을 종료합니다." << endl;

					Sleep(2000);
					exit(0);
				}
			} else {
				system("cls");
				cout << "소지금이 부족합니다." << endl;
				Sleep(1000);
				break;
			}
			break;
		case 2:
		{
			system("cls");

			cout << "무기를 팔고 소지금을 얻습니다." << endl;
			free += plusticket;
			level = 0;
			probability = 100;
			plusticket = 1;

			Sleep(2000);
			break;
		}
		case 3:
			system("cls");

			cout << "종료중 . . ." << endl;

			Sleep(2000);
			cout << "종료되었습니다." << endl;
			exit(0);
		}

		default:

			system("cls");

			cout << "숫자만 입력 가능합니다." << endl;
			Sleep(1000);
			break;
		}
	}
	return 0;
}