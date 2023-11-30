#include "Stack.h"

int	main()
{
	Stack<int>	stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	stack.printAll();
	std::cout << "size: " << stack.get_size() << std::endl;

	std::cout << "popped element: " << stack.pop() << std::endl;
	stack.printAll();

	stack.top() = 5;
	stack.printAll();
	std::cout << "popped element: " << stack.pop() << std::endl;
	stack.printAll();
	std::cout << "popped element: " << stack.pop() << std::endl;
	stack.printAll();
	std::cout << "size: " << stack.get_size() << std::endl;
	std::cout << "popped element: " << stack.pop() << std::endl;
	stack.printAll();
	std::cout << "popped element: " << stack.pop() << std::endl;
	std::cout << "is stack empty?: " << stack.empty() << std::endl;
	stack.push(42);
	stack.printAll();

}