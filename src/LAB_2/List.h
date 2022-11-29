#pragma once
#include "ListItem.h";

/// @brief —труктура линейного двусв€зного списка.
struct List
{
	Node* Head;
	Node* Tail;
	int Length;
};

/// @brief —оздание линейного двусв€зного списка.
/// @param list - указатель на линейный двусв€зный список.
void CreateList(List* list);

/// @brief ƒобавление элемента в конец линейного двусв€зного списка.
/// @param list - указатель на линейный двусв€зный список.
/// @param value - значение элемента.
void AddElement(List* list, int value);

/// @brief ”даление элемента из линейного двусв€зного списка.
/// @param list - указатель на линейный двусв€зный список.
/// @param index - индекс элемента.
void RemoveElement(List* list, int index);

/// @brief ¬ставка элемента в начало линейного двусв€зного списка.
/// @param list - указатель на линейный двусв€зный список.
/// @param value - значение элемента.
void InsertElementInBegin(List* list, int value);

/// @brief ¬ставка элемента в конец линейного двусв€зного списка.
/// @param list - указатель на линейный двусв€зный список.
/// @param value - значение элемента.
void InsertElementInEnd(List* list, int value);

/// @brief ¬ставка элемента в линейный двусв€зный список после определенного элемента.
/// @param list - указатель на линейный двусв€зный список.
/// @param value - значение элемента.
/// @param index - индекс элемента.
void InsertElementAfterCertainElement(List* list, int value, int index);

/// @brief ¬ставка элемента в линейный двусв€зный список перед определенным элементом.
/// @param list - указатель на линейный двусв€зный список.
/// @param value - значение элемента.
/// @param index - индекс элемента.
void InsertElementBeforeCertainElement(List* list, int value, int index);

/// @brief —ортировка линейного двусв€зного списка.
/// @param list - указатель на линейный двусв€зный список.
void SortList(List* list);

/// @brief Ћинейный поиск элемента в линейном двусв€зном списке.
/// @param list - указатель на линейный двусв€зный список.
/// @param value - значение элемента.
/// @return ¬озвращает индекс элемента.
/// @return ¬озвращает -1, если элемент не найден.
int LinearSearch(List* list, int value);
