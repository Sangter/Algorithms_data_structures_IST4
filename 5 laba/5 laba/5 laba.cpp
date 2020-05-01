#include <iostream> 
#define N 12 

using namespace std;

void input(int* a) //проверка на ввод положительного числа	
{
	while (!(cin >> *a) || *a <= 0)
	{
		cin.clear();
		cin.ignore(32267, '\n');
		cout << "Error" << std::endl;
	}
}


void create_lot(int stones[])   //создание массива веса камней 
{
	cout << N << " камней в куче. Вес камней:\n";
	for (int i = 0; i < N; i++) {
		cout << (i + 1) << ": ";
		input(&stones[i]);
	}
}

void arrange_lot(int stones[])   //сортировка камней по убыванию 
{
	int i, j, cur;
	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			if (stones[i] < stones[j]) {
				cur = stones[i];
				stones[i] = stones[j];
				stones[j] = cur;
			}
		}
	}
}

void arrange_bags(int stones[])  //создание двух куч, вес которых будет отличен минимально
{
	int sum1 = 0, sum2 = 0, k1 = 0, k2 = 0, i;
	int bag1[N - 1], bag2[N - 1];
	for (i = 0; i < N; i++) {
		if (sum1 <= sum2) {
			bag1[k1] = stones[i];
			sum1 += stones[i];
			k1++;
		}
		else {
			bag2[k2] = stones[i];
			sum2 += stones[i];
			k2++;
		}
	}
	if (1.0*sum1 / sum2 <= 2) {
		cout << "\n Куча №1: ";
		for (i = 0; i < k1; i++)
			cout << bag1[i] << "  ";
		cout << "\n Вес 1 кучи: " << sum1 << endl;
		cout << "\n Куча №2: ";
		for (i = 0; i < k2; i++)
			cout << bag2[i] << "  ";
		cout << "\n Вес 2 кучи: " << sum2 << endl;
	}
	else cout << "Вес различается более чем в 2 раза\n";
}

int main() {
	setlocale(LC_ALL, "");
	int lot[N];
	create_lot(lot);
	arrange_lot(lot);
	arrange_bags(lot);
	cin.sync();
	cin.get();
	return 0;
}