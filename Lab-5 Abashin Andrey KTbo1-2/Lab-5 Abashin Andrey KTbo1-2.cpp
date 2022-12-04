/******************************************************************************
Абашин Андрей Андреевич
КТбо1-2
Лабораторная работа №5 «Структуры»
Вариант № 1
Задание: Написать программу, которая записывает с клавиатуры в файл структуру
согласно выданному варианту задания. В качестве разделителя полей структуры
использовать символ табуляции. В программе реализовать:
а)дополнение существующего массива структур новыми структурами;
б)поиск структуры с заданным значением выбранного элемента;
в)вывод на экран содержимого массива структур;
г)упорядочение массива структур по заданному полю (элементу), например
государство по численности.

«Человек»: фамилия, имя,пол, рост, вес, дата рождения (число, месяц, год),
номер телефона, домашний адрес (индекс, страна, область, город, улица, дом, квартира).

*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct human
{
	char surname[20];
	char name[20];
	char gender[10];
	int height;
	int weight;
	struct {
		int day;
		int month;
		int year;
	} burthday;
	char number[20];
	struct {
		int index;
		char country[20];
		char oblast[30];
		char city[20];
		char street[20];
		int home;
		int kv;
	} address;
};

void SortHeight(human** q, int k) // функция сортировки пузырьком
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k - i - 1; j++)
			if (q[j]->height > q[j + 1]->height)
			{
				human* temp = q[j];
				q[j] = q[j + 1];
				q[j + 1] = temp;
			}
};

void Output(human* h, int i) // функция вывода в консоль структуры
{
	cout << endl;
	cout << i + 1 << " Человек: ";
	cout << h[i].surname << " -- " << h[i].name << " -- "
		<< h[i].gender << " -- " << h[i].height << " -- "
		<< h[i].weight << " -- " << h[i].burthday.day << " -- "
		<< h[i].burthday.month << " -- " << h[i].burthday.year << " -- "
		<< h[i].number << " -- " << h[i].address.index << " -- "
		<< h[i].address.country << " -- " << h[i].address.oblast << " -- "
		<< h[i].address.city << " -- " << h[i].address.street << " -- "
		<< h[i].address.home << " -- " << h[i].address.kv;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); //чтобы в файле записывались русские буквы
	setlocale(LC_ALL, "ru");

	const int n = 15; //максимальное количество структур
	char otvet1, otvet2, otvet3, otvet4;
	int k = 0, poisk;//переменная для счетчика структур

	ofstream file("human.txt"); //создание файла

	human* h = new human[n]; //указатель на массив структур


	//..........    ЗАПОЛНЕНИЕ СТРУКТУРЫ С КЛАВИАТУРЫ В ФАЙЛ    ..........


	for (int i = 0; i < n; i++) //цикл заполнения структур
	{
		cout << endl;
		cout << "Введите фамилию " << i + 1 << " человека: ";
		cin >> h[i].surname;
		file << h[i].surname << "	";
		cout << "Введите имя " << i + 1 << " человека: ";
		cin >> h[i].name;
		file << h[i].name << "	";
		cout << "Введите пол " << i + 1 << " человека: ";
		cin >> h[i].gender;
		file << h[i].gender << "	";
		cout << "Введите рост " << i + 1 << " человека: ";
		cin >> h[i].height;
		file << h[i].height << "	";
		cout << "Введите вес " << i + 1 << " человека: ";
		cin >> h[i].weight;
		file << h[i].weight << "	";
		cout << "Введите число(1-31), когда родился " << i + 1 << " человек: ";
		cin >> h[i].burthday.day;
		file << h[i].burthday.day << "	";
		cout << "Введите месяц(1-12), когда родился " << i + 1 << " человек: ";
		cin >> h[i].burthday.month;
		file << h[i].burthday.month << "	";
		cout << "Введите год(1-2022), когда родился " << i + 1 << " человек: ";
		cin >> h[i].burthday.year;
		file << h[i].burthday.year << "	";
		cout << "Введите номер телефона(89005557700) " << i + 1 << " человека: ";
		cin >> h[i].number;
		file << h[i].number << "	";
		cout << "Введите индекс(123456) " << i + 1 << " человека: ";
		cin >> h[i].address.index;
		file << h[i].address.index << "	";
		cout << "Введите страну(Xxxxxx) " << i + 1 << " человека: ";
		cin >> h[i].address.country;
		file << h[i].address.country << "	";
		cout << "Введите область(Хххххх) " << i + 1 << " человека: ";
		cin >> h[i].address.oblast;
		file << h[i].address.oblast << "	";
		cout << "Введите город(Хххххх) " << i + 1 << " человека: ";
		cin >> h[i].address.city;
		file << h[i].address.city << "	";
		cout << "Введите улицу(Хххххх) " << i + 1 << " человека: ";
		cin >> h[i].address.street;
		file << h[i].address.street << "	";
		cout << "Введите номер дома(99) " << i + 1 << " человека: ";
		cin >> h[i].address.home;
		file << h[i].address.home << "	";
		cout << "Введите номер квартиры(99) " << i + 1 << " человека: ";
		cin >> h[i].address.kv;
		file << h[i].address.kv;

		k++;
		cout << endl << "##########################################################################" << endl;
		cout << endl << "Чтобы прекратить заполнение структур, введите 'N'. Чтобы продолжить, любое другое значение." << endl;
		cout << endl << "##########################################################################" << endl;
		cin >> otvet1;
		if ((otvet1 == 'N') || (otvet1 == 'n')) break;

		file << (char)13; //после ввода структуры, перевод на новую строку в файле (ENTER)
	}
	file.close();

	human** q = new human * [n]; // массив указателей
	for (int i = 0; i < k; i++)// цикл заполнения массива указателей
		q[i] = &h[i];


	//..........   ПОИСК СТРУКТУРЫ С ЗАДАННЫМ ЗНАЧЕНИЕМ    ..........


	cout << endl << endl << "Если вы хотите выполнить поиск структуры с заданным зачением, ВВЕДИТЕ 'Y'" << endl;
	cout << "Чтобы пропустить, введите любое значение, КРОМЕ 'Y' ";
	cin >> otvet2;
	if ((otvet2 == 'Y') || (otvet2 == 'y'))
	{
		cout << endl << "Введите значение, соответствующее нужному полю" << endl;
		cout << "Поиск по фамилии - 1" << endl;
		cout << "Поиск по имени - 2" << endl;
		cout << "Поиск по полу - 3" << endl;
		cout << "Поиск по росту - 4" << endl;
		cout << "Поиск по весу - 5" << endl;
		cout << "Поиск по дню рождения - 6" << endl;
		cout << "Поиск по месяцу рождения - 7" << endl;
		cout << "Поиск по году рождения - 8" << endl;
		cout << "Поиск по номеру телефона - 9" << endl;
		cout << "Поиск по индексу - 10" << endl;
		cout << "Поиск по стране - 11" << endl;
		cout << "Поиск по области - 12" << endl;
		cout << "Поиск по городу - 13" << endl;
		cout << "Поиск по улице - 14" << endl;
		cout << "Поиск по номеру дома - 15" << endl;
		cout << "Поиск по номеру квартиры - 16" << endl;

		cout << "Введите значение: ";
		cin >> poisk;

		if (poisk == 1)
		{
			string znachenie;
			cout << endl << "Введите фамилию: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].surname)
					Output(h, i);
			}
		}
		if (poisk == 2)
		{
			string znachenie;
			cout << "Введите имя: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].name)
					Output(h, i);
			}
		}
		if (poisk == 3)
		{
			string znachenie;
			cout << "Введите пол: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].gender)
					Output(h, i);
			}
		}
		if (poisk == 4)
		{
			int znachenie;
			cout << "Введите рост: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].height)
					Output(h, i);
			}
		}
		if (poisk == 5)
		{
			int znachenie;
			cout << "Введите вес: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].weight)
					Output(h, i);
			}
		}
		if (poisk == 6)
		{
			int znachenie;
			cout << "Введите день рождения: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].burthday.day)
					Output(h, i);
			}
		}
		if (poisk == 7)
		{
			int znachenie;
			cout << "Введите месяц рождения: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].burthday.month)
					Output(h, i);
			}
		}
		if (poisk == 8)
		{
			int znachenie;
			cout << "Введите год рождения: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].burthday.year)
					Output(h, i);
			}
		}
		if (poisk == 9)
		{
			string znachenie;
			cout << "Введите номер телефона: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].number)
					Output(h, i);
			}
		}
		if (poisk == 10)
		{
			int znachenie;
			cout << "Введите индекс: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].address.index)
					Output(h, i);
			}
		}
		if (poisk == 11)
		{
			string znachenie;
			cout << "Введите страну: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].address.country)
					Output(h, i);
			}
		}
		if (poisk == 12)
		{
			string znachenie;
			cout << "Введите область: ";
			cin.sync();
			getline(cin, znachenie);
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].address.oblast)
					Output(h, i);
			}
		}
		if (poisk == 13)
		{
			string znachenie;
			cout << "Введите город: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].address.city)
					Output(h, i);
			}
		}
		if (poisk == 14)
		{
			string znachenie;
			cout << "Введите улицу: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].address.street)
					Output(h, i);
			}
		}
		if (poisk == 15)
		{
			int znachenie;
			cout << "Введите номер дома: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].address.home)
					Output(h, i);
			}
		}
		if (poisk == 16)
		{
			int znachenie;
			cout << "Введите номер квартиры: ";
			cin >> znachenie;
			for (int i = 0; i < k; i++)
			{
				if (znachenie == h[i].address.kv)
					Output(h, i);
			}
		}
	}


	//..........   ВЫВОД НА ЭКРАН СОДЕРЖИМОГО МАССИВА СТРУКТУР    ..........


	cout << endl << endl << "Если вы хотите вывести на экран содержимое массива структур, ВВЕДИТЕ 'Y'";
	cout << endl << "Чтобы пропустить, введите любое значение, КРОМЕ 'Y' ";
	cin >> otvet3;
	if ((otvet3 == 'Y') || (otvet3 == 'y'))
	{
		for (int i = 0; i < k; i++)
		{
			Output(h, i);
		}
	}

	cout << "\n" << "\n";


	//..........    СОРТИРОВКА СТРУКТУРЫ ПО РОСТУ    ..........


	cout << "Если вы хотите отсортировать структуры по росту и вывести результат на экран, ВВЕДИТЕ 'Y'";
	cout << "Чтобы пропустить, введите любое значение, КРОМЕ 'Y' " << endl;
	cin >> otvet4;
	if ((otvet4 == 'Y') || (otvet4 == 'y'))
	{
		SortHeight(q, k);
		for (int i = 0; i < k; i++)
		{
			cout << i + 1 << " Человек: ";
			cout << q[i]->surname << "	" << q[i]->name << "	"
				<< q[i]->gender << "	" << q[i]->height << "	"
				<< q[i]->weight << "	" << q[i]->burthday.day << "	"
				<< q[i]->burthday.month << "	" << q[i]->burthday.year << "	"
				<< q[i]->number << "	" << q[i]->address.index << "	"
				<< q[i]->address.country << "	" << q[i]->address.oblast << "	"
				<< q[i]->address.city << "	" << q[i]->address.street << "	"
				<< q[i]->address.home << "	" << q[i]->address.kv;
			cout << "\n";
		};
	}
	return 0;
}