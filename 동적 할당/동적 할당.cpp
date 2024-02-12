#include <iostream>

using namespace std;

const int kMaxStr = 100;

int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    // 문자열 복사
    char str1[] = "Hello World!";
    char str2[kMaxStr];

    // str2 = str1;
    // str1 자체가 포인터이기 때문에 주소를 복사해야 할지, 한 글자 한 글자를 복사를 해야할 지 모름
    // C++ 언어에서는 프로그래머의 의도를 이해할 수 없다, 편의기능보다는 효율성을 중시한 언어

    // 메모리 카피
    memcpy(str2, str1, Min(sizeof(str1), sizeof(str2)));
    cout << str2 << '\n';


    // 동적 할당은 메모리를 직접 조정하는 방식
    // 주의 : 동적할당 메모리는 변수 사이즈가 포인터 사이즈이다.
    char * dynamic_array = new char[kMaxStr];

    // str1, str2는 정적배열로 Stack 영역에 있고, dynamic_array는 동적배열로 Heap 영역에 있다.
    // 따라서 주소값을 10진수로 바뀐 값을 봤을 때, 차이가 많이 나는 것을 확인할 수 있다.
    memcpy(dynamic_array, str1, Min(sizeof(str1), kMaxStr));
    cout << str1 << " " << str2 << " " << dynamic_array << "\n";
    cout << size_t(str1) << " " << size_t(str2) << " " << size_t(dynamic_array) << "\n";

    // 동적배열은 꼭 메모리 해제를 해주어야 한다. 메모리 누수가 생길 수 있다.
    delete[] dynamic_array;

    // 지우지 않고 재할당을 하는 경우 새로운 메모리를 사용하고, 데이터를 잃어버린다.
    // dynamic_array = new char[kMaxStr];
    // cout << size_t(dynamic_array) << "\n";
    // delete[] dynamic_array;

    return 0;
}
