## Реализация функции библиотеки matrix.h

Реализованы основные действия с матрицами: `create_matrix` (создание), `remove_matrix` (очистка и уничтожение), `eq_matrix` (сравнение), `sum_matrix` (сложение), `sub_matrix` (вычитание), `mult_matrix` (умножение), `mult_number` (умножение на число), `transpose` (транспонирование), `determinant` (вычисление определителя), `calc_complements` (вычисление матрицы алгребраический дополнений), `inverse_matrix` (поиск обратной матрицы).

- Библиотека разработана на языке Си стандарта C11 с использованием компилятора gcc
- Решение оформлено как статическая библиотека (с заголовочным файлом c_matrix.h)
- Библиотека разработана в соответствии с принципами структурного программирования
- Подготовлено полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check
- Unit-тесты покрывают не менее 80% каждой функции
- Предусмотрен Makefile для сборки библиотеки и тестов (с целями all, clean, test, c_matrix.a, gcov_report)
- В цели gcov_report формируется отчёт gcov в виде html страницы. Для этого unit-тесты запускаются с флагами gcov
