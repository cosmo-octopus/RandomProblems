#include "Queue.h"

int	main()
{
	Queue<int>	q;

	q.enqueue(1);
	q.enqueue(2);
	q.printAll();
	std::cout << "size: " << q.get_size() << std::endl;
	q.enqueue(3);
	q.printAll();
	std::cout << "size: " << q.get_size() << std::endl;
	std::cout << "dequeued: " << q.dequeue() << std::endl;
	q.printAll();
	std::cout << "size: " << q.get_size() << std::endl;
	std::cout << "dequeued: " << q.dequeue() << std::endl;
	q.printAll();
	std::cout << "size: " << q.get_size() << std::endl;
	q.enqueue(42);
	q.printAll();
	std::cout << "is queue empty?: " << q.isEmpty() << std::endl;
	q.front() = 1;
	q.rear() = 42;
	q.printAll();
	std::cout << "dequeued: " << q.dequeue() << std::endl;
	std::cout << "dequeued: " << q.dequeue() << std::endl;
	std::cout << "is queue empty?: " << q.isEmpty() << std::endl;
}