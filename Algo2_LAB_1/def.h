#include <iostream>
#include <vector>
#include <cmath>

int binary_search(std::vector<int> &mas, int left, int right, int target)
{
	if (left > right) return 0;
	int middle = (left + right) / 2;
	if (target == mas[middle]) return 1;
	else if (target > mas[middle]) return(binary_search(mas, middle + 1, right, target));
	else return binary_search(mas, left, middle - 1, target);
}


bool ladder_search(std::vector<std::vector<int>> &matrix, int target)
{
	int N = matrix[0].size();
	int M = matrix.size();
	int i = N - 1, j = 0;
	while ((i >= 0) && (j < M)) {
		if (matrix[j][i] == target) {
			return 1;
		}
		if (matrix[j][i] > target) i--;
		if (matrix[j][i] < target) j++;
	}
	return 0;
}

bool exp_search(std::vector<std::vector<int>> &matrix, int target)
{
	int N = matrix[0].size();
	int M = matrix.size();
	int i = N - 1, j = 0;
	while ((i >= 0) && (j < M)) {
		if (matrix[j][i] == target) {
			return 1;
		}
		if (matrix[j][i] > target) {
			i--;   // Идем влево если таргет меньше
			continue;
		}
		if (matrix[j][i] < target) {
			int rise = 1;
			int left = j;
			int right = j + rise;

			while ((left + right < M) && (matrix[left + right][i] < target)) {
				rise = rise * 2;
				right = right + rise;
			}

			left = (left + right) / 2;
			if (right > M - 1) {
				right = M - 1;
			}
			if (left == right) return 0;
			//std::cout << left << ' ' << right << '\n';
			while (left < right) {
				int middle = (left + right) / 2;
				if (matrix[middle][i] == target) return 1;
				else if (matrix[middle][i] > target) right = middle - 1;
				else left = middle + 1;
			}
			j = left; //пропускаем строки в которых нет таргета
		}
	}
	return 0;
}