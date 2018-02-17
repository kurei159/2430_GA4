#pragma once
/*
Author: Cheuk-Wang Chau
Class for Circular Linked List based on linked list by D.S. Malik
*/

#include <cassert>

//Node
template <class Type>
struct CirnodeType
{
	Type info;
	CirnodeType<Type> *link;
};

template <class Type>
class circularLinkedList
{
public:
	const circularLinkedList<Type>& operator=(const circularLinkedList<Type> &); //Operator overloading

	void initializeList();

	bool isEmptyList() const;

	void destroy();

	void print() const;

	void reversePrint() const;

	int length() const;

	Type front() const;

	Type back() const;

	bool search(const Type& searchItem) const;

	void insert(const Type& insertItem);

	void deleteNode(const Type& deleteItem);




	circularLinkedList();
	circularLinkedList(const circularLinkedList<Type>& otherList);
	~circularLinkedList();

protected:
	int count;
	CirnodeType<Type> *first; //pointer to the first node
	CirnodeType<Type> *last; //pointer to the last node
private:
	void copyList(const circularLinkedList<Type>& otherList);
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and assigned
	// to this list.

};

//DEFINITIONS

template <class Type>
circularLinkedList<Type>::circularLinkedList()
{
	first = NULL;
	last = first;
	count = 0;
}

template <class Type>
circularLinkedList<Type>::~circularLinkedList()
{
	destroy();
}


template <class Type>
bool circularLinkedList<Type>::isEmptyList() const
{
	return (first == NULL); //If there's no first element then list is empty
}

template <class Type>
void circularLinkedList<Type>::destroy()
{
	CirnodeType<Type> *temp; //pointer to delete the node
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}



template<class Type>
void circularLinkedList<Type>::initializeList()
{
	destroy();
}

template<class Type>
int circularLinkedList<Type>::length() const
{
	return count;
}

template<class Type>
void circularLinkedList<Type>::print() const
{
	CirnodeType<Type> *current; //pointer to traverse the list
	current = first; //set current to point to the first node
	while (current != NULL)
	{
		cout << current->info << " "; //output info
		current = current->link;
	}//end while
}

template <class Type>
void circularLinkedList<Type>::reversePrint() const
{
	CirnodeType<Type> *current; //pointer to traverse the list
	current = last; //set current to point to the last node
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->back;
	}//end while
}//end reversePrint

template <class Type>
bool circularLinkedList<Type>::search(const Type& searchItem) const
{
	bool found = false;
	CirnodeType<Type> *current; //pointer to traverse the list
	current = first;
	while (current != NULL && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->link;
	if (found)
		found = (current->info == searchItem); //test for equality
	return found;
}//end search

template <class Type>
Type circularLinkedList<Type>::front() const
{
	assert(first != NULL);
	return first->info;
}

template <class Type>
Type circularLinkedList<Type>::back() const
{
	assert(last != NULL);
	return last->info;
}

template <class Type>
void circularLinkedList<Type>::insert(const Type& insertItem)
{
    CirnodeType<Type> *current; //pointer to traverse the list
    CirnodeType<Type> *trailCurrent; //pointer just before current
    CirnodeType<Type> *newNode; //pointer to create a node
    bool found;
    newNode = new CirnodeType<Type>; //create the node
    newNode->info = newItem; //store newItem in the node
    newNode->link = NULL; //set the link field of the node
    //to NULL
    if (this->first == NULL) //Case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;
        while (current != NULL && !found) //search the list
        if (current->info >= newItem)
            found = true;
        else
        {
            trailCurrent = current;
            current = current->link;
        }
        if (current == this->first) //Case 2
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL)
                this->last = newNode;
		
            this->count++;
        }
    }//end else
	this->last->link = first; //Last Node points to first or itself
}//end insert

template <class Type>
void circularLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	CirnodeType<Type> *current; //pointer to traverse the list
	CirnodeType<Type> *trailCurrent; //pointer just before current
	bool found;
	if (this->first == NULL) //Case 1
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = this->first;
		found = false;
		while (current != NULL && !found) //search the list
			if (current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}

		if (current == NULL) //Case 4
			cout << "The item to be deleted is not in the list."
			<< endl;
		else
			if (current->info == deleteItem) //the item to be
											 //deleted is in the list
			{
				if (this->first == current) //Case 2
				{
					this->first = this->first->link;

					if (this->first == NULL)
						this->last = NULL;
					delete current;
				}
				else //Case 3
				{
					trailCurrent->link = current->link;
					if (current == this->last)
						this->last = trailCurrent;
						
					delete current;
				}
				this->count--;
			}
			else //Case 4
				cout << "The item to be deleted is not in the "
				<< "list." << endl;
	}
	if (first != NULL)
	{
		this->last->link = this->first; //point last node to new first
	}
}//end deleteNode

template <class Type>
void circularLinkedList<Type>::copyList(const circularLinkedList<Type>& otherList)
{
	CirnodeType<Type> *newNode; //pointer to create a node
	CirnodeType<Type> *current; //pointer to traverse the list
	if (first != NULL) //if the list is nonempty, make it empty
		destroyList();
	if (otherList.first == NULL) //otherList is empty
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first; //current points to the
								   //list to be copied
		count = otherList.count;
		//copy the first node
		first = new CirnodeType<Type>; //create the node
		first->info = current->info; //copy the info
		first->link = NULL; //set the link field of the node to NULL
		last = first; //make last point to the first node
		current = current->link; //make current point to the link
								 // node
								 //copy the remaining list
		while (current != NULL)
		{
			newNode = new CirnodeType<Type>; //create a node
			newNode->info = current->info; //copy the info
			newNode->link = NULL; //set the link of newNode to NULL
			last->link = newNode; //attach newNode after last
			last = newNode; //make last point to the actual last
							//node
			current = current->link; //make current point to the
									 //link node
		}//end while
	}//end else

	if (first != NULL)
	{
		last->link = first;
	}
}//end copyList


template <class Type>
circularLinkedList<Type>::circularLinkedList(const circularLinkedList<Type>& otherList)
{
	first = NULL;
	copyList(otherList);
}//end copy constructor


 //overload the assignment operator
template <class Type>
const circularLinkedList<Type>& circularLinkedList<Type>::operator=(const circularLinkedList<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}//end else
	return *this;
}