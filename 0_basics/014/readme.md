# период числа - 2

Дана запись числа $N$ в десятичном виде, возможно, с периодом. Представьте это число в виде простой дроби $A / B$.

## входные данные

В первой строке дана десятичная запись числа $N$.

## выходные данные

Выведите два наименьших натуральных числа $A, B$, разделенных пробелом, таких, что $A / B = N$.

## ограничения

 * 0 <= N <= 1000
 * Период числа не более 1000 символов
 * time limit: 1s
 * memory limit: 8m

## пример

| INPUT | OUTPUT |
| ----- | ------ |
| 0.1 | 1 10 |
| 0.(3) | 1 3 |
| 3.36(1) | 121 36 |