#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	default_random_engine rnd(time(0));

	uniform_int_distribution<unsigned> g(10, 50);

	vector<int> arr;

	int n, k = 0;

	cout << "Введите размерность массива эл-ов: " << endl;
	cout << "n = "; 
	cin >> n;

	for (int i = 0; i < n; i++) {

		int d = g(rnd);
	    arr.push_back(d);
		cout << arr[i] << " ";

	}

	set<int> arr2{ 1, 5, 10 , 21, 25 , 50 };

	for (int i = 0; i < n; i++)

		if (arr2.count(arr[i])) 
			k++;

	cout << "\nНайдено - " << k << " идентичных элементов." << endl;

}

	
