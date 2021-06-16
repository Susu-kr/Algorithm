/*
	문제1
	용량이 큰 파일을 작은 용량으로 분할해서
	작은 단위의 파일로 나누는 유틸리티 프로그램을 작성.
	사용자로부터 소스 파일을 입력받은 후
	각각 분할된 작은 파일의 바이트 값을 입력받아 해당 크기의 파일로 분할한다.

	ex) Enter file name : test.zip
		Enter file size : 1024
		-> file Test0.div
		-> file Test1.div
		-> file Test2.div
		...
		Split Done!
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

inline void eatline() { while (cin.get() != '\n') continue;}

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
	string file;
	cout << "Enter file name : ";
	cin >> file;
	eatline();
	int File_Size = fileSize(file);
	int size;
	cout << "Enter file size : ";
	cin >> size;
	eatline();
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open()) {
		int num = 0;
		while (File_Size != 0) {
			int read_size;
			if(File_Size >= size) read_size = sizeof(char) * size;
			else read_size = sizeof(char) * File_Size;

			char *buffer = new char[read_size];
			memset(buffer, 0, read_size);
			if (buffer == NULL)	error("버퍼 할당 실패");

			fin.read(buffer, read_size);
			ofstream div;
			string divname;
			for (int i = 0; i < file.length(); i++) {
				if (file[i] == '.') break;
				divname += file[i];
			}
			divname += to_string(num++) + ".div";
			div.open(divname, ios_base::out | ios_base::binary);
			if (div.is_open()) {
				cout << "-> " << divname << endl;
				div.write(buffer, read_size);
				if (div.fail()) error("분할파일 쓰기 실패");
				div.close();
			}
			else error("분할파일 생성 실패");
			delete[] buffer;
			File_Size -= read_size;
		}
		cout << ".....\nSplit Done!\n";
		fin.close();
	}
	else error("파일을 열 수 없습니다.");
	return 0;
}