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


	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// 콘솔 입출력


	char user_input[100];

	/*

	cout << "원하는 문장을 입력해주세요." << endl;
	cout << "입력: ";

	//cin >> user_input; // 중간에 빈칸이 있으면 더이상 받아오지 않는다. 그럴 땐 아래와 같이
	cin.getline(user_input, sizeof(user_input));

	cout << "메아리: " << user_input << endl;
	*/


	/*
	int number = -1;

	// cin >> user_input;
	// cin.getline(user_input, sizeof(user_input));
	cin.ignore(100, '\n');

	cin >> number;

	cout << user_input << " " << number << endl;

	 // 참고 : cin.ignore(numeric_limits<streamsize>::max(), '\n')
	 */

	 ////////////////////////////////////////////////////////////////////////////////////////////////////////////

	 // 분기 처리

	int number;

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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	/*
	while (i < 10)
	{
		cout << i << " ";
		i++;
	}
	cout << endl;
	*/

	while (true)
	{
		cout << i << " ";
		i++;

		if (i == 10) break;
	}

	return 0;
}