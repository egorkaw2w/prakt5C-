#include <iostream>
#include <Windows.h>
#include <iostream>
#pragma once
using namespace std;

class BankAccaunt
{
	double cash;
private:
	int accauntNumber;
	double balance;
	double interestRate;
public:
	BankAccaunt(int a, double b) {
		accauntNumber = a;
		balance = b;
		interestRate = 0;
	}
	void deposit() {
		cout << "Сколько денег будем класть?: ";
		cin >> cash;
		balance += cash;
	}
	void withdraw() {
		cout << "Сколько снимим? \n";
		cin >> cash;
		if (cash > balance) {
			cout << "У вас недостаточно средств";
		}
		else {
			balance -= cash;
			cout << "мы сняли " << cash << " рублей, и теперь у вас: " << balance;
		}
	}
	void getbalance() {
		cout << "Ваше состояние на данный момент: " << balance;
	}
	void getInterest() {
		double result = (float)(balance * interestRate * (1.00/12.00));
		cout << "Сумма процентов, заработанных на счёте составляет: " << result;
	}
	void setInterestRate() {
		cout << "На какую ставку вы хотите поменять? \n";
		cin >> cash;
		interestRate = (double)cash;
		cout << "Ваша ставка обновлена \n";
	}
	void getAccountNumber() {
		cout << "\nНомер вашего банковского счёта: " << accauntNumber;
	}
	friend bool transfer(BankAccaunt& from, BankAccaunt& to, double amount);
};

bool transfer(BankAccaunt& from, BankAccaunt& to, double amount) {
	if (from.balance >= amount) {
		from.balance -= amount;
		to.balance += amount;
		return true;
	}
	else {
		cout << "Недостаточно средств на счету для перевода." << endl;
		return false;
	}
}

int main()
{
	SetConsoleCP(1251);
	setlocale(0, "ru");
	int accauntNumber;
	double balance;
	cout << "Введи номер вашего счёта: ";
	cin >> accauntNumber;
	cout << "Введите ваш баланс: ";
	cin >> balance;

	BankAccaunt a(accauntNumber, balance);
	while (true) {
		cout << "\n\tЭто терминал \n\t Выберите действие\n";
		cout << "1 - пополнение \t 2-узнать баланс\n3 - снятие\t4- узнать номер аккаунта\n5 - перевод средств\t6 - рассчитать ставку\n 7 - изменить ставку\t8- закрыть программу\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			a.deposit();
		}
		else if (choice == 2) {
			a.getbalance();
		}
		else if (choice == 3) {
			a.withdraw();
		}
		else if (choice == 4) {
			a.getAccountNumber();
		}
		else if (choice == 5) {
			int accauntNumber2;
			double balance2;
			cout << "Введите номер второго счёта: ";
			cin >> accauntNumber2;
			cout << "Введите баланс второго счёта: ";
			cin >> balance2;
			BankAccaunt b(accauntNumber2, balance2);

			double amount;
			cout << "Введите сумму перевода: ";
			cin >> amount;
			if (transfer(a, b, amount)) {
				cout << "Перевод успешно выполнен." << endl;
			}
			else {
				cout << "Перевод не выполнен." << endl;
			}
		}
		else if (choice == 6) {
			a.getInterest();
		}
		else if (choice == 7) {
			a.setInterestRate();
		}
		else if (choice == 8) {
			break;
		}

		else {
			cout << "такого действия нет";
		}
	}

}