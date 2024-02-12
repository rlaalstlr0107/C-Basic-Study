#include <iostream>
#include <cstring>

using namespace std;

// 구조체는 관련이 있는 변수들을 구조적으로 묶어서 함꼐 사용을 할 때
struct MyStruct
{
    int first;
    int second;

    int Sum()
    {
        return first + second;
    }
};

int main()
{
    MyStruct a;
    a.first = 123;
    a.second = 456;

    // 경우에 따라서는 멤버 변수들의 합보더 더 큰 사이즈가 나올 수 있다,
    // 구조체 안에 들어있는 멤버 사이즈의 합보다 크다라고 이해
    cout << sizeof(a) << "\n";
    cout << a.Sum() << '\n';

    // 구조체 멤버변수를 포인터로 접근하기 위해서는 -> 화살표를 사용해서 접근할 수 있다.
    MyStruct * ptr_a = &a;

    // 포인터로 접근해서 값을 바꿔버림
    ptr_a->first = -6;
    
    cout << ptr_a->first << " " << ptr_a->second << " " << ptr_a->Sum() << '\n';

    // 배열도 가능하다.
    MyStruct pairs[10];

    for (int i = 0; i < 10; i++)
    {
        // 주의!! 배열일 경우에는 인덱싱을 한 다음 멤버 변수에 접근을 해야 한다.
        // pairs->first = i;
        // pairs->second = i * 10;

        pairs[i].first = i;
        pairs[i].second = i * 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << pairs[i].Sum() << '\n';
    }
    
    return 0;
}