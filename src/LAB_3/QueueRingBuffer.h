#pragma once
#include "RingBuffer.h"

 /// @brief Представляет реализацию по представлению очереди на базе кольцевого буфера.
struct QueueRingBuffer
{
	 /// @brief Буфер.
	RingBuffer* Buffer;
};

 /// @brief Создает очередь на базе кольцевого буфера.
 /// @param queue - очередь.
 /// @param size - размер очереди.
void CreateQueueBuffer(QueueRingBuffer* queue, int size);

 /// @brief Вставляет элемент в очередь.
 /// @param queue - очередь.
 /// @param value  - значение элемента.
void EnqueueBuffer(QueueRingBuffer* queue, int value);

 /// @brief Извлекает элемент из очереди.
 /// @param queue - очередь.
 /// @return Возвращает значение элемента.
int DequeueBuffer(QueueRingBuffer* queue);

 /// @brief Удаление очереди.
 /// @param queue - очередь.
void DeleteQueue(QueueRingBuffer* queue);
