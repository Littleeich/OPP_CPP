#include "List.h"
#include "Queue.h"
#include <ctime>
using namespace std;

void main()
{
	system("title Пользовательский адаптер Queue (двусвязный список)");
	srand(time(0));
	rand();

	Queue q(25);

	for (int i = 0; i < 5; i++)
		q.Enqueue(rand() % 90 + 10);

	q.Show();

	q.Dequeue();

	q.Show();

	for (int i = 0; i < 2; i++)
		q.Enqueue(rand() % 90 + 10);

	q.Show();

	for (int i = 0; i < 3; i++)
		q.Dequeue();

	q.Show();
}
