#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <ctime>
#include <cstdlib>

#define WEAPON_STAR 25
using namespace std;

// 로그를 기록하는 함수
void logMessage(const string& message) {
    ofstream logFile("log.csv", ios::app);
    if (logFile.is_open()) {
        time_t now = time(0);
        struct tm ltm;
        localtime_s(&ltm, &now);
        logFile << ltm.tm_year + 1900 << "-" << ltm.tm_mon + 1 << "-" << ltm.tm_mday << " "
            << ltm.tm_hour << ":" << ltm.tm_min << ":" << ltm.tm_sec << ","
            << message << endl;
        logFile.close();
    }
    else {
        cout << "로그 파일을 열 수 없습니다." << endl;
    }
}

// 검 이름
string generateWeaponName(int level) {
    string prefix[] = { "광휘의", "신성한", "불타는", "영웅의", "태양의", "무적의", "용감한", "수호의", "전설의", "강력한" };
    string suffix[] = { "무의", "명의", "신의", "마의", "검의", "마검의", "기의", "비의", "천의", "신검의" };
    return prefix[level % 10] + " " + suffix[level % 10] + " 검";
}

int main() {
    int level = 0;              // 현재 무기 강화 레벨
    int free = 100;             // 소지금
    int enhanceCost = 1;        // 초기 강화 비용
    int sellPrice = 1;          // 초기 판매 가격
    double probability = 100.0; // 강화 성공 확률 (0 ~ 100)
    int choice;                 // 사용자 선택
    int sellCount = 0;          // 판매 횟수

    srand(time(nullptr));   // 시드 설정

    cout << "제작자: 유한대학교 학생" << endl;
    Sleep(2000);


    while (true) {
        system("cls");

        cout << "┌──────────────────────────────────────────────────────────────────────────────────────┐" << endl;
        cout << "│                                  유한 강화소에 오신걸 환영합니다.                       │" << endl;
        cout << "├──────────────────────────────────────────────────────────────────────────────────────┤" << endl;
        cout << "│ 소지금: " << free << " Coin" << endl;
        cout << "│ 강화 레벨: " << level << "강" << endl;
        if (level < WEAPON_STAR) {
            cout << "│ 강화 확률: " << probability << "%" << endl;
        }
        else {
            cout << "│ 최강 검을 얻었습니다." << endl;
        }
        cout << "│ 무기 이름: " << generateWeaponName(level) << endl;
        cout << "│ 판매 가격: " << sellPrice << " Coin" << endl; // 판매 가격 출력
        cout << "├──────────────────────────────────────────────────────────────────────────────────────┤" << endl;
        cout << "│ [1] 무기 강화    [2] 무기 판매    [3] 게임 종료                                     │" << endl;
        cout << "└──────────────────────────────────────────────────────────────────────────────────────┘" << endl;
        cout << "입력: ";
        cin >> choice;

        switch (choice) {
        case 1: // 무기 강화
            if (free >= enhanceCost) { // 사용자가 강화 비용을 감당할 수 있는지 확인
                cout << "강화 중..." << endl;
                Sleep(1500);

                if (level < WEAPON_STAR) {
                    if (rand() % 100 < probability) {
                        cout << "강화 성공!" << endl;
                        level++;
                        free -= enhanceCost;    // 강화 비용 차감
                        enhanceCost *= 1.5;       // 강화 비용 증가
                        sellPrice *= 2;         // 판매 가격 3배 증가
                        probability *= 0.81;    // 강화 확률을 0.81 배율로 증가
                    }
                    else {
                        cout << "강화 실패!" << endl;
                        free -= enhanceCost;    // 강화 비용 차감
                        // 강화 실패 시 이전 확률을 유지
                    }
                }
                else {
                    cout << "최강 검을 얻었습니다." << endl;
                    Sleep(2000);
                    exit(0);
                }

                
                logMessage("무기 강화 시도");
            }
            else {
                cout << "소지금이 부족합니다." << endl;
                Sleep(1000);
            }
            break;
        case 2: // 무기 판매
            if (level > 0) { // 무기가 0강이 아닌 경우에만 판매 가능
                cout << "무기를 팔고 소지금을 얻습니다." << endl;
                free += sellPrice;
                level = 0;
                sellPrice = 1; // 판매 가격 초기값으로 설정
                enhanceCost = 1; // 강화 비용 초기값으로 설정
                probability = 100.0; // 강화 확률 초기값으로 설정
                sellCount++;

               
                logMessage("무기 판매, 레벨: " + to_string(level));
                Sleep(2000);
            }
            else {
                cout << "판매할 무기가 없습니다." << endl;
                Sleep(1000);
            }
            break;
        case 3: // 게임 종료
            cout << "게임을 종료합니다." << endl;
            logMessage("게임 종료");
            Sleep(2000);
            exit(0);
        default:
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
            Sleep(1000);
            break;
        }
    }
    return 0;
}
