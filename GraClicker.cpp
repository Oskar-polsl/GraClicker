#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

using namespace std;

typedef unsigned long long int u64;
u64 cash = 50;
u64 cash_per_second = 0;
time_t cash_added = time(NULL);

void clear() {
	system("cls");
}

void add_cash() {
	time_t current = time(NULL);
	cash += cash_per_second * (current - cash_added);
	cash_added = current;
}

struct {
	string name;
	u64 cost;
	u64 eff;
} 
units[] = {
	{"lvl 1 crook", 25, 1},
	{"baby Yoda", 250, 12},
	{"Shrek", 1000, 50},
	{"Boomer", 1950, 95},
	{"Son Goku", 9001, 400},
	{"Joker", 30000, 1500},
	{"Geralt", 100000, 5000},
	{"Naruto", 800000, 45000},
	{"Andrzej Duda", 3000000, 200000},
	{"Ricardo Milos", 21374200, 21374200},
};
int units_len = 10;

void shop() {
	clear();
	add_cash();

	int licznik1{}, licznik2{}, licznik3{}, licznik4{}, licznik5{}, licznik6{}, licznik7{}, licznik8{}, licznik9{}, licznik10{};
	int unit;

	cout << "Sklep" << endl;
	cout << endl;
	for (int i = 0; i < units_len; i++) {
		cout.fill(' ');
		cout.width(2);
		cout << i + 1 << ". ";
		cout.fill(' ');
		cout.width(15);
		cout << units[i].name;
		cout.fill(' ');
		cout.width(10);
		cout << units[i].cost << " Yang";
		cout.fill(' ');
		cout.width(10);
		cout << units[i].eff << " YPS" << endl;
	}
	cout << endl;
	cout << "Wpisz 'q' aby wróciæ do menu g³ównego." << endl;
	cout << "Wybierz jednostkê: ";
	
	cin >> unit;

	if (cin.fail()) {
		cin.clear();
		return;
	}// czy mozna kupic jednostke units[unit -1]
	if (unit == 0 || unit > units_len) return;
	if (cash < units[unit - 1].cost) return;
	//kupiles jednostke units[unit - 1];
	
	else if (unit == 1)licznik1++;
	else if (unit == 2)licznik2++;
	else if (unit == 3)licznik3++;
	else if (unit == 4)licznik4++;
	else if (unit == 5)licznik5++;
	else if (unit == 6)licznik6++;
	else if (unit == 7)licznik7++;
	else if (unit == 8)licznik8++;
	else if (unit == 9)licznik9++;
	else if (unit == 10)licznik10++;
	cout << licznik1;
	cash -= units[unit - 1].cost;
	cash_per_second += units[unit - 1].eff;
	units[unit - 1].cost = units[unit - 1].cost * 11 / 10;
}

int main() {
	setlocale(LC_CTYPE, "Polish");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

	while (true) {
		clear();
		add_cash();

		cout << "Twoje œrodki: " << cash << " Yang" << endl;
		cout << "Œrodki na sekundê: " << cash_per_second << " YPS" << endl;
		cout << endl;
		cout << "1. Odœwie¿" << endl;
		cout << "2. Kup jednostkê" << endl;
		cout << "3. Wyjœcie" << endl;
		cout << endl << endl;
		cout << "Wybierz akcjê: ";
		string action;
		cin >> action;

		// 3. Wykonaj akcjê
		if (action.length() == 0) {
			return 0;
		}
		else if (action.length() == 1 && action[0] == '2') {
			shop();
		}
		else if (action.length() == 1 && action[0] == '3') {
			return 0;
		}
	}
}
