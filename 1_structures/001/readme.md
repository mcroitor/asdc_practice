# Студент

Задан интерфейс класса:

```cpp
class Student {
    std::string _first_name;
    std::string _last_name;
    std::string _group;
public:
    Student(std::string _first_name, std::string _last_name, std::string _group);
    Student operator = (const Student& student);
    
    std::string firstName() const;
    std::string lastName() const;
    std::string group() const;
};
```

Напишите реализацию класса. Вспомогательная программа будет 

## входные данные

Оператор чтения из потока читает поля объекта, разделенные символом `;`.

## выходные данные

Оператор записи в поток записывает поля объекта в квадратных скобках, разделенные запятой и пробелом.

## ограничения

 * -- input data limits --
 * time limit: 1s
 * memory limit: 8m

## пример

| INPUT | OUTPUT |
| ----- | ------ |
| Gicu;Stirbu;IA2202 | [ Gicu, Stirbu, IA2202 ] |
