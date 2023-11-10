#include <iostream>

struct Node
{
	int		val;
	Node	*next;
};

Node	*listNew();
void	listAdd(Node *head, Node *newElem);
void	listPrint(Node *head);
void	listClear(Node *head);
void	insert(Node* head, Node* newElem, int index);
int		listSize(Node *head);

void	listClear(Node *head)
{
	Node	*curr;

	while (head)
	{
		curr = head;
		head = head->next;
		delete(curr);
	}
}

void	listAdd(Node *head, Node *newElem)
{
	if (!head || !newElem)
		return ;
	while (head->next)
		head = head->next;
	head->next = newElem;
}

Node	*listNew()
{
	Node		*node = new (Node);
	static int	i = 0;

	i++;
	node->val = i;
	node->next = NULL;
	return (node);
}

void listInsert(Node *head, Node *newElem, int index) {
    Node *curr = head;
    Node *prev = nullptr;

    // Find the insertion point based on the index value
    while (curr && curr->val < index)
	{
        prev = curr;
        curr = curr->next;
    }

    // If inserting at the beginning or an empty list
    if (prev == nullptr)
	{
        newElem->next = head;
        head = newElem;
    }
	else
	{
        prev->next = newElem;
        newElem->next = curr;
    }
}

void	listPrint(Node *head)
{
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

int	listSize(Node *head)
{
	int	counter = 0;

	while (head)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int	main()
{
	Node	*head = new(Node);
	Node	*newNode;

	head->val = 0;
	head->next = NULL;
	for (int i = 0; i < 5; i++)
	{
		newNode = listNew();
		listAdd(head, newNode);
	}
	listPrint(head);
	newNode = listNew();
	listInsert(head, newNode, 3);
	listPrint(head);
	std::cout << "List Size: " << listSize(head) << std::endl;
	listClear(head);
}