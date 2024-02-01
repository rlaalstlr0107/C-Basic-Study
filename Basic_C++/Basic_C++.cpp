#include <iostream>
#include <random>
#include <bits/stdc++.h>

using namespace std;


const int kMaxStr = 100; // 전역 변수

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
	char character = 'a';
	char str[] = "Hello, World!";

	cout << character << " " << sizeof(character) << endl;

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

	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

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


	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	// 콘솔 입출력


	char user_input[100];

	cout << "원하는 문장을 입력해주세요." << endl;
	cout << "입력: ";

	//cin >> user_input; // 중간에 빈칸이 있으면 더이상 받아오지 않는다. 그럴 땐 아래와 같이
	cin.getline(user_input, sizeof(user_input));

	cout << "메아리: " << user_input << endl;


	int number = -1;

	// cin >> user_input;
	// cin.getline(user_input, sizeof(user_input));
	cin.ignore(100, '\n');

	cin >> number;

	cout << user_input << " " << number << endl;

	// 참고 : cin.ignore(numeric_limits<streamsize>::max(), '\n')


	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	// 분기 처리

	number = 0;

	cin >> number;

	if (number % 2 == 0)
		cout << "짝수 입니다. \n";  // 이거는 cout << "짝수 입니다." << endl 과 같다.
	else
		cout << "홀수 입니다. \n";


	// 조건 연산자 (삼항 연산자)
	cout << (number % 2 == 0 ? "짝수입니다." : "홀수입니다.") << endl;


	// switch case
	switch (number)
	{
	case 0:
		cout << "정수 0입니다." << endl;
		break;

	case 1:
		cout << "정수 1입니다." << endl;
		break;

	default:
		cout << "그 외의 숫자입니다." << endl;
		break;
	}

	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	// 반복문

	for (int i = 0; i < 10; i++) {
		cout << i << " ";
	}
	cout << endl;


	int my_array[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	for (int i = 0; i < sizeof(my_array) / sizeof(int); i++) {
		cout << my_array[i] << " ";
	}
	cout << endl;

	// 문자열 출력 
	char my_string[] = "Hello\0, World!";

	// null character를 만나면 멈추게 하는 방법 1
	for (int i = 0; i < sizeof(my_string); i++) {
		if (my_string[i] == '\0')
			break;

		cout << my_string[i];
	}
	cout << endl;

	// null character를 만나면 멈추게 하는 방법 2
	for (int i = 0; my_string[i] != '\0'; i++) {

		cout << my_string[i];

	}
	cout << endl;

	i = 0;

	// while 문
	/*while (i < 10)
	{
		cout << i << " ";
		i++;
	}
	cout << endl;*/


	while (true)
	{
		cout << i << " ";
		i++;

		if (i == 10) break;
	}


	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	// 숫자 맞추기 게임

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 99);

	number = distrib(gen);
	int guess;

	while (1)
	{
		cout << "입력 : ";
		cin >> guess;

		if (guess > number) cout << "너무 커요 \n";
		else if (guess < number) cout << "너무 작아요 \n";
		else
		{
			cout << "정답!!";
			break;
		}
	}


	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

	// 포인터 (어려움)

	int a = 123;

	// address of 주소 연산자 & ampersand
	cout << a << " " << &a << endl;

	int* b = &a; // b에 a의 주소를 대입

	// deference operator (역참조 연산자)
	cout << b << " " << *b << endl;

	*b = 678; // b가 가르키고 있는 주소에 저장을 하는 행위라고 생각..
	// 포인터 변수 b를 이용해 변수 a가 사용하는 메모리의 값을 바꾼 것.

	cout << a << " " << b << " " << *b << endl;




	// 1. 포인터 자체의 주소 크기와 자료형의 크기 (주소의 크기는 항상 동일하다.)
	double* c = nullptr; // 아무 주소도 가리키고 있지 않다는 의미의 초기화, 0으로도 많이 사용한다.

	// 자료형의 크기는 다를 수 있지만, 주소는 크기가 같다!! (집이 크다고 주소가 길지는 않잖아..)
	cout << sizeof(int) << " " << sizeof(double) << endl;			// 4 8
	cout << sizeof(int*) << " " << sizeof(double*) << endl;		// 8 8
	cout << sizeof(b) << " " << sizeof(c) << endl;					// 8 8




	// 2. 포인터 연산과 배열

	// size_t 안내 (여기서는 주소를 10진수로 변환하기 위한 용도이다.) 
	cout << sizeof(size_t) << endl; // 8
	cout << size_t(b) << " " << size_t(b + 1) << " " << size_t(b + 2) << endl;
	cout << size_t(c) << " " << size_t(c + 1) << " " << size_t(c + 2) << endl;
	// 포인터가 가지고 있는 주소에다가 1을 더한다는 의미는 포인터의 원래의 자료형 만큼 더해준다.
	// 배열처럼 사용하는 경우가 많다.




	char my_str[] = { 'h', 'e', 'l', 'l', 'o' };

	char* ptr = my_str; // 배열 자체가 포인터이다.

	cout << *(ptr + 4) << endl;
	cout << *(my_str + 4) << endl;
	cout << ptr[4] << endl;

	// 즉, 배열이라는 것 자체가 메모리 공간이 쭉 나열이 되어있고, 인덱싱을 통해 하나만 가져와서 사용하는 것


	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;


	// 함수

	cout << Add(1, 2) << endl;

	int sum;
	Add(4, 5, &sum); // sum의 주소를 넣는다.

	cout << sum << endl;


	cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;


	// 문자열 비교


	const char str1[kMaxStr] = "stop";

	while (1)
	{
		char str2[kMaxStr];
		cin >> str2;

		if (IsEqual(str1, str2))
		{
			cout << "종료합니다." << endl;
			break;
		}

		else
		{
			cout << "계속합니다." << endl;
		}

	}

	return 0;
}


// 함수는 선언과 정의가 분리가 가능해서 맨 위에서 선언을 하고, 아래에서 실제 구현을 하는 형식으로 깔끔하게 짤 수 있다.
int Add(int a, int b);

int Add(int a, int b)
{
	return a + b;
}


// c언어 계열에서 매개변수에 포인터가 들어가있는 경우에는 대부분 출력을 여기에 저장해서 보내려는게 아닐까 생각, 추측!
void Add(int a, int b, int* c)
{
	*c = a + b; // c라는 주소를 찾아가서 그 값을 더해준다.
}

// 문자열을 매개변수로 넣기
// 여기서는 모든 문자열 배열의 길이가 동일하다고 가정한다.
bool IsEqual(const char str1[], const char str2[])
{
	// 모든 한 글자 한 글자를 돌면서 같은지 다른지

	for (int i = 0; i < kMaxStr; i++) {

		if (str1[i] != str2[i])
			return false;

		// 문자열의 종료 조건
		if (str1[i] == '\0')
			return true;
	}

	return true;
}