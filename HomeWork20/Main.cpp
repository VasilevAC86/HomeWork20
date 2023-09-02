# include <iostream>
# include <ctime>
# include <cstdlib>


short LEFT, RIGHT; // Объявляем глобальные переменные начала и конца диапазона 

short arr_Min(short arr[], const short length) { // Функция поиска минимального элемента в массиве
	short min = arr[0];
	for (short i = 0; i < length; i++)
		min = min < arr[i] ? min : arr[i];
	return min;
}

short arr_Max(short arr[], const short length) { // Функция поиска максимального элемента в массиве
	short max = arr[0];
	for (short i = 0; i < length; i++)
		max = max < arr[i] ? arr[i] : max;
	return max;
}

// Перегруженная функция для поиска последнего вхождения элемента в массив
short search_Last_Index(short arr[], const short length, short element) {
	short index = -1;
	for (short i = length - 1; i >= 0; i--) {
		if (arr[i] == element) {
			index = i;
			break;
		}
	}

	return index;
}
short search_Last_Index(short arr[], const short length, short element, short last) {
	short index = -1;
	for (short i = last - 1; i >= 0; i--)
		if (arr[i] == element) {
			index = i;
			break;
		}
	return index;
}

// Функция с параметром по умолчанию для возвращения индекса первого вхождения элемента в массив
short search_Index(short arr[], const short length, short element, short begin = 0) {
	short index = -1;
	for (short i = begin; i < length; i++)
		if (arr[i] == element) {
			index = i;
			break;
		}
	return index;
}

// Процедура заполнения массива случайными числами в выбранном пользователем диапазоне
void fill_Arr(short arr[], const short length) {
	srand(time(NULL));
	for (short i = 0; i < length; i++) // Цикл заполнения массива случайными числами в диапазоне от LEFT до RIGTH
		arr[i] = rand() % (RIGHT - LEFT) + LEFT;
}

void range_Examination() { // Процедура заполнения и проверки диапазона
	std::cout << "\nEnter the start of the range = ";
	std::cin >> LEFT;
	std::cout << "Enter the end of the range = ";
	std::cin >> RIGHT;
	while (RIGHT < LEFT) {
		std::cout << "Input error! The end of range cannot be less than the start!\nEnter the start of the range (data type is short) = ";
		std::cin >> LEFT;
		std::cout << "Enter the end of the range (data type is short) =";
		std::cin >> RIGHT;
	}
}

void print_Arr(short arr[], const short length) { // Процедура вывода массива в консоль
	std::cout << std::endl;
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b \n";
}

// Процедура вывода результата поиска индекса элемента массива, равному введённому числу в зависимости от выборов пользователя
void print_Index(short index, char choise_Search, char choise_Index, short element, short begin) {
	switch (index) {
	case -1:
		if (choise_Search == '1' && choise_Index == '1')
			std::cout << "\n\033[92mThe number " << element << " in the array (from the index " << begin << ") was not found\033[0m\n\n";
		else
			if (choise_Search != '1' && choise_Index == '1')
				std::cout << "\n\033[92mThe number " << element << " in the array (before the index " << begin << ") was not found\033[0m\n\n";
			else
				std::cout << "\n\033[92mThe number " << element << " in the array was not found\033[0m\n\n";
		break;
	default:
		std::cout << "\n\033[92mThe number " << element << " has an index " << index << " in the array\033[0m\n\n";
	}
}

double mean_Value(short arr[], const short length) { // Функция расчёта среднеарифметического значения элементов массива
	int sum = 0;
	for (short i = 0; i < length; i++)
		sum += arr[i];
	return sum / double(length);
}

void range(short arr[], const short length) {
	bool key = false; // Переменная для проверки наличия в массиве элементов, входящих в диапазон
	for (short i = 0; i < length; i++) // Цикл проверки наличия в массиве элементов, входящих в диапазон
		if (arr[i] < RIGHT && arr[i] > LEFT) {
			key = true;
			break; // Если в массиве есть хоть один элемент, входящий в диапазон, то нет смысла дальше крутить цикл
		}
	if (key) {
		std::cout << "\n\033[92mThe range includes the following array elements: ";
		for (short i = 0; i < length; i++) // Цикл вывода элементов массива, входящих в указанны диапазон
			if (arr[i] < RIGHT && arr[i] > LEFT)
				std::cout << arr[i] << ", ";
		std::cout << "\b\b\033[0m\n\n";
	}
	else
		std::cout << "\033[92mThe array has no elements in the specified range\033[0m\n\n";
}

short count(short arr[], const short length, short element) { // Функция расчёта кол-ва повторений числа element в массиве
	short counter = 0; // Счётчик кол-ва повторений числа element в массиве
	for (short i = 0; i < length; i++)
		if (arr[i] == element)
			counter++;
	return counter;
}

void sort_Arr(short arr[], const short length, char choise_Index) { // Процедура сортировки массива в зависимости от выбора пользователя
	for (short i = length - 1; i > 0; i--)
		for (short j = 0; j < i; j++)
			switch (choise_Index) {
			case '1':
				if (arr[j] > arr[j + 1])
					std::swap(arr[j], arr[j + 1]);
				break;
			default:
				if (arr[j] < arr[j + 1])
					std::swap(arr[j], arr[j + 1]);
			}
}

int main() {

	// Работа с массивом с помощью функций
	std::cout << "\033[91mWorking with an array using functions\033[0m\n\n";
	const short size = 20;
	short array[size];	
	std::cout << "Specify a range of random numbers to populate an array within the short data type:";
	range_Examination();
	fill_Arr(array, size);
	std::cout << "\033[92m\nSource array:\033[0m\n";
	print_Arr(array, size);	
	char choise_Search, choise_Index; // Переменные для хранения выбора пользователя направления поиска числа в массиве и индекса начала поиска соответственно
	short begin = -1, element; // Переменные для хранения индекса элемента массива, с которого надо начинать поиск числа, и числа для поиска соответственно
	std::cout << "\nEnter a number to find its index in an array = ";
	std::cin >> element;
	std::cout << "\nChoose how to search for a number in an array:\npress '1' from the beginning of the array \033[4m\033[92mor\033[0m press any other key from the end of the array.\nYoyr choise -> ";
	std::cin >> choise_Search;
	std::cout << "\nSearch number from specific array index?\nPress '1' for 'Yes' \033[4m\033[92mor\033[0m press any other key for 'No'.\nYour choise -> ";
	std::cin >> choise_Index;
	switch (choise_Search) {
	case '1':
		if (choise_Index == '1') {
			std::cout << "\nEnter the index of the array element from which to start searching -> ";
			std::cin >> begin;	
			print_Index(search_Index(array, size, element, begin), choise_Search, choise_Index, element, begin);			
		}
		else 
			print_Index(search_Index(array, size, element), choise_Search, choise_Index, element, begin);		
		break;
	default:
		if (choise_Index == '1') {
			std::cout << "\nEnter the index of the array element from which to start searching -> ";
			std::cin >> begin;
			print_Index(search_Last_Index(array, size, element, begin), choise_Search, choise_Index, element, begin);			
		}
		else 
			print_Index(search_Last_Index(array, size, element), choise_Search, choise_Index, element, begin);					
	}
	std::cout << "\033[92mThe minimum element of the array is " << arr_Min(array, size) << "\n\n";
	std::cout << "The maximum element of the array is " << arr_Max(array, size) << "\n\n";
	std::cout << "Arithmetic mean of all array elements is " << mean_Value(array, size) << "\033[0m\n\n";
	std::cout << "Specify a range to search for array elements (data type is short):";
	range_Examination();
	range(array, size);
	std::cout << "Enter a number to find the number of times it occurs in an array = ";
	std::cin >> element;
	short counter = count(array, size, element);
	if (counter == 1)
		std::cout << "\n\033[92mThe number " << element << " enters the array " << counter << " time\033[0m\n\n";
	else
		if(counter > 1)
			std::cout << "\n\033[92mThe number " << element << " enters the array " << counter << " times\033[0m\n\n";
		else
			std::cout << "\n\033[92mThe number " << element << " is not in the array\033[0m\n\n";
	std::cout << "Choose how to sort the array:\npress '1' to sort ascending numbers \033[4m\033[92mor\033[0m press any other key to sort descending numbers\nYour choise -> ";
	std::cin >> choise_Index;
	sort_Arr(array, size, choise_Index);
	std::cout << "\n\033[92mFinal array is: ";	
	print_Arr(array, size);
	std::cout << "\033[0m\n";

	return 0;
}
