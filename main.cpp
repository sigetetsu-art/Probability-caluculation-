#include<iostream>
#include<cmath>
#define quality 256
using namespace std;

int main() {
	double table[quality]; //�ݐϕ��z�֐��̒l������z��
	double x_val[quality]; //�����̒l������z��
	int x_min = -4; //�����̍ŏ��l
	int x_max = 4; //�����̍ő�l
	double mu = 15.0; //���K���z�̕��ϒl
	double sigma = 1.2; //���K���z�̕W���΍�
	double x = 14.6; //�m���ϐ�

	for (int i = 0; i < quality; i++) {
		double x_ax = x_min + (x_max - x_min) * (i + 0.5) / quality;
		x_val[i] = x_ax;
		table[i] = 0.5 * (1 + erf(x_ax / sqrt(2)));
	}

	double a = (x - mu - 0.5) / sigma; //�ϕ��͈͂̍��[
	int index_a = (a - x_min) * quality / (x_max - x_min) - 0.5;
	double b = (x - mu + 0.5) / sigma; //�ϕ��͈͂̉E�[
	int index_b = (b - x_min) * quality / (x_max - x_min) - 0.5;

	double x_value_a = x_val[index_a];
	double probability_a = table[index_a];
	double x_value_b = x_val[index_b];
	double probability_b = table[index_b];

	double probability = probability_b - probability_a;

	cout << "�ϕ��͈� [" << x - 0.5 << ", " << x + 0.5 << "] ��" << "[" << a << ", " << b << "]" << endl;
	cout << "probability = " << probability << endl;
	return 0;

}