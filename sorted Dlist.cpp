#include <iostream>
using namespace std;

template <class T>
class Dlist
{
public:
	class Node
	{
		T  data;
		Node* next;
		Node* prev;
		Node()
		{
			data = 0;
			next = nullptr;
			prev = nullptr;
		}

		Node(T data, Node* n, Node* p)
		{
			this->data = data;
			next = n;
			prev = p;

		}
		friend class Dlist<T>;
	};

	class listiterator {
	protected:
		Node* current;
		friend class Dlist<T>;

	public:

		listiterator()
		{
			current = nullptr;
		}

		listiterator(Node* p) 		{
			current = p;
		}

		T& operator* () const
		{
			return current->data;
		}

		listiterator& operator++ ()
		{
			if (current != nullptr)
				this->current = this->current->next;
			return *this;
		}

		listiterator operator++ (int)
		{
			listiterator old = *this;
			++(*this);
			return old;
		}

		listiterator& operator-- ()
		{
			if (current != nullptr)
				this->current = this->current->prev;
			return *this;
		}

		listiterator operator-- (int)
		{
			listiterator old = *this;
			--(*this);
			return old;
		}


		bool operator== (const listiterator& rhs) const
		{
			return current == rhs.current;
		}

		bool operator!= (const listiterator& rhs) const  
		{
			return !(*this == rhs);
		}
	};
	listiterator begin() { return head; } 
	listiterator end() { return nullptr; }

	Dlist()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insert(T val)
	{
		Node* n = new Node;
		n->data = val;
		n->next = nullptr;
		n->prev = nullptr;

		if (head == nullptr)
		{
			head = n;
			tail = n;
		}

		else
		{
			Node* curr = head;
			Node* prev = nullptr;
			while (curr != nullptr && curr->data < val)
			{
				prev = curr;
				curr = curr->next;
			}
			if (curr == head)
			{
				n->next = head;
				n->prev = nullptr;
				head = n;
			}
			else if (curr != nullptr)
			{
				n->next = curr;
				curr->prev = n;
				n->prev = prev;
				prev->next = n;
			}
			else
			{
				prev->next = n;
				n->prev = prev;
				tail = n;
			}
		}
	}

	void Del(T val)
	{
		Node* n = new Node;
		n->data = val;
		n->next = nullptr;
		n->prev = nullptr;

		if (head == nullptr)
			cout << "Not Present";
		else
		{
			Node* curr = head;
			Node* prev = nullptr;
			while (curr != nullptr && curr->data != val)
			{
				prev = curr;
				curr = curr->next;
			}
			if(curr==nullptr){
				goto end;
			}
			if (curr == head)
			{
				head = head->next;
				delete curr;
			}
			else if (curr == tail)
			{
				prev->next = nullptr;
				tail = prev;
				delete curr;
			}
			else
			{
				prev->next = curr->next;
				curr->next->prev = prev;
				delete curr;
			}

		}
		end:
			int d;
	}

	void PrintForward()
	{
		if (head == nullptr)
		{
			cout << "->NULL" << endl;
		}
		else
		{
			Node* temp = head;
			while (temp != nullptr) 
			{
				cout <<"->"<< temp->data  ;
				temp = temp->next;
			}
			cout << "->NULL";
		}
	}

	void PrintBackward()
	{
		Node* temp = tail;
		if (temp == nullptr) 
		{
			cout << "->NULL" << endl;
		}
		else
		{
			
			while (temp != nullptr)
			{
				cout << "->"<< temp->data ;
				temp = temp->prev;
			}
			cout<<"->NULL";
		}
	}
	bool search(T val)
	{
		Node* cur;
		if (val < (tail->data) / 2)
		{
			cur = head;
			while (cur->data <= val)
			{
				if (cur->data = val)
				{
					return true;

				}
				else if (cur->data > val)
				{
					return false;
				}
				cur = cur->next;
			}
		}
		else
		{
			cur = tail;
			while (cur->data <= val) {
				if (cur->data = val)
				{
					return true;

				}
				else if (cur->data > val)
				{
					return false;
				}
				cur = cur->prev;
			}
		}
	}

	~Dlist()
	{
		Node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}

private:

	Node* head;
	Node* tail;

};

template <typename T> 
void unionDlist(Dlist<T>& a, Dlist<T>& b, Dlist<T>& c)
{
	Dlist<int>::listiterator duh = a.begin();
	Dlist<int>::listiterator bruh = b.begin();

	for (; duh != a.end(); duh++)
		c.Insert(*duh);
	for (; bruh != b.end(); bruh++)
	{
		bool flag = 0;
		for (duh = a.begin(); duh != a.end(); duh++)
			if (*bruh == *duh)
				flag = 1;

		if (flag == 0)
			c.Insert(*bruh);
	}
}

template <typename T>
void intersectDlist(Dlist<T>& a, Dlist<T>& b, Dlist<T>& c)
{
	Dlist<int>::listiterator duh = a.begin();
	Dlist<int>::listiterator bruh = b.begin();

	for (; duh != a.end(); duh++)
	{
		bool flag = 0;
		for ( bruh = b.begin(); bruh != b.end(); bruh++)
		{
			if (*bruh == *duh)
				flag = 1;
		}
		if (flag == 1)
		{
			c.Insert(*duh);
		}
	}
}

template <typename T>
void differenceDlist(Dlist<T>& a, Dlist<T>& b, Dlist<T>& c)
{
	Dlist<int>::listiterator duh = a.begin();
	Dlist<int>::listiterator bruh = b.begin();

	for (; duh != a.end(); duh++)
	{
		bool flag = 0;
		for (bruh = b.begin(); bruh != b.end(); bruh++)
		{
			if (*duh == *bruh)
				flag = 1;
		}
		if (flag == 0)
		{
			c.Insert(*duh);
		}
	}
}

template <typename T>
void bubblesortDlist(Dlist<T>& a)
{
	Dlist<int>::listiterator duh = a.begin();
	Dlist<int>::listiterator bruh = a.begin();

	T num1 = 0, num2 = 0, temp = 0;
	for (; duh != a.end(); duh++)
		for (bruh = a.begin(); bruh != a.end(); bruh++)
		{
			num1 = *bruh;
			if (++bruh != a.end())
			{
				num2 = *bruh;
				bruh--;

				if (num1 < num2)
				{
					temp = bruh.current->data;
					bruh.current->data = bruh.current->next->data;
					bruh.current->next->data = temp;
				}
			}
		}
}

int main()
{
	Dlist <int> l1;
	int dum=0;
	for(int i=0;i<10;i++){
		cin>>dum;
		l1.insert(dum);
	}
	l1.PrintBackward();
	cout << endl;
	cout<<"Enter Val to find:";
	cin>>dum;
	l1.Del(dum);
	l1.PrintForward();
	cout << endl;
	if(!l1.search(4)){
		cout<<"Found";
	}
	else{
		cout<<"Element Not Found Error: 404";
	}
	cout << endl;


	return 0;
}
