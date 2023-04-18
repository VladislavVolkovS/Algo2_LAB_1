#include "def.h"
#include <chrono>

int main() {
	int M, N;
	N = pow(2,13);
	M = pow(2,13);
	std::vector<std::vector<int>> matrix1(M, std::vector<int>(N));
	std::vector<std::vector<int>> matrix2(M, std::vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix1[i][j] = (N/M*i + j)*2;
			matrix2[i][j] = (N / M * (i+1) * (j+1)) * 2;
		}
	}
	//for (int i = 0; i < M; i++) {
	//	for (int j = 0; j < N; j++) {
	//		std::cout << matrix2[i][j] << ' ';
	//	}
	//	std::cout << '\n';
	//}
	int target1 = 2 * N + 1;
	int target2 = 16 * N + 1;

	long timeavg = 0;
	std::cout << "binary in matrix1:\n";
	for (int j = 0; j < 100; j++) {
		auto start11 = std::chrono::steady_clock::now();// начальное время
		for (int i = 0; i < M; i++) {
			int a = binary_search(matrix1[i], 0, N - 1, target1);
			if (a != 0) {
				break;
			}
		}
		auto end11 = std::chrono::steady_clock::now(); // конечное время
		timeavg = timeavg + std::chrono::duration_cast<std::chrono::microseconds>(end11 - start11).count();
	}

	std::cout << "Elapsed time in microseconds: " << (timeavg / 100) << " us\n";



	timeavg = 0;
	std::cout << "ladder in matrix1:\n";
	for (int j = 0; j < 100; j++) {
		auto start12 = std::chrono::steady_clock::now();// начальное время
		ladder_search(matrix1, target1);
		auto end12 = std::chrono::steady_clock::now(); // конечное время
		timeavg = timeavg + std::chrono::duration_cast<std::chrono::microseconds>(end12 - start12).count();
	}
	std::cout << "Elapsed time in microseconds: " << (timeavg / 100) << " us\n";



	std::cout << "exp in matrix1:\n";
	for (int j = 0; j < 100; j++) {
		auto start13 = std::chrono::steady_clock::now();// начальное время
		exp_search(matrix1, target1);
		auto end13 = std::chrono::steady_clock::now(); // конечное время
		timeavg = timeavg + std::chrono::duration_cast<std::chrono::microseconds>(end13 - start13).count();
	}
	std::cout << "Elapsed time in microseconds: " << (timeavg / 100) << " us\n";

	std::cout << '\n';


	timeavg = 0;
	std::cout << "binary in matrix2:\n";
	for (int j = 0; j < 100; j++) {
		auto start21 = std::chrono::steady_clock::now();// начальное время
		for (int i = 0; i < M; i++) {
			int a = binary_search(matrix2[i], 0, N - 1, target2);
			if (a != 0) {
				break;
			}
		}
		auto end21 = std::chrono::steady_clock::now(); // конечное время
		timeavg = timeavg + std::chrono::duration_cast<std::chrono::microseconds>(end21 - start21).count();
	}
	std::cout << "Elapsed time in microseconds: " << (timeavg / 100) << " us\n";



	timeavg = 0;
	std::cout << "ladder in matrix2:\n";
	for (int j = 0; j < 100; j++) {
		auto start22 = std::chrono::steady_clock::now();// начальное время
		ladder_search(matrix2, target2);
		auto end22 = std::chrono::steady_clock::now(); // конечное время
		timeavg = timeavg + std::chrono::duration_cast<std::chrono::microseconds>(end22 - start22).count();
	}
	std::cout << "Elapsed time in microseconds: " << (timeavg / 100) << " us\n";


	timeavg = 0;
	std::cout << "exp in matrix2:\n";
	for (int j = 0; j < 100; j++) {
		auto start23 = std::chrono::steady_clock::now();// начальное время
		exp_search(matrix2, target2);
		auto end23 = std::chrono::steady_clock::now(); // конечное время
		timeavg = timeavg + std::chrono::duration_cast<std::chrono::microseconds>(end23 - start23).count();
	}
	std::cout << "Elapsed time in microseconds: " << (timeavg / 100) << " us\n";
	return 0;
}