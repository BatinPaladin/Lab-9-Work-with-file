#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Функция заполнения массива слов
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

//Функция разделение строки на слова
void SplitRow(string row, string*& array, int lenght) {
	array = new string[lenght];
	FillWordsArray(array, row, lenght);
};

//Функция подсчёта кол-ва слов в строке
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

//Функция проверки на наличие  одинаковых слов
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

//Функция подсчета кол-ва гласных букв в строке
void NumberOfVowels(string row) { 
	int count=0;
	string Vowels = {"АЕЁИОУЫЭЮЯаеёиоуыэюя"};
	for (int i = 0; i < size(row); i++) {
		for (int j = 0; j < size(Vowels); j++) {
			if (row[i] == Vowels[j]) {
				count++;
			}
		}
	}
	if (count==0){
		cout << "\nПервая строкa из F2.txt [" << row << "] не содержит гласных букв.\n";
	}
	else {
		cout << "\nПервая строкa из F2.txt [" << row << "] содержит " << count << " гласные буквы.\n";
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
			cout << "Ошибка! Не удалось открыть файл F2.txt.";
		}
		file.close();
	}
	else {
		cout << "Ошибка! Не удалось открыть файл F1.txt.";
	}
	ifile.close();
	system("pause");
	return 0;
}