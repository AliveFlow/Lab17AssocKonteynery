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
	// ��������� �������: ��������� ���� �������� ���������       //
	// ��������. ���������� ���� while                            //
	//============================================================//
	int n;
	cout << "������� ���������� ��������� �������: ";
	cin >> n;
	while (n--) {
		string S = lit[c(rnd)];
		int D = d(rnd);
		pair<string, int> tpr = make_pair(S, D);
		rat.insert(tpr);
		// ��� emplace ���� ����� �� ���������:
		//rat.emplace(S, D);
	}
	//=============================2==============================//
	// �������� 3 �������������� �������� � ������� ����          //
	// ��������� ��������                                         //
	//============================================================//
	rat.emplace("d1", 10);
	rat.insert({ "d2", -5 });
	rat.insert(pair<const string, int>("d3", 6));
	//=============================3==============================//
	// �������  ��� �������� ������������� ����� ������ �         //
	// ������ ������                                              //
	//============================================================//
	string el_l, el_r;
	cout << "������� �����:\n";
	cout << "1-��: "; cin >> el_l;
	cout << "2-��: "; cin >> el_r;
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
	// ������� �������� ������ ��� ��������� � ������� ������,     //
	// ������� ����� ������� �� ������ 10. ���� ����� ��������� �� //
	// ���������� - ������� 0. ���������� equal_range,             //
	// ������������ ������ �� ���� ���������� ��������� �������    //
	// ������                                                      //
	//=============================================================//
	string tmp;
	cout << "������� ����: ";
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