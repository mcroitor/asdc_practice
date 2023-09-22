# сдвиг массива.

Дан массив __a__ из __N__ целых чисел. Циклически сдвиньте элементы массива вправо на один элемент (0-й элемент становится 1-м, 1-й становится 2-м, ..., последний становится 0-м, то есть массив `{3, 5, 7, 9}` превращается в массив `{9, 3, 5, 7}`).

## входные данные

В первой строке целое число N. Во второй строке N целых чисел.

## выходные данные

Вывести в одной строке элементы преобразованного массива, разделеные пробелом.

## ограничения

 * 1 <= N, M, a[i] <= 1000
 * time limit: 1s
 * memory limit: 8m

## пример

| INPUT | OUTPUT |
| ----- | ------ |
| 5<br>-2 -1 0 1 2 | 2 -2 -1 0 1 |