#pragma once
#include "HashTable.h"

/// @brief Меню для хеш-таблицы.
void MenuHashTable();

/// @brief Меню для словаря.
void MenuDictionary();

/// @brief Функция для корректного ввода числа.
/// @param outputString - строка для вывода информации.
/// @return Возвращает число
int InputValue(std::string outputString);

/// @brief Функция для ввода строки.
/// @param outputString - строка для вывода информации.
/// @return Возвращает строку.
std::string InputString(std::string outputString);

/// @brief Выводит на экран хеш-таблицу.
/// @param table - таблица.
void PrintHashTable(HashTable* table);

/// @brief Основное меню.
void Menu();