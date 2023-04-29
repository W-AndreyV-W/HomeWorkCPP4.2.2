//	В стоке 47 синтактическая ошибка (тип данных элементов,  
//	сохраняемых в векторе), 
//	std::vector<std::function<void(double)>> functions
//	{ sin_print, cos_print };
// 
//	В стоке 43 семантическая ошибка (неправильный тип 
//	параметра функции, из чего происходить не явное приведение 
//	типа переменной и ошибка в вычислении косинуса), 
//	std::function<void(double)> cos_print = [](double radian) {
//
//	В стоке 31 ошибка линковки (не определен параметр функции)
//	std::for_each(array_angle.begin(), array_angle.end(), 
//	[&](int tmp) {
//	строку 26 удалить.


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int tmp = 0;
	std::vector <double> array_angle {30, 60, 90};
	std::vector<double>angles;

	std::cout << "[Входные данные]: ";
	std::for_each(array_angle.begin(), array_angle.end(), [&]() {
		angles.push_back(tmp * 3.1415926 / 180);
		std::cout << tmp << " * 3.1415926 / 180, ";
		}
	);

	std::cout << std::endl;

	std::function<void(double)> sin_print = [](double radian) {
		std::cout << "sin: " << sin(radian) << " ";
	};

	std::function<void(double)> cos_print = [](int radian) {
		std::cout << "cos: " << cos(radian) << " ";
	};

	std::vector<void(double)> functions{ sin_print, cos_print };

	std::cout << "[Выходные данные]: " << std::endl;
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions) {
			function(angle);
		}
		std::cout << std::endl;
	}
}