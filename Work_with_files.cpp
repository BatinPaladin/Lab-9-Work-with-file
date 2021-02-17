#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//������� ���������� ������� ����
void FillWordsArray(string*& array, string row, int lenght) {
	int j = 0;
	for (int i = 0; i < lenght; i++) {
		while (row[j] == ' ') {
			j++;
		}
		while ((row [j] != ' ') && (row[j] != '\0') && (row[j] != '\n')) {
			array[i] += row[j];
			j++;
		}
	}
};

//������� ���������� ������ �� �����
void SplitRow(string row, string*& array, int lenght) {
	array = new string[lenght];
	FillWordsArray(array, row, lenght);
};

//������� �������� ���-�� ���� � ������
int WordsCount(string row) {
	bool flag = false;
	int i = 0, count = 0;
	while (row[i] != '\0' && row[i] != '\n') {
		if (row[i] != ' ' && flag == false) {
			flag = true;
			count++;
		}
		else {
			if (row[i] == ' ') {
				flag = false;
			}
		}
		i++;
	}
	return count;
};

//������� �������� �� �������  ���������� ����
bool HasDoubles(string*& array, int lenght) {
	for (int i = 0; i < lenght; i++) {
		for (int j = i + 1; j < lenght; j++) {
			if (array[i] == array[j]) {
				return true;
			}
		}
	}
	return false;
};

//������� �������� ���-�� ������� ���� � ������
void NumberOfVowels(string row) { 
	int count=0;
	string Vowels = {"�Ũ����������������"};
	for (int i = 0; i < size(row); i++) {
		for (int j = 0; j < size(Vowels); j++) {
			if (row[i] == Vowels[j]) {
				count++;
			}
		}
	}
	if (count==0){
		cout << "\n������ �����a �� F2.txt [" << row << "] �� �������� ������� ����.\n";
	}
	else {
		cout << "\n������ �����a �� F2.txt [" << row << "] �������� " << count << " ������� �����.\n";
	}
};

int main()
{
	system("chcp 1251");
	ifstream ifile("F1.txt");
	if (ifile.is_open()) {
		ofstream ofile("F2.txt");
		while (!ifile.eof()){
			string row;
			string* WordsArray; 
			getline(ifile, row);
			int NumbersOfWords = WordsCount(row);
			SplitRow(row, WordsArray, NumbersOfWords);
			if (HasDoubles(WordsArray, NumbersOfWords) == false) {
				ofile << row << '\n';
			}
		}
		ofile.close();
		ifstream file("F2.txt");
		if (file.is_open()) {
			string row;
			getline(file, row);
			NumberOfVowels(row);
		}
		else {
			cout << "������! �� ������� ������� ���� F2.txt.";
		}
		file.close();
	}
	else {
		cout << "������! �� ������� ������� ���� F1.txt.";
	}
	ifile.close();
	system("pause");
	return 0;
}