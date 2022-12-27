#pragma once

/// @brief Хранит информацию о динамическом массиве.
struct DynamicArray
{
	/// @brief Данные массива.
	int* Array;

	/// @brief Размер динамического массива.
	int Capacity;

	/// @brief Длина динамического массива.
	int Length = 0;
};

/// @brief Реализует создание динамического массива.
/// @param dynamicArray Динамический массив.
void CreateArray(DynamicArray* dynamicArray);

/// @brief Реализует добавление нового элемента в динамический массив.
/// @param dynamicArray Динамический массив.
/// @param value Значение, которое нужно добавить в динамический массив.
void AddElement(DynamicArray* dynamicArray, int value);

/// @brief Реализует удаление выбранного эелемента в динамическом массиве.
/// @param dynamicArray Динамический массив.
/// @param index Индекс элемента, который нужно удалить.
void RemoveElement(DynamicArray* dynamicArray, int index);

/// @brief Реализует вставку нового элемента в динамический массив.
/// @param dynamicArray Динамический массив.
/// @param value Значение, которое нужно вставить.
/// @param index Индекс элемента, после которого нужно вставить новый элемент.
void InsertElement(DynamicArray* dynamicArray, int value, int index);

/// @brief Реализует изменение размера динамического массива.
/// @param dynamicArray Динамический массив.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief Реализует уменьшение размера динамического массива.
/// @param dynamicArray Динамический массив.
void ReductionArray(DynamicArray* dynamicArray);

/// @brief Реализует обновление динамического массива.
/// @param dynamicArray Динамический массив.
void UpdateArray(DynamicArray* dynamicArray);

/// @brief Реализует заполнение динамического массива случайными значениями.
/// @param dynamicArray Динамический массив.
/// @param length Длина динамического массива.
void GetRandomArray(DynamicArray* dynamicArray, int length);

/// @brief Реализует сортировку динамического массива.
/// @param dynamicArray Динамический массив.
void SortArray(DynamicArray* dynamicArray);

/// @brief Реализует линейный поиск элемента в динамическом массиве.
/// @param dynamicArray Динамический массив.
/// @param value Искомое значение.
/// @return Индекс элемента с искомым значением.
int LinearSearch(DynamicArray* dynamicArray, int value);

/// @brief Реализует бинарный поиск элемента в динамическом массиве.
/// @param dynamicArray Динамический массив.
/// @param value Искомое значение.
/// @return Индекс элемента с искомым значением.
int BinarySearch(DynamicArray* dynamicArray, int value);