#pragma once

//TODO: comments
struct ListItem
{
    /// @brief Следующий элемент.
    ListItem* Next = nullptr;

    /// @brief Преыдущий элемент.
    ListItem* Prev = nullptr;

    /// @brief Значение элемента.
    int Value = 0;
};

//TODO: comments
struct List
{
    /// @brief Указатель на первый элемент списка.
    ListItem* Head = nullptr;

    /// @brief Указатель на последний элемент списка.
    ListItem* Tail = nullptr;

    /// @brief Длина списка.
    int Length = 0;
};

/// @brief Создание линейного двусвязного списка.
/// @param list - указатель на линейный двусвязный список.
void CreateList(List* list);

/// @brief Добавление элемента в конец линейного двусвязного списка.
/// @param list - указатель на линейный двусвязный список.
/// @param value - значение элемента.
void AddElement(List* list, int value);

/// @brief Удаление элемента из линейного двусвязного списка.
/// @param list - указатель на линейный двусвязный список.
/// @param index - индекс элемента.
void RemoveElement(List* list, int index);

/// @brief Вставка элемента в начало линейного двусвязного списка.
/// @param list - указатель на линейный двусвязный список.
/// @param value - значение элемента.
void InsertElementInBegin(List* list, int value);

/// @brief Вставка элемента в линейный двусвязный список после определенного элемента.
/// @param list - указатель на линейный двусвязный список.
/// @param value - значение элемента.
/// @param index - индекс элемента.
void InsertElementAfterCertainElement(List* list, int value, int index);

/// @brief Вставка элемента в линейный двусвязный список перед определенным элементом.
/// @param list - указатель на линейный двусвязный список.
/// @param value - значение элемента.
/// @param index - индекс элемента.
void InsertElementBeforeCertainElement(List* list, int value, int index);

/// @brief Сортировка линейного двусвязного списка.
/// @param list - указатель на линейный двусвязный список.
void SortList(List* list);

/// @brief Линейный поиск элемента в линейном двусвязном списке.
/// @param list - указатель на линейный двусвязный список.
/// @param value - значение элемента.
/// @return Возвращает индекс элемента.
/// @return Возвращает -1, если элемент не найден.
int LinearSearch(List* list, int value);
