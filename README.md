# PhysicalOS-arduino
Однокнопочный калькулятор на ардуино

[Канал PhysicalOS в Телеграме](http://telete.in/PhysicalOS "Канал PhysicalOS в Телеграме")

Автор: MaksPV [Телеграм](https://telete.in/Maksimushka "Телеграм") [ВКонтакте](http://vk.com/MaksPVi "ВКонтакте")

![Иллюстрация к проекту](https://github.com/MaksPV/PhysicalOS-arduino/raw/master/logo.png)

## Схема подключения
![Иллюстрация к проекту](https://github.com/MaksPV/PhysicalOS-arduino/raw/master/scheme.jpg)
- Arduino Uno или ей подобные
- ЖК дисплей 1602
- Расширитель I2C для LCD модулей на PCF8574T
- Кнопка

## Установка
1. Установить библеотеку GyverButton из архива чуть мной моддифицированной
2. Открыть скетч из архива по адресу /Sketch/Sketch.ino
3. Залить его в ардуину

## Конструкция меню
1 - одно нажатие, 2 - два и т.д.

0 - зажатие кнопки = выход из режимов

#### Главное меню
1. Управление первой переменной
2. Управление второй переменной
3. Выбор знака действия
4. Переход в режим решения квадратных уравнений
5. Режим присвоения значений переменных

#### Управление переменными
1. Прибавить 1
2. Убавить 1
3. Умножить на 10
4. Поделить на 10
5. Умножить на -1

#### Выбор знака
1. Следующая страница
      1. Следующая страница
            1. Логарифм из a
            2. Тангенс из a
      2. Возведение в степень
      3. Извлечение корня (где a - число из которого извлекается корень, а b - степень)
      4. Синусоид из a
      5. Косинус из a
2. Прибавление
3. Вычитание
4. Умножение
5. Деление

#### Решатор квадратных уравнений
1. Управление первой переменной
2. Управление второй переменной
3. Управление третьей переменной
4. Переход в режим решения примеров
5. Режим переноса значений переменных

#### Режим присвоения значений переменных
1. Выбор переменной (a -> b -> c -> a -> и так далее)
2. Выбор присвоения
     1. Следующая страница
                        1. присвоения числа пи
	        	2. присвоения числа е
	          	3. присвоения гравитационной постоянной
	        	4. присвоение нуля
     2. Из суммы
     3. Из первой переменной
     4. Из второй переменной
     5. Из третьей переменной
