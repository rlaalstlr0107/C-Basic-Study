#include <iostream>

using namespace std;

int main()
{
    // 내부적으로 메모리를 이미 가지고 있다.
    int i;  // 변수를 정의
    i = 123;    // 변수에 값을 지정
                // python의 경우에는 값이 아닌 객체의 레퍼런스로 따라가서 그 값을 들고 와야한다.

    // sizeof 소개
    cout << i << " " << sizeof(i) << endl;

    float f = 123.456f; // 4byte
    double d = 123.456; // 8byte

    cout << f << " " << sizeof(f) << endl;
    cout << d << " " << sizeof(d) << endl;

    // C++는 글자 하나와 문자열을 구분을 한다. -> 문자 여러 개가 나열이 되어있는 배열로 사용을 한다.
    char c = 'a';
    char str[] = "Hello, World!";

    cout << c << " " << sizeof(c) << endl;

    // 형변환
    i = 987.654; // double을 int에 강제로 저장한다.
    
    f = 567.89; // 이 것도 형변환이다.


    // 기본 연산자
    i += 100;
    i++;

    // boolean
    bool is_good = true;
    is_good = false;

    cout << is_good << endl; // 0

    cout << boolalpha << true << endl;      // true
    cout << is_good << endl;                // false
    cout << noboolalpha << true << endl;    // 1

    cout << (1 > 3) << endl;


    // 영역 (scope) : {} 안의 i 값을 변경해가면서 확인하기

    i = 123; // 더 넓은 영역
    
    {
        int i = 345;
        cout << i << endl;
    }

    cout << i << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // 배열

    int arr[3] = { 1, 2, 3 };

    cout << arr[0] << " "
        << arr[1] << " "
        << arr[2] << endl;

    // 인덱식으로 하나짜리 변수처럼
    arr[1] = 5;

    cout << arr[0] << " "
        << arr[1] << " "
        << arr[2] << endl;

    // 문자열은 기본적으로 문자의 배열

    char name[14] = "Hello, World!"; // 문자열의 크기를 13으로 했을 때 에러가 발생함을 확인!!
                                     // C 언어 계열은 맨 마지막에 문자열이 끝났다!라는 뜻의 Null character라는 것을 추가하기 때문!

    cout << name << " " << sizeof(name) << endl;

    name[0] = 'A';
    name[1] = 'B';
    name[2] = 'C';

    cout << name << endl;

    name[2] = '\0'; // null character로 바꾸면? -> cout 자체가 한 글자 한 글자 보여주다가 null character를 만나면 멈추게 되어있기 때문

    cout << name << endl;

    return 0;
}