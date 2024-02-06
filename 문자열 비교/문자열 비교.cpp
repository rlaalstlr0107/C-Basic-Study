#include <iostream>

using namespace std;

const int kMaxStr = 100;

// 문자열을 매개변수로 문자열이 같은 지 판별하는 함수
bool IsEqual(const char *str1, const char *str2)
{
    for (int i = 0; i < kMaxStr; i++) {

        // 문자열 종료 조건을 안 넣어주었으면 안 끝남, 디버깅을 해주면 되는데..
        cout << int(str1[i]) << " / " << int(str2[i]) << "\n";

        if (str1[i] != str2[i])
            return false;

        if (str1[i] == '\0')
            return true;
    }

    return true;
}

int main()
{
    const char str1[kMaxStr] = "stop";

    while (1) {
        char str2[kMaxStr];
        cin >> str2;

        if (IsEqual(str1, str2)) {
            cout << "종료합니다." << '\n';
            break;
        }
        else {
            cout << "계속합니다." << '\n';
        }
    }

    return 0;
}

