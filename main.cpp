#include<iostream>
#include<cmath>
#define quality 256
using namespace std;

int main() {
	double table[quality]; //累積分布関数の値を入れる配列
	double x_val[quality]; //横軸の値を入れる配列
	int x_min = -4; //横軸の最小値
	int x_max = 4; //横軸の最大値
	double mu = 15.0; //正規分布の平均値
	double sigma = 1.2; //正規分布の標準偏差
	double x = 14.6; //確率変数

	for (int i = 0; i < quality; i++) {
		double x_ax = x_min + (x_max - x_min) * (i + 0.5) / quality;
		x_val[i] = x_ax;
		table[i] = 0.5 * (1 + erf(x_ax / sqrt(2)));
	}

	double a = (x - mu - 0.5) / sigma; //積分範囲の左端
	int index_a = (a - x_min) * quality / (x_max - x_min) - 0.5;
	double b = (x - mu + 0.5) / sigma; //積分範囲の右端
	int index_b = (b - x_min) * quality / (x_max - x_min) - 0.5;

	double x_value_a = x_val[index_a];
	double probability_a = table[index_a];
	double x_value_b = x_val[index_b];
	double probability_b = table[index_b];

	double probability = probability_b - probability_a;

	cout << "積分範囲 [" << x - 0.5 << ", " << x + 0.5 << "] →" << "[" << a << ", " << b << "]" << endl;
	cout << "probability = " << probability << endl;
	return 0;

}