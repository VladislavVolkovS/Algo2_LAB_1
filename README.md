# Algo2_LAB_1
В данной лабораторной рассмотренны три реализации поиска элемента в матрице:
1. Бинарный поиск
2. Экспоненциальный
3. "Лесенка" + экспоненциальный

Каждый проверялся на время работы при различных исходных данных(различных размерах матриц)

Код запускался в Visual Studio 2019
___________________________________
Вывод: бинарный поиск работает дольше других двух алгоритмов на больших данных, поскольку вызывает функцию поиска
в каждой строке, даже если там нет элемента. Однако для маленьких данных он работает быстрее, так как в алгоритме
"лесенкой" и Экспоненциалбный поиск + "лесенка" мы по столбцам двигаемся пошагово, это значит что если элемент в
начале строки, мы пройдем всю строку линейно, а в случае бинарного поиска за log. 

Но при этом "лесенка" и экспоненциальный поиск + "лесенка" работают примерно за одинаковое время, но исходя из
второго графика и графика отношения аргоритма "экспоненциальный поиск + лесенка" на первом типе генерации и
втором, можем заметить что "экспоненциальный поиск + лесенка" работает быстрее в матрице элементы которой увеличиваются
очень быстро => данный алгоритм ищет быстрее чем обычная лесенка на матрице содержащей большой диапазон значений.

Результаты эффективности алгоритмов:

https://docs.google.com/spreadsheets/d/1GbiKcBLEcaIxFbzRT8PMMM15tzgz79CH/edit?usp=sharing&ouid=101333705451636887009&rtpof=true&sd=true
