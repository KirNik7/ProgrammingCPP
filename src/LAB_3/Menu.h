#pragma once	
#include <string>
#include "QueueRingBuffer.h"
#include "QueueStack.h"
#include "RingBuffer.h"
#include "Stack.h"


 /// @brief Вызывает основное меню.
void Menu();

 /// @brief Вызывает меню для работы со стеком.
void MenuStack();


 /// @brief Вызывает меню для работы с кольцевым буфером.
void MenuRingBuffer();

 /// @brief Вызывает меню для работы с очередью на базе кольцевого буфера.
void MenuQueueRingBuffer();

 /// @brief Вызывает меню для работы с очередью на базе двух стеков.
void MenuQueueStack();

 /// @brief Выводит стек на экран.
 /// @param stack - стек.
void PrintStack(Stack* stack);

 /// @brief Выводит кольцевой буфер на экран.
 /// @param buffer - кольцевой буфер.
void PrintBuffer(RingBuffer* buffer);

 /// @brief Выводит очередь на экран.
 /// @param queue - очередь на базе двух стеков.
void PrintQueueStack(QueueStack* queue);

 /// @brief Проверяет, создан ли стек.
 /// @param stack - стек.
 /// @return Возвращает true, если стек создан, иначе false.
bool StackIsCreated(Stack* stack);

 /// @brief Проверяет, создан ли кольцевой буфер.
 /// @param buffer - кольцевой буфер.
 /// @return Возвращает true, если кольцевой буфер создан, иначе false.
bool RingBufferIsCreated(RingBuffer* buffer);

 /// @brief Проверяет, создана ли очередь на базе кольцевого буфера.
 /// @param queue - очередь на базе кольцевого буфера.
 /// @return Возвращает true, если очередь создана, иначе false.
bool QueueRingBufferIsCreated(QueueRingBuffer* queue);

 /// @brief Проверяет, создана ли очередь на базе двух стеков.
 /// @param queue - очередь на базе двух стеков.
 /// @return Возвращает true, если очередь создана, иначе false.
bool QueueStackIsCreated(QueueStack* queue);

 /// @brief Осуществляет проверку ввода размера кольцевого буфера.
 /// @return Размер.
int RingBufferSize();

 /// @brief Используется для ввода числа.
 /// @param outputString - строка для вывода.
 /// @return Возвращает введенное число.
int InputValue(std::string outputString);
