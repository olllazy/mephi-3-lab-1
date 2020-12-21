#pragma once
#include <string>
#include <limits>
#include <iostream> 
#include <exception>
#include <ctime> 
#include <chrono>

#include "linkedlist.h" 
#include "dynamicarray.h" 
#include "sequence.h" 
#include "sort.h" 


template<typename T>
void darand(T* da,int size) {
	for (int i = 0; i < size; i++) {
		int el = rand() % 10;
		da->append(el);
	}
}

template<typename T>
void lirand(T* li, int size) {
	for (int i = 0; i < size; i++) {
		int el = rand() % 10;
		li->set(el, i);
	}
}

template<typename T> 
void print(T* str) {
	for (int i = 0; i < str->getSize(); i++) {
		std::cout << str->get(i) << ' ';
	};
	std::cout << std::endl;
	return;
}

int work_witn_list(){
	int size = 0;
	std::cout << "Enter the size: " << std::endl;
	std::cin >> size; 
	try {
		ListSequence<int>* li = new ListSequence<int>(size);
		lirand(li,size);
		print(li);
		std::cout << "Len: " << li->getSize() << '\n';
		std::cout << '\n';

		ListSequence<int> li2(*(li));

		Sorter<int>* sorter = new Sorter<int>();
		sorter->bubblesort(li2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			});
		std::cout << "sorted1:" << std::endl;
		print(&li2);


		sorter->shakersort(li2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			}, -1);
		std::cout << "sorted2:" << std::endl;
		print(&li2);


		sorter->quicksort(li2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			}, li2.getSize() - 1);
		std::cout << "sorted3:" << std::endl;
		print(&li2);


		sorter->insertionsort(li2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			}, -1);
		std::cout << "sorted4:" << std::endl;
		print(&li2);


		sorter->shellsort(li2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			});
		std::cout << "sorted5:" << std::endl;
		print(&li2);

		std::cout << std::endl << "the first:" << std::endl;
		print(li);

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}

	return 0;

} 

int work_witn_da() {
	int size = 0;
	std::cout << "Enter the size: " << std::endl;
	std::cin >> size;
	try {
		ArraySequence<int>* da = new ArraySequence<int>(size);
		darand(da,size);

		print(da);
		std::cout << "Len: " << da->getSize() << '\n';
		std::cout << '\n';

		ArraySequence<int> da2(*(da));

		Sorter<int>* sorter = new Sorter<int>();
		sorter->bubblesort(da2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			});
		std::cout << "sorted1:" << std::endl;
		print(&da2);

		
		sorter->shakersort(da2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			},-1);
		std::cout << "sorted2:" << std::endl;
		print(&da2);

		
		sorter->quicksort(da2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			}, da2.getSize()-1);
		std::cout << "sorted3:" << std::endl;
		print(&da2);

		
		sorter->insertionsort(da2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			},-1);
		std::cout << "sorted4:" << std::endl;
		print(&da2);

		
		sorter->shellsort(da2, [](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
			});
		std::cout << "sorted5:" << std::endl;
		print(&da2);

		std::cout << std::endl << "the first:" << std::endl;
		print(da);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}

	return 0;

} 

int readInt(int from = std::numeric_limits<int>::min(), int to = std::numeric_limits<int>::max()) {
	while (true) {
		try {
			std::string line;
			std::getline(std::cin, line);
			if (line.empty()) throw std::exception();

			int read = std::stoi(line);
			if (read < from || read > to) throw std::exception();

			std::cout << "\n";
			return read;
		}
		catch (...) {
			std::cout << "Please, enter a number from " << std::to_string(from) << " to " << std::to_string(to) << ": ";
		}

	}
} 

float readFloat(float from = std::numeric_limits<float>::lowest(), float to = std::numeric_limits<float>::max()) {
	while (true) {
		try {
			std::string line;
			std::getline(std::cin, line);
			if (line.empty()) throw std::exception();

			float read = std::stof(line);
			if (read < from || read > to) throw std::exception();

			std::cout << "\n";
			return read;
		}
		catch (...) {
			std::cout << "Please, enter a float number from " << std::to_string(from) << " to " << std::to_string(to) << ": ";
		}

	}
}

void printMenu() {
	std::cout << "1. set A (array)" << endl;
	std::cout << "2. set B (list)" << endl;
	std::cout << "3. select sort function" << endl;
	std::cout << "4. compare sort functions" << endl;
	std::cout << "5. exit" << endl;
	return;
}


ArraySequence<int>* readArray() {
	int size; 
	while (true) {
		std::cout << "set size: " << endl;
		std::cin >> size;
		try {
			ArraySequence<int>* da = new ArraySequence<int>(size);
			std::cout << "1. set automatically" << endl;
			std::cout << "2. set by hand" << endl;

			int choice = readInt(1, 2);
			switch (choice) {
			case 1:
				darand(da, size);
				break;
			case 2:
				for (int i = 0; i < size; i++) {
					int el;
					std::cin >> el;
					da->append(el);
				}
				break;
			}
			print(da);
			return da;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
			return nullptr;
		}
	}
}  

ListSequence<int>* readList() {
	int size;
	while (true) {
		std::cout << "set size: " << endl;
		std::cin >> size;
		try {
			ListSequence<int>* li = new ListSequence<int>(size);
			std::cout << "1. set automatically" << endl;
			std::cout << "2. set by hand" << endl;

			int choice = readInt(1, 2);
			switch (choice) {
			case 1:
				lirand(li, size);
				break;
			case 2:
				for (int i = 0; i < size; i++) {
					int el;
					std::cin >> el;
					li->set(el, i);
				}
				break;
			}
			print(li);
			return li;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
			return nullptr;
		}
	}
} 




int menu() {
	ArraySequence<int>* A = nullptr;
	ListSequence<int>* B = nullptr; 
	float c = 0; 
	while (true) {
		printMenu();
		
		int choice = readInt(1, 5);
		switch (choice) {
		case 1:
			delete A;
			A = readArray();
			break;
		case 2:
			delete B;
			B = readList();
			break;
		case 3:
			while (true) {
				std::cout << "select sequence: " << endl;
				std::cout << "1. set A (array)" << endl;
				std::cout << "2. set B (list)" << endl;
				std::cout << "3. exit" << endl;
				int choice_seq = readInt(1, 3); 
				if (choice_seq == 3) break; 

				while (true) {
					try {
						std::cout << "1. bubble sort" << endl;
						std::cout << "2. shaker sort" << endl;
						std::cout << "3. quick sort" << endl;
						std::cout << "4. insertion sort" << endl;
						std::cout << "5. shell sort" << endl;
						std::cout << "6. exit" << endl;
						int choice_sort = readInt(1, 6);
						if (choice_sort == 6) break;


						Sorter<int>* sorter = new Sorter<int>();



						switch (choice_sort) {
						case 1:
							if (choice_seq == 1) {
								if (A == nullptr) A = readArray();
								ArraySequence<int> Asort(*(A));
								auto point_1 = std::chrono::system_clock::now();
								sorter->bubblesort(Asort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Asort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							else {
								if (B == nullptr) B = readList();
								ListSequence<int> Bsort(*(B));
								auto point_1 = std::chrono::system_clock::now();
								sorter->bubblesort(Bsort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Bsort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							break;
						case 2:
							if (choice_seq == 1) {
								if (A == nullptr) A = readArray();
								ArraySequence<int> Asort(*(A));
								auto point_1 = std::chrono::system_clock::now();
								sorter->shakersort(Asort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Asort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							else {
								if (B == nullptr) B = readList();
								ListSequence<int> Bsort(*(B));
								auto point_1 = std::chrono::system_clock::now();
								sorter->shakersort(Bsort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Bsort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							break;
						case 3:
							if (choice_seq == 1) {
								if (A == nullptr) A = readArray();
								ArraySequence<int> Asort(*(A));
								auto point_1 = std::chrono::system_clock::now();
								sorter->quicksort(Asort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									}, Asort.getSize() - 1);
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Asort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							else {
								if (B == nullptr) B = readList();
								ListSequence<int> Bsort(*(B));
								auto point_1 = std::chrono::system_clock::now();
								sorter->quicksort(Bsort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									}, Bsort.getSize() - 1);
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Bsort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							break;
						case 4:
							if (choice_seq == 1) {
								if (A == nullptr) A = readArray();
								ArraySequence<int> Asort(*(A));
								auto point_1 = std::chrono::system_clock::now();
								sorter->insertionsort(Asort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Asort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							else {
								if (B == nullptr) B = readList();
								ListSequence<int> Bsort(*(B));
								auto point_1 = std::chrono::system_clock::now();
								sorter->insertionsort(Bsort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Bsort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							break;
						case 5:
							if (choice_seq == 1) {
								if (A == nullptr) A = readArray();
								ArraySequence<int> Asort(*(A));
								auto point_1 = std::chrono::system_clock::now();
								sorter->shellsort(Asort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Asort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							else {
								if (B == nullptr) B = readList();
								ListSequence<int> Bsort(*(B));
								auto point_1 = std::chrono::system_clock::now();
								sorter->shellsort(Bsort, [](int a, int b) {
									if (a < b)
										return -1;
									if (a > b)
										return 1;
									else
										return 0;
									});
								auto point_2 = std::chrono::system_clock::now();
								std::chrono::duration<double> elapsed_sort = point_2 - point_1;
								print(&Bsort);
								cout << "Sort time: " << elapsed_sort.count() << std::endl;
							}
							break;
						}
					}
					catch (std::exception& e)
					{
						std::cout << e.what() << '\n';
						return 1;
					}
				}
			}
			break;
		
		case 4:
			while (true) {
				std::cout << "select sequence: " << endl;
				std::cout << "1. set A (array)" << endl;
				std::cout << "2. set B (list)" << endl;
				std::cout << "3. exit" << endl;
				int choice_seq = readInt(1, 3);
				if (choice_seq == 3) break;

				try {
							
						std::chrono::duration<double> elapsed_sort1;
						std::chrono::duration<double> elapsed_sort2;

						for (int k = 1; k < 3; k++) {
							std::cout << "Please, select function #" << std::to_string(k) <<": " << endl;

							std::cout << "1. bubble sort" << endl;
							std::cout << "2. shaker sort" << endl;
							std::cout << "3. quick sort" << endl;
							std::cout << "4. insertion sort" << endl;
							std::cout << "5. shell sort" << endl;
							std::cout << "6. exit" << endl;
							int choice_sort = readInt(1, 6);
							if (choice_sort == 6) break;


							Sorter<int>* sorter = new Sorter<int>();



							switch (choice_sort) {
							case 1:
								if (choice_seq == 1) {
									if (A == nullptr) A = readArray();
									ArraySequence<int> Asort(*(A));
									auto point_1 = std::chrono::system_clock::now();
									sorter->bubblesort(Asort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Asort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								else {
									if (B == nullptr) B = readList();
									ListSequence<int> Bsort(*(B));
									auto point_1 = std::chrono::system_clock::now();
									sorter->bubblesort(Bsort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Bsort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								break;
							case 2:
								if (choice_seq == 1) {
									if (A == nullptr) A = readArray();
									ArraySequence<int> Asort(*(A));
									auto point_1 = std::chrono::system_clock::now();
									sorter->shakersort(Asort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Asort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								else {
									if (B == nullptr) B = readList();
									ListSequence<int> Bsort(*(B));
									auto point_1 = std::chrono::system_clock::now();
									sorter->shakersort(Bsort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Bsort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								break;
							case 3:
								if (choice_seq == 1) {
									if (A == nullptr) A = readArray();
									ArraySequence<int> Asort(*(A));
									auto point_1 = std::chrono::system_clock::now();
									sorter->quicksort(Asort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										}, Asort.getSize() - 1);
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Asort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								else {
									if (B == nullptr) B = readList();
									ListSequence<int> Bsort(*(B));
									auto point_1 = std::chrono::system_clock::now();
									sorter->quicksort(Bsort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										}, Bsort.getSize() - 1);
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Bsort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								break;
							case 4:
								if (choice_seq == 1) {
									if (A == nullptr) A = readArray();
									ArraySequence<int> Asort(*(A));
									auto point_1 = std::chrono::system_clock::now();
									sorter->insertionsort(Asort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Asort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								else {
									if (B == nullptr) B = readList();
									ListSequence<int> Bsort(*(B));
									auto point_1 = std::chrono::system_clock::now();
									sorter->insertionsort(Bsort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Bsort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								break;
							case 5:
								if (choice_seq == 1) {
									if (A == nullptr) A = readArray();
									ArraySequence<int> Asort(*(A));
									auto point_1 = std::chrono::system_clock::now();
									sorter->shellsort(Asort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Asort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								else {
									if (B == nullptr) B = readList();
									ListSequence<int> Bsort(*(B));
									auto point_1 = std::chrono::system_clock::now();
									sorter->shellsort(Bsort, [](int a, int b) {
										if (a < b)
											return -1;
										if (a > b)
											return 1;
										else
											return 0;
										});
									auto point_2 = std::chrono::system_clock::now();
									std::chrono::duration<double> elapsed_sort = point_2 - point_1;
									if (k == 1) {
										elapsed_sort1 = elapsed_sort;
									}
									else {
										elapsed_sort2 = elapsed_sort;
									}
									print(&Bsort);
									cout << "Sort time: " << elapsed_sort.count() << std::endl;
								}
								break;
							}
						}

						if (elapsed_sort1 < elapsed_sort2) {
							std::cout << "Fuction #1 works faster than function #2";
						}
						else {
							std::cout << "Fuction #2 works faster than function #1";
						}

						
				}
				catch (std::exception& e)
				{
					std::cout << e.what() << '\n';
					return 1;
				}
				
			}
			break;
		/*
		case 5:
		{
			if (!A) {
				print("A isn't set");
				break;
			}

			TypedVector* D = nullptr;
			D = *A * c;
			D->print();
			delete D;
			break;
		}
		case 6:
		{
			if (!A) {
				print("A isn't set");
				break;
			}

			float norm = A->getNorm();
			print(std::to_string(norm));
			break;
		}*/
		case 5:
			return 0;
			
		}
	}
}

int main() {

	srand(time(NULL));
	menu();
	
	return 0;
}