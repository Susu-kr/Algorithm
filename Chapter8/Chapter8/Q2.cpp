/*
	문제2.
	암호화된 파일을 복호화(decoding) 하는 프로그램을 작성.
	사용자가 입력 파일 이름과 출력파일 이름을 입력하면
	입력 파일의 암호가 풀린 버전을 출력 파일로 저장하는 프로그램을 작성.

	ex> Input source filename : encoding.txt
		Input decoding filename : decoding.txt
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

inline void eatline() { while (cin.get() != '\n') continue; }

int32_t fileSize(string filename) {
	struct stat _stat;
	int32_t rc = stat(filename.c_str(), &_stat);
	if (rc == 0) return _stat.st_size;
	else return -1;
}


void error(string msg) {
	cout << msg << endl;
	exit(EXIT_FAILURE);
}

int main() {
	string S_File;
	cout << "Input source filename : ";
	cin >> S_File;
	eatline();
	string D_File;
	cout << "Input decoding filename : ";
	cin >> D_File;
	ofstream decode;
	decode.open(D_File, ios_base::out | ios_base::binary);
	if (decode.is_open()) {
		ifstream fin;
		fin.open(S_File, ios_base::in | ios_base::binary);
		int Size = fileSize(S_File);
		if (fin.is_open()) {
			int count = 0;
			while (count != Size) {
				char *buffer = new char[sizeof(char) + 5];
				memset(buffer, 0, sizeof(char) + 5);
				if (buffer == NULL) error("버퍼 할당 실패");
				fin.read(buffer, sizeof(char) + 5);
				decode.write(buffer, sizeof(char));
				if (decode.fail()) error("파일 쓰기 실패");
				delete[] buffer;
				count += 6;
			}
			fin.close();
		}
		else error("파일 열기 실패");
		decode.close();
	}
	else error("파일 생성 실패");
	return 0;
}