/*
	문제2
	사용자로부터 분할된 소스파일의 개수, 소스 파일의 이름,
	목적 파일의 이름을 입력받아 새로운 하나의 파일로 조합하는 프로그램을 작성
	ex) Enter file number : 2
		Enter source filename1 : Test0.div
		Enter source filename2 : Test1.div
		Enter Target filename : Temp.zip
		.....
		Combine Done!
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
	int count;
	cout << "Enter file number : ";
	cin >> count;
	eatline();

	vector<string> file;
	for (int i = 0; i < count; i++) {
		string name;
		cout << "Enter file name : ";
		cin >> name;
		file.push_back(name);
		eatline();
	}
	int i = 0;
	ofstream div;
	string divname;
	cout << "Enter target file name : ";
	cin >> divname;
	div.open(divname, ios_base::out | ios_base::binary);
	if (div.is_open()) {
		while (i != count) {
			ifstream fin;
			fin.open(file[i], ios_base::in | ios_base::binary);
			if (fin.is_open()) {
				int Read_Size = sizeof(char) * fileSize(file[i]);
				char * buffer = new char[Read_Size];
				memset(buffer, 0, Read_Size);
				if (buffer == NULL) error("버퍼 할당 실패");

				fin.read(buffer, Read_Size);
				div.write(buffer, Read_Size);
				if (div.fail()) error("파일 쓰기 실패");
				delete[] buffer;
			}
			else error("파일 열기 실패");
			i++;
		}
		cout << ".....\nCombine Done!\n";
		div.close();
	}
	else error("파일 생성 실패");
	return 0;
}