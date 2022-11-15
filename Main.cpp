//Шаблон
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>



using namespace std;

double devide(double num1, double num2) {
	if (num2 == 0)
		//throw "обнаружено деление на ноль";
		//throw exception("обнаружено деление на ноль"); //объект класса exception с конструктором
		throw invalid_argument("делить на ноль нельзя"); // будет пойман exception
	return num1 / num2;
}

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
void show_arr(T arr[], const int length) {
	if (length <= 0)
		throw invalid_argument("обаружена отрицательная длинна массива");
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";

}



int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//Исключения при работе с файлами
	//string path = "file.txt";
	//ofstream out;
	//out.exceptions(ios::badbit | ios:: failbit | ios::eofbit);//разрешаем категории исключений	
	//классический метод открытия файла и проверки
	// out.open(path);
	//if (out.is_open()) {
		//cout << "Файл открыт для записи.\n";
	//}
	//else
		//cout << "Ошибка открытия файла.\n";
		// out.close();
	//через исключения проверка открытия файла
	/*try {
		out.open(path);
		cout << "Файл открыт для записи \n";
		out.close();
	}
	catch (const ios::failure& ex) {//можно exceptions но для файлов лучше const ios::failure-работает с исключениями fstream
		//cout << "Ошибка открытия файла: " << ex.what() << '\n';
		cout <<"Код ошибки: " << ex.code().value() << '\n';// метод value() выдает чило (код) из кода ex.code() кода ошибок, можно использовать в свичкейсе
	}*/
	//Классическая проверка if else
	/*cout << "Введите начало дапазона: ";
	cin >> n;
	cout << "Введите конец дапазона: ";
	cin >> m;

	//Классическая проверка if else
	if (n < m)
		cout << "Все супер!\n";
	else
		cout << "Ошибка ввода!\n";*/

	//Обработка исключений
	/*try {//попробовать
		cout << "Введите начало дапазона: ";
		cin >> n;
		cout << "Введите конец дапазона: ";
		cin >> m;
		if (n > m)
			throw 1;// бросить
		if (n == m)
			//throw 2;
			throw "Границы диапазона равны.";
		cout << "Все отлично!\n ";

	}
	catch (const int &e) {//поймать
		if(e==1)
			cout << "Начало диапазона больше конца диапазона.\n";
		//else
			//if(e==2)
				//cout << "Границы диапазона равны.\n";

	}
	catch (const char* e) { //передаем костанты со ссылкой
		cout << "Ошибка: " << e << endl;

	}*/

	//Обработка деления на ноль
	/*try {
		cout << "Введите два числа: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << devide(n, m) << '\n';
	}
	catch (const char* e) {
		cout << "Ошибка: " << e << '\n';
	}
	catch (const exception & ex) { // ловит все классы исключений
		cout << "Ошибка: " << ex.what() << '\n'; // метод what объекта ех класса exception
	}*/


	//Задача 1. Вывод массива на экран

	cout << "Задача 1.\nМассив:\n";
	const int size = 10;
	int arr[size];
	try {
		fill_arr(arr, size, 1, 11);
		show_arr(arr, -5);
	}
	catch (const exception& ex) {
		cout << "Ошибка: " << ex.what() << endl;
	}


	return 0;
}