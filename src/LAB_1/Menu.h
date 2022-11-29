#pragma once

/// @brief Реализует функцию ввода значения в меню.
/// @param value Значение в меню.
void InputValueInMenu(int* value);

/// @brief Реализует создание массива через меню.
/// @param dynamicArray Динамический массив.
void CreateArrayInMenu(DynamicArray* dynamicArray);

/// @brief Реализует добавление нового элемента в динамический массив через меню.
/// @param dynamicArray Динамический массив.
void AddElementInMenu(DynamicArray* dynamicArray);

/// @brief Реализует удаление элемента динамического массива через меню.
/// @param dynamicArray Динамический массив.
void RemoveElementInMenu(DynamicArray* dynamicArray);

/// @brief Реализует вставку нового элемента в динамический массив через меню.
/// @param dynamicArray Динамический массив.
void InsertELementInMenu(DynamicArray* dynamicArray);

/// @brief Реализует сортировку динамического массива через меню.
/// @param dynamicArray Динамический массив.
void SortArrayInMenu(DynamicArray* dynamicArray);

/// @brief Реализует линейный поиск элемента в динамическом массиве через меню.
/// @param dynamicArray Динамический массив.
void LinearSearchInMenu(DynamicArray* dynamicArray);

/// @brief Реализует бинарный поиск элемента в динамическом массиве через меню.
/// @param dynamicArray Динамический массив.
void BinarySearchInMenu(DynamicArray* dynamicArray);

/// @brief Реализует получение пользовательских элементов динамического массива через меню.
/// @param dynamicArray Динамический массив.
/// /// @param length Длина динамического массива.
void GetArrayByUserInMenu(DynamicArray* dynamicArray, int length);

/// @brief Реализует получение значений днамического массива.
/// @return Возвращает элементы динамического массива.
void PrintArrayInMenu(DynamicArray* dynamicArray);