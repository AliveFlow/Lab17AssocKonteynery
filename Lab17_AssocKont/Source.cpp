#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include "pch.h"

using namespace std;

int main() {
	multimap<string, int> rat;
	vector<string> lit{ "a1", "a2", "a3",
						"b1", "b2", "b3",
						"c1", "c2", "c3" };
	default_random_engine rnd(time(0));
	uniform_int_distribution<int> d(-10, 20);
	uniform_int_distribution<int> c(0, 8);
	//=============================1==============================//
	// Заполняем словарь: случайный ключ получает случайное       //
	// значение. Используем цикл while                            //
	//============================================================//
	int n;
	cout << "Введите количество элементов словаря: ";
	cin >> n;
	while (n--) {
		string S = lit[c(rnd)];
		int D = d(rnd);
		pair<string, int> tpr = make_pair(S, D);
		rat.insert(tpr);
		// Для emplace пару можно не создавать:
		//rat.emplace(S, D);
	}
	//=============================2==============================//
	// Вставить 3 дополнительных элемента с помощью трех          //
	// различных операций                                         //
	//============================================================//
	rat.emplace("d1", 10);
	rat.insert({ "d2", -5 });
	rat.insert(pair<const string, int>("d3", 6));
	//=============================3==============================//
	// Вывести  все элементы расположенные между первым и         //
	// вторым ключом                                              //
	//============================================================//
	string el_l, el_r;
	cout << "Введите ключи:\n";
	cout << "1-ый: "; cin >> el_l;
	cout << "2-ой: "; cin >> el_r;
	auto fst = rat.lower_bound(el_l);
	auto lst = rat.upper_bound(el_r);
	while (fst != lst) {
		cout << fst->first
			<< " => "
			<< fst->second
			<< endl;
		fst++;
	}
	//==============================4==============================//
	// Вывести значения только тех элементов с искомым ключом,     //
	// которые имеют рейтинг не меньше 10. Если таких элементов не //
	// существует - вывести 0. Используем equal_range,             //
	// возвращающую ссылку на пару итераторов диапазона искомых    //
	// ключей                                                      //
	//=============================================================//
	string tmp;
	cout << "Введите ключ: ";
	cin >> tmp;
	auto first = rat.equal_range(tmp).first;
	auto last = rat.equal_range(tmp).second;
	if (first == last)
		cout << 0 << endl;
	else
		while (first != last) {
			auto r = first->second;
			if (r >= 10)
				cout << r << " ";
			first++;
		}
	return 0;
}