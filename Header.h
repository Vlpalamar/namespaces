#pragma once

#include"MyData.h"


namespace Vlad
{

	namespace DinThings
	{
	
			template<class T, int size>
			class List
			{
			public:
				MyData<T>* first = nullptr;
				MyData<T>* last = nullptr;
				int        length = 0;
				int        maxSize = size;

				List()
				{

				}
				~List()
				{

				}
				List<T, size>(const List<T, size>& l);
				void push_front(T val);
				void push_back(T val);
				void push_at(T val, int pos);
				T pop_front();
				T pop_back();
				T pop_at(int pos);
				T peek_front();
				T peek_back();
				T peek_at(int pos);
				T operator[](int ind);
				void print();
				int get_size();
				void clear();
				bool isEmpty();
				bool isFull();
				List<T, size> operator+(const List<T, size>& l);
				List<T, size> operator*(const List<T, size>& l);
				//friend ostream& operator<<(ostream &out, const List<T, size> &l);
			};

			template<class T, int size>
			ostream& operator<<(ostream& out, const List<T, size>& l)
			{
				MyData<T>* temp = l.first;
				while (temp)
				{
					out << temp->value;
					temp = temp->next;
				}
				return out;
			}

			template<class T, int size>
			inline void List<T, size>::push_front(T val)
			{
				if (length < size)
				{
					if (length == 0)
					{
						first = new MyData<T>;
						first->value = val;
						last = first;
					}
					else
					{
						MyData<T>* temp = new MyData<T>;
						temp->value = val;
						temp->next = first;
						first = temp;
					}
					length++;
				}
				else
					cout << "List full" << endl;
			}

			template<class T, int size>
			inline void List<T, size>::push_back(T val)
			{
				if (length < size)
				{
					if (length == 0) {
						first = new MyData<T>;
						first->value = val;
						last = first;
					}
					else
					{
						MyData<T>* temp = new MyData<T>;
						temp->value = val;
						last->next = temp;
						last = temp;
					}
					length++;
				}
				else
					cout << "List full" << endl;
			}

			template<class T, int size>
			inline void List<T, size>::push_at(T val, int pos)
			{
				if (length < size)
				{
					if (pos == 0)
						push_front(val);
					else
					{
						if (pos == length - 1)
						{
							push_back(val);
						}
						else
						{
							MyData<T>* temp = new MyData<T>;
							temp->value = val;
							MyData<T>* num = first;
							for (size_t i = 0; i < pos - 1; i++)
							{
								num = num->next;
							}
							temp->next = num->next;
							num->next = temp;
							length++;
						}
					}
				}
				else
					cout << "List full" << endl;
			}

			template<class T, int size>
			inline T List<T, size>::pop_front()
			{
				if (length > 0)
				{
					MyData<T>* temp = first;
					T val = first->value;
					first = first->next;
					delete temp;
					length--;
					return val;
				}
			}

			template<class T, int size>
			inline T List<T, size>::pop_back()
			{
				MyData<T>* num = first;
				T val = last->value;
				for (size_t i = 0; i < length - 2; i++)
				{
					num = num->next;
				}
				delete last;
				last = num;
				last->next = nullptr;
				length--;
				return val;
			}

			template<class T, int size>
			inline T List<T, size>::pop_at(int pos)
			{
				if (length)
				{
					if (pos == 0)
						pop_front();
					else
					{
						if (pos == length - 1)
						{
							pop_back();
						}
						else
						{
							MyData<T>* num = first, * temp;
							for (size_t i = 0; i < pos - 1; i++)
							{
								num = num->next;
							}
							temp = num->next;
							T val = temp->value;
							num->next = temp->next;
							delete temp;
							length--;
							return val;
						}
					}
				}
			}

			template<class T, int size>
			inline T List<T, size>::peek_at(int pos)
			{
				MyData<T>* temp = first;
				for (size_t i = 0; i < pos; i++)
				{
					temp = temp->next;
				}
				return temp->value;
			}

			template<class T, int size>
			inline T List<T, size>::operator[](int ind)
			{
				return peek_at(ind);
			}

			template<class T, int size>
			inline void List<T, size>::print()
			{
				if (length == 0)
				{
					cout << "List empty" << endl;
				}
				else
				{
					MyData<T>* temp = first;
					while (temp)
					{
						cout << temp->value << endl;
						temp = temp->next;
					}
					cout << endl;
				}
			}

			template<class T, int size>
			inline List<T, size> List<T, size>::operator+(const List<T, size>& l)
			{
				//s = this->maxSize + l.maxSize;
				List<T, size> S;// = *this;
				MyData<T>* temp = l.first;
				for (size_t i = 0; i < l.length; i++)
				{
					S.push_back(temp->value);
					temp = temp->next;
				}
				return S;
			}

			template<class T, int size>
			inline List<T, size> List<T, size>::operator*(const List<T, size>& l)
			{
				//TODO
			}

			template<class T, int size>
			inline List<T, size>::List(const List<T, size>& l)
			{
				MyData<T>* temp = l.first;
				while (temp)
				{
					this->push_back(temp->value);
					temp = temp->next;
				}
			}
	
			template<class T, int size>
			class ForwardList
			{
				MyData<T>* first = nullptr;
				MyData<T>* last = nullptr;
				int length = 0;
			public:
				~ForwardList()
				{
					//clear();
				}
				void push_front(T val);
				void push_back(T val);
				void push_at(T val, int pos);
				T pop_front();
				T pop_back();
				T pop_at(int pos);
				T peek_front();
				T peek_back();
				T peek_at(int pos);
				T operator[](int ind);
				void print();
				void print_reverse();
				int getSize();
				void clear();
				bool isEmpty();
				bool isFull();
				ForwardList<T, size> operator+(const ForwardList<T, size>& l);
				ForwardList<T, size> operator*(const ForwardList<T, size>& l);
			};

			template<class T, int size>
			inline void ForwardList<T, size>::push_front(T val)
			{
				if (length == size)
					throw MyException(LIST_FULL);
				if (!length)
				{
					first = last = new MyData<T>;
					first->value = val;
				}
				else
				{
					MyData<T>* temp = new MyData<T>;
					if (!temp)
						throw MyException(OUT_OF_MEMORY);
					temp->value = val;
					temp->next = first;
					first->prev = temp;
					first = temp;
				}
				length++;
			}

			template<class T, int size>
			inline void ForwardList<T, size>::push_back(T val)
			{
				if (length == size)
					throw MyException(LIST_FULL);
				if (!length)
				{
					first = last = new MyData<T>;
					first->value = val;
				}
				else
				{
					MyData<T>* temp = new MyData<T>;
					if (!temp)
						throw MyException(OUT_OF_MEMORY);
					temp->value = val;
					last->next = temp;
					temp->prev = last;
					last = temp;
				}
			}


			template<class T, int size>
			inline void ForwardList<T, size>::push_at(T val, int pos)
			{
				if (length < size)
				{
					if (pos == 0)
						push_front(val);
					else
						if (pos == length)
						{
							push_back(val);
						}
						else
						{
							MyData<T>* temp = new MyData<T>;
							temp->value = val;
							MyData<T>* num;
							if (pos < length / 2)
							{
								num = first;
								for (size_t i = 0; i < pos - 1; i++)
								{
									num = num->next;
								}
							}
							else
							{
								num = last;
								for (size_t i = 0; i < length - pos; i++)
								{
									num = num->prev;
								}
							}
							temp->next = num->next;
							num->next = temp;
							temp->next->prev = temp;
							temp->prev = num;
							length++;
						}
				}
				else
					cout << "List full" << endl;
			}

			template<class T, int size>
			inline T ForwardList<T, size>::pop_front()
			{
				if (length)
				{
					T val = first->value;
					MyData<T>* temp = first;
					first = first->next;
					first->prev = nullptr;
					delete temp;
					length--;
					return val;
				}
			}

			template<class T, int size>
			inline T ForwardList<T, size>::pop_back()
			{
				if (length)
				{
					T val = last->value;
					MyData<T>* temp = last;
					last = last->prev;
					last->next = nullptr;
					delete temp;
					length--;
					return val;
				}
			}

			template<class T, int size>
			inline T ForwardList<T, size>::pop_at(int pos)
			{

				if (length)
				{
					if (pos == 0)
						pop_front();
					else
						if (pos == length - 1)
						{
							pop_back();
						}
						else
						{
							MyData<T>* temp, * num;
							T val;
							if (pos < length / 2)
							{
								num = first;
								for (int i = 0; i < pos - 1; i++)
								{
									num = num->next;
								}
							}
							else
							{
								num = last;
								for (int i = 0; i < length - pos; i++)
								{
									num = num->prev;
								}
							}
							temp = num->next;
							val = temp->value;
							num->next = temp->next;
							temp->next->prev = num;
							delete temp;
							length--;
							return val;
						}
				}
				else
					cout << "List full" << endl;
			}

			template<class T, int size>
			inline void ForwardList<T, size>::print()
			{
				if (length == 0)
				{
					cout << "List empty" << endl;
				}
				else
				{
					MyData<T>* temp = first;
					while (temp)
					{
						cout << temp->value << " ";
						temp = temp->next;
					}
					cout << endl;
				}
			}

			template<class T, int size>
			inline void ForwardList<T, size>::print_reverse()
			{
				if (length == 0)
				{
					cout << "List empty" << endl;
				}
				else
				{
					MyData<T>* temp = last;
					while (temp)
					{
						cout << temp->value << " ";
						temp = temp->prev;
					}
					cout << endl;
				}
			}

			template<class T, int size>
			inline int ForwardList<T, size>::getSize()
			{
				return length;
			}

			template<class T, int size>
			inline ForwardList<T, size> ForwardList<T, size>::operator+(const ForwardList<T, size>& l)
			{
				//TODO
			}

			template<class T, int size>
			inline ForwardList<T, size> ForwardList<T, size>::operator*(const ForwardList<T, size>& l)
			{
				//TODO
			}


	
			template<class T, int size>
			class Queue
			{
				MyData<T>* first = nullptr;
				MyData<T>* last = nullptr;
				int length = 0;

			public:
				~Queue()
				{
					clear();
				}

				void push(T val);   //äîáàâèòü çíà÷åíèå â ñòåê

				T pop();            //èçâëå÷ü çíà÷åíèå èç ñòåêà

				T pick();           //ïîñìîòðåòü âåðõíåå çíà÷åíèå

				int getSize();      //ïîëó÷èòü òåêóùèé ðàçìåð

				void clear();       //î÷èñòêà ñòåêà

				bool isEmpty();     //ïðîâåðêà íà ïóñòîòó

				bool isFull();      //ïðîâåðêà íà çàïîëíåííîñòü

				void print();

				void print(int x, int y);
			};

			template<class T, int size>
			inline void Queue<T, size>::push(T val)
			{
				if (length < size)
				{
					if (length == 0)
					{
						first = new MyData<T>;
						first->value = val;
						last = first;
					}
					else
					{
						MyData<T>* temp = new MyData<T>;
						temp->value = val;
						last->next = temp;
						last = temp;
					}
					length++;
				}
				else
					cout << "Queue owerflow" << endl;
			}

			template<class T, int size>
			inline T Queue<T, size>::pop()
			{
				if (length)
				{
					T val = first->value;
					MyData<T>* temp = first;
					first = first->next;
					delete temp;
					length--;
					return val;
				}
			}

			template<class T, int size>
			inline T Queue<T, size>::pick()
			{
				return first->value;
			}

			template<class T, int size>
			inline void Queue<T, size>::print()
			{
				if (length == 0)
				{
					cout << "Queue empty" << endl;
				}
				else
				{
					MyData<T>* temp = first;
					while (temp)
					{
						cout << temp->value << " ";
						temp = temp->next;
					}
					cout << endl;
				}
			}

		
			template<class T, int size>
			inline bool Queue<T, size>::isEmpty()
			{
				return length == 0;
			}

			template<class T, int size>
			inline bool Queue<T, size>::isFull()
			{
				return length == size;
			}

			template<class T, int size>
			inline int Queue<T, size>::getSize()
			{
				return length;
			}

			template<class T, int size>
			inline void Queue<T, size>::clear()
			{
				while (length)
					pop();
				first = last = nullptr;
			}


			/////////////////////////////////////////

			template<class T, int size>
			class RingQueue
			{
				MyData<T>* first = nullptr;
				MyData<T>* last = nullptr;
				int length = 0;

			public:
				~RingQueue()
				{
					clear();
				}

				void push(T val);   //äîáàâèòü çíà÷åíèå â ñòåê

				void pop();         //èçâëå÷ü çíà÷åíèå èç ñòåêà

				T pick();           //ïîñìîòðåòü âåðõíåå çíà÷åíèå

				int getSize();      //ïîëó÷èòü òåêóùèé ðàçìåð

				void clear();       //î÷èñòêà ñòåêà

				bool isEmpty();     //ïðîâåðêà íà ïóñòîòó

				bool isFull();      //ïðîâåðêà íà çàïîëíåííîñòü

				void print();
			};

			template<class T, int size>
			inline void RingQueue<T, size>::push(T val)
			{
				if (length < size)
				{
					if (length == 0)
					{
						first = new MyData<T>;
						first->value = val;
						last = first;
					}
					else
					{
						MyData<T>* temp = new MyData<T>;
						temp->value = val;
						last->next = temp;
						last = temp;
					}
					length++;
				}
			}

			template<class T, int size>
			inline void RingQueue<T, size>::pop()
			{
				MyData<T>* temp = first;
				first = first->next;
				temp->next = nullptr;
				last->next = temp;
				last = temp;
			}

			template<class T, int size>
			inline bool RingQueue<T, size>::isEmpty()
			{
				return length == 0;
			}

			template<class T, int size>
			inline bool RingQueue<T, size>::isFull()
			{
				return length == size;
			}

			template<class T, int size>
			inline int RingQueue<T, size>::getSize()
			{
				return length;
			}

			template<class T, int size>
			inline void RingQueue<T, size>::clear()
			{
				MyData<T>* temp = first;
				while (temp)
				{
					first = first->next;
					delete temp;
					temp = first;
					length--;
				}
				first = last = nullptr;
			}

			template<class T, int size>
			inline void RingQueue<T, size>::print()
			{
				if (length == 0)
				{
					cout << "Queue empty" << endl;
				}
				else
				{
					MyData<T>* temp = first;
					while (temp)
					{
						cout << temp->value << " ";
						temp = temp->next;
					}
					cout << endl;
				}
			}

			template<class T, int size>
			inline T RingQueue<T, size>::pick()
			{
				return first->value;
			}

			////////////////////////////////////

			template<class T, int size>
			class PriorityQueue
			{
				MyData<T>* first = nullptr;
				MyData<T>* last = nullptr;
				int length = 0;

			public:
				~PriorityQueue()
				{
					clear();
				}

				void push(T val, Priority pre = LOW);   //äîáàâèòü çíà÷åíèå â ñòåê

				T pop();            //èçâëå÷ü çíà÷åíèå èç ñòåêà

				T& peek();           //ïîñìîòðåòü âåðõíåå çíà÷åíèå

				int getSize();      //ïîëó÷èòü òåêóùèé ðàçìåð

				void clear();       //î÷èñòêà ñòåêà

				bool isEmpty();     //ïðîâåðêà íà ïóñòîòó

				bool isFull();      //ïðîâåðêà íà çàïîëíåííîñòü

				void print();
			};

			template<class T, int size>
			inline void PriorityQueue<T, size>::push(T val, Priority pre)
			{
				if (length < size)
				{
					MyData<T>* temp = new MyData<T>;
					temp->value = val;
					temp->pre = pre;
					if (length == 0)
					{
						first = last = temp;
					}
					else
					{
						if (pre > first->pre)
						{
							temp->next = first;
							first = temp;
						}
						else
						{
							if (last->pre >= pre)
							{
								last->next = temp;
								last = temp;
							}
							else
							{
								MyData<T>* temp1 = first;
								while (temp1->pre >= pre && temp1->next->pre >= pre)
								{
									temp1 = temp1->next;
								}
								temp->next = temp1->next;
								temp1->next = temp;
							}
						}
					}
					length++;
				}
			}

			template<class T, int size>
			inline void PriorityQueue<T, size>::print()
			{
				if (length == 0)
				{
					cout << "Queue empty" << endl;
				}
				else
				{
					MyData<T>* temp = first;
					while (temp)
					{
						cout << temp->value << endl;
						temp = temp->next;
					}
					cout << endl;
				}
			}

			template<class T, int size>
			inline T PriorityQueue<T, size>::pop()
			{
				if (length)
				{
					T val = first->value;
					MyData<T>* temp = first;
					first = first->next;
					delete temp;
					length--;
					return val;
				}
			}

			template<class T, int size>
			inline bool PriorityQueue<T, size>::isEmpty()
			{
				return length == 0;
			}

			template<class T, int size>
			inline bool PriorityQueue<T, size>::isFull()
			{
				return length == size;
			}

			template<class T, int size>
			inline int PriorityQueue<T, size>::getSize()
			{
				return length;
			}

			template<class T, int size>
			inline void PriorityQueue<T, size>::clear()
			{
				while (length)
					pop();
				first = last = nullptr;
			}

			template<class T, int size>
			inline T& PriorityQueue<T, size>::peek()
			{
				return first->value;
			}

			template<class TKey, class TVal>
			class BTreeNode
			{
			public:
				TKey key;
				TVal value;

				BTreeNode* left = nullptr;
				BTreeNode* right = nullptr;

				BTreeNode(TKey key, TVal val) :key(key), value(val) {}

				void print()
				{
					if (left) left->print();
					cout << value << " ";
					if (right) right->print();
				}

				TVal* get(TKey& key)
				{
					if (key == this->key) return &value;
					if (key < this->key && left) return left->get(key);
					if (key > this->key&& right) return right->get(key);
					return nullptr;
				}
			};


			template<class TKey, class TVal>
			class BTree
			{
			public:
				static BTreeNode<TKey, TVal>* root;

				bool isEmpty()
				{
					return !root;
				}

				bool push(TKey key, TVal val)
				{
					if (!root)
					{
						root = new BTreeNode<TKey, TVal>(key, val);
						return true;
					}
					bool working = true;
					BTreeNode<TKey, TVal>* temp = root;
					do
					{
						if (key < temp->key)
						{
							if (temp->left)
							{
								temp = temp->left;
							}
							else
							{
								temp->left = new BTreeNode<TKey, TVal>(key, val);
								working = false;
							}
						}
						else
						{
							if (key > temp->key)
							{
								if (temp->right)
								{
									temp = temp->right;
								}
								else
								{
									temp->right = new BTreeNode<TKey, TVal>(key, val);
									working = false;
								}
							}
							else
								return false;
						}
					} while (working);
					return true;
				}

				TVal* get(TKey key)
				{
					if (root)
						return root->get(key);
					return nullptr;
				}

				void print()
				{
					if (!root)
						cout << "Tree empty" << endl;
					root->print();
					cout << endl;
				}

				BTreeNode<TKey, TVal>* push_r(TKey key, TVal val, BTreeNode<TKey, TVal>*& node = root)
				{
					if (!node)
					{
						node = new BTreeNode<TKey, TVal>(key, val);
						return node;
					}
					else
					{
						if (key < node->key) node->left = push_r(key, val, node->left);
						else if (key > node->key) node->right = push_r(key, val, node->right);
						else return nullptr;
					}
					return node;
				}
			};
			template<class TKey, class TVal>
			BTreeNode<TKey, TVal>* BTree<TKey, TVal>::root = nullptr;
		
				template<class T, int size>
				class StaticStack
				{
					MyData<T> data[size];
					int top = 0;
				public:
					StaticStack() {}

					~StaticStack() {}

					void push(T val);   //добавить значение в стек

					T pop();            //извлечь значение из стека

					T pick();           //посмотреть верхнее значение

					int getSize();      //получить текущий размер

					void clear();       //очистка стека

					bool isEmpty();     //проверка на пустоту

					bool isFull();      //проверка на заполненность

					void print();

				private:

				};

				template<class T, int size>
				inline void StaticStack<T, size>::push(T val)
				{
					if (top < size)
						data[top++].value = val;
					else
						cout << "Stack owerflow!" << endl;
				}

				template<class T, int size>
				inline T StaticStack<T, size>::pop()
				{
					T val = data[top - 1].value;
					top--;
					return val;
				}

				template<class T, int size>
				inline T StaticStack<T, size>::pick()
				{
					return data[top - 1].value;
				}

				template<class T, int size>
				inline int StaticStack<T, size>::getSize()
				{
					return top;
				}

				template<class T, int size>
				inline void StaticStack<T, size>::clear()
				{
					top = 0;
				}

				template<class T, int size>
				inline bool StaticStack<T, size>::isEmpty()
				{
					return top == 0;
				}

				template<class T, int size>
				inline bool StaticStack<T, size>::isFull()
				{
					return top == size;
				}

				template<class T, int size>
				inline void StaticStack<T, size>::print()
				{
					if (top == 0)
						cout << "Stack empty" << endl;
					else
					{
						for (size_t i = 0; i < top; i++)
						{
							cout << data[i].value << " ";
						}
						cout << endl;
					}
				}


				/////////////////////////////////////////////
				template<class T, int size>
				class DynamicStack
				{
					MyData<T>* data = nullptr;
					int top;
				public:
					DynamicStack() {}

					~DynamicStack() { clear(); }

					void push(T val);   //добавить значение в стек

					T pop();            //извлечь значение из стека

					T pick();           //посмотреть верхнее значение

					int getSize();      //получить текущий размер

					void clear();       //очистка стека

					bool isEmpty();     //проверка на пустоту

					bool isFull();      //проверка на заполненность

					void print();
				};

				template<class T, int size>
				inline void DynamicStack<T, size>::push(T val)
				{
					if (top < size)
					{
						if (top == 0)
						{
							data = new MyData<T>;
							data->value = val;
						}
						else
						{
							MyData<T>* temp = new MyData<T>;
							temp->value = val;
							temp->next = data;
							data = temp;
						}
						top++;
					}
					else
						cout << "Stack owerflow!" << endl;
				}

				template<class T, int size>
				inline T DynamicStack<T, size>::pop()
				{
					if (top > 0)
					{
						T val = data->value;
						MyData<T>* temp = data;
						data = data->next;
						delete temp;
						top--;
						return val;
					}
				}

				template<class T, int size>
				inline T DynamicStack<T, size>::pick()
				{
					if (top > 0)
						return data->value;
					return 0;
				}

				template<class T, int size>
				inline void DynamicStack<T, size>::print()
				{
					if (top == 0)
					{
						cout << "Stack empty" << endl;
					}
					else
					{
						MyData<T>* temp = data;
						while (temp)
						{
							cout << temp->value << " ";
							temp = temp->next;
						}
						cout << endl;
					}
				}

				template<class T, int size>
				inline bool DynamicStack<T, size>::isEmpty()
				{
					return top == 0;
				}

				template<class T, int size>
				inline bool DynamicStack<T, size>::isFull()
				{
					return top == size;
				}

				template<class T, int size>
				inline int DynamicStack<T, size>::getSize()
				{
					return top;
				}

				template<class T, int size>
				inline void DynamicStack<T, size>::clear()
				{
					while (top)
						pop();
					data = nullptr;
				}
		

	}
	namespace nm_Math
	{
		class MathProg
		{
			int A0;
			int step;
		public:
			MathProg() :MathProg(0, 0) {};
			MathProg(int A0, int step);
			void print(int n = 10);
			MathProg operator+(MathProg b);
			MathProg operator-(MathProg b);
			int operator[](int n);
			friend istream& operator>>(istream& in, MathProg& f);
			int summa(int n = 10);

			~MathProg();
		};



		inline MathProg::MathProg(int A0, int step)
		{
			this->A0 = A0;
			this->step = step;
		}

		inline void MathProg::print(int n)
		{
			if (n < 0)
			{
				int res = this->A0;
				n = n * -1;
				for (size_t i = 0; i < n; i++)
				{
					cout << res << " ";
					res = res - step;
				}

			}
			else {

				int res = this->A0;
				for (size_t i = 0; i < n; i++)
				{
					cout << res << " ";
					res = res + step;
				}
			}
		}
		istream& operator>>(istream& in, MathProg& f)
		{
			cout << "Enter: A0,Step" << endl;
			in >> f.A0 >> f.step;
			return in;
		}


		inline MathProg MathProg::operator+(MathProg b)
		{
			MathProg c;
			c.A0 = this->A0 + b.A0;
			c.step = this->step + b.step;
			return c;
		}

		inline MathProg MathProg::operator-(MathProg b)
		{
			MathProg c;
			c.A0 = this->A0 - b.A0;
			c.step = this->step - b.step;
			return c;
		}

		inline int MathProg::operator[](int n)
		{
			if (n < 0)
			{
				cout << "Error" << endl;
			}
			else
			{

				int res = this->A0;
				for (size_t i = 0; i < n; i++)// ìû èùåì èíäåêñ ïî ýòîìó
				{
					res = res + step;
				}
				return res;
			}
		}

		inline int MathProg::summa(int n)
		{
			if (n < 0)
			{
				cout << "Error" << endl;
			}
			else
			{
				int res = this->A0;
				int sum = res;
				for (size_t i = 0; i < n - 1; i++)
				{

					res = res + step;
					sum = sum + res;
				}

				return sum;
			}
		}

		MathProg ::~MathProg()
		{
		}  

	}
	namespace nm_Exceptions
	{
		enum ERROR
		{
			LIST_FULL,
			LIST_EMPTY,
			BAD_INDEX,
			OUT_OF_MEMORY
		};


		class MyException
		{
			ERROR m_error;
		public:
			MyException(ERROR e) :m_error(e) {}
			string getError(ERROR e) const
			{
				switch (e)
				{
				case LIST_FULL:
					return "Ñïèñîê ïîëíûé";
				case LIST_EMPTY:
					return "Ñïèñîê ïîëíûé";
				case BAD_INDEX:
					return "Íåïðàâèëüíûé èíäåêñ";
				}
				return "Íå èçâåñòíàÿ îøèáêà";
			}

			string what() const
			{
				return (getError(m_error) + " " + __TIMESTAMP__);
			}
		};
	}
}