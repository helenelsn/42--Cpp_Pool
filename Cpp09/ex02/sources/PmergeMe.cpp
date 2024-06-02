/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:50 by Helene            #+#    #+#             */
/*   Updated: 2024/06/02 15:45:50 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

std::list<int>::iterator getItAtIndex(std::list<int> list, int index)
{
	// if (index >= list.size())
	// 	; // ?
	std::list<int>::iterator it = list.begin();
	std::advance(it, index);
	return it;
}

std::list<int>::iterator getItAtSteps(std::list<int>::iterator listIt, int step)
{
	std::list<int>::iterator it = listIt;
	std::advance(it, step);	// a securiser ?
	return it;
}

int distInList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	int d = 0;
	for (std::list<int>::iterator it = begin; it != end; it++)
		d++;
	return d;
}

void printList(std::list<int> list)
{
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::list<int>::iterator tmp = it;
		std::advance(tmp, 1);
		if (tmp != list.end() && *it > *tmp)
		{
			int index = distInList(list.begin(), it);
			std::cout << std::endl << "--------------------- Error at index " << index << ", element "<< *it << " is before " << *tmp << "------------------------ " << std::endl;
			return ; 
		}
		std::cout << *it << " ";
	}
}

void printVector(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i + 1 < vec.size() && vec[i] > vec[i + 1])
		{
			std::cout << std::endl << "--------------------- Error at index " << i << ", element "<< vec[i] << " is before " << vec[i + 1] << "------------------------ " << std::endl;
			return ; 
		}
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void printDeque(std::deque<int> deque)
{
	for (size_t i = 0; i < deque.size(); i++)
	{
		if (i + 1 < deque.size() && deque[i] > deque[i + 1])
		{
			std::cout << std::endl << "--------------------- Error at index " << i << ", element "<< deque[i] << " is before " << deque[i + 1] << "------------------------ " << std::endl;
			return ; 
		}
		std::cout << deque[i] << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << "PmergeMe: Default constructor" << std::endl;
	
	int value = 0;
	std::cout << "Before : ";
	for (int i = 1; i <argc; i++)
	{
		value = atoi(argv[i]);
		_sequence.push_back(value);
		_listSequence.push_back(value);
		_dequeSequence.push_back(value);
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	
	sortSequences();
}

PmergeMe::PmergeMe(const PmergeMe& other) {

	std::cout << "PmergeMe: Copy constructor" << std::endl;
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    
	std::cout << "PmergeMe: Assignment operator" << std::endl;
	
	// faire des getters plutot
	_sequence = other._sequence;
	_listSequence = other._listSequence; 
	return *this;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe: Destructor" << std::endl;
}

void PmergeMe::sortSequences() {

	double startVecSort, startListSort, startDequeSort, endSorts;
	
	startVecSort = clock();
	vectorSort();
	// startListSort = clock();
	// listSort();
	startDequeSort = clock();
	dequeSort();
	endSorts = clock();

	std::cout << "After : " << std::endl;
	printVector(_sequence);
	printDeque(_dequeSequence);
	// printList(_listSequence);
	
	// for (size_t i = 0; i < _sequence.size(); i++)
		// std::cout << _sequence[i] << " ";
	// std::cout << std::endl << std::endl;
	// for (std::list<int>::iterator it = _listSequence.begin(); it != _listSequence.end(); it++)
		// std::cout << *it << " ";
	std::cout << std::endl;	

	std::cout << "Time to process a range of " << _sequence.size() << " elements with std::[vector] : ";
	std::cout << (startDequeSort - startVecSort)/CLOCKS_PER_SEC * pow(10, 6) << " us" << std::endl;
	
	std::cout << "Time to process a range of " << _sequence.size() << " elements with std::[deque] : ";
	std::cout << (endSorts - startDequeSort)/CLOCKS_PER_SEC * pow(10, 6) << " us" << std::endl;
	
}

void vecRecInsertSort(std::vector< std::vector<int> > &pairs, int size)
{
	if (size <= 1)
		return ;
	
	vecRecInsertSort(pairs, size - 1);

	int last = pairs[size - 1][1];
	int lastComplement = pairs[size - 1][0];
	int j = size - 2;

	for (; j >= 0 && pairs[j][1] > last; j--)
	{
		pairs[j + 1][1] = pairs[j][1];
		pairs[j + 1][0] = pairs[j][0];
	}
	pairs[j + 1][1] = last;
	pairs[j + 1][0] = lastComplement;
}

void vecInsertionOrder(std::vector<int> &insertionOrder, std::vector<int> &boundsIndexes,
	size_t sequenceSize, size_t currVecSize)
{
	size_t tk = 1;
	size_t prev_tk = 1;
	int isOdd = (sequenceSize % 2);
	
	for (size_t k = 2; tk < currVecSize + isOdd; k++)
	{
			prev_tk = tk;
			tk = (pow(2, k + 1) + pow(-1, k)) / 3;
			for (size_t t = (tk < currVecSize + isOdd) ? tk : currVecSize -1 + isOdd ; t > prev_tk; t--)
				insertionOrder.push_back(t);	
	}
	for (size_t i = 0; i < insertionOrder.size(); i++)
		boundsIndexes.push_back(insertionOrder[i]);
}

// depuis begin() up to xi not included
// et on s'interesse, pour un yi, a bj avec j = i - 2
void vecBinaryInsertion(std::vector<int> &sorted, std::vector<int> &pairComplements,
	std::vector<int> &insertionOrder, std::vector<int> &boundsIndexes)
{
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		std::vector<int>::iterator insertingBefore = (std::lower_bound(sorted.begin(), sorted.begin() + boundsIndexes[i], pairComplements[insertionOrder[i] - 2]));
		// std::vector<int>::iterator insertingBefore = (std::lower_bound(sorted.begin(), sorted.end(), pairComplements[insertionOrder[i] - 2]));
		
		// int insertIndex = vecBinarySearch(sorted, sorted.front(), sorted.back(), pairComplements[insertionOrder[i] - 2]);
		// std::vector<int>::iterator insertBefore = sorted.begin() + insertIndex;
		
		sorted.insert(insertingBefore, pairComplements[insertionOrder[i] - 2]);
		int insertIndex = insertingBefore - sorted.begin();
		// std::cout << "Vector : elem : " << pairComplements[insertionOrder[i] - 2] << ", insertIndex = " << insertIndex << std::endl;
		for (int i = 0; i < (int)boundsIndexes.size(); i++)
		{
			if (boundsIndexes[i] >= insertIndex)
				boundsIndexes[i]++;
		}		
	}
}

void PmergeMe::vectorSort() {
	
	int m = _sequence.size() / 2;
	std::vector< std::vector<int> > pairs(m);

	// ------------- STEP 1
	// crée un tableau bidimensionnel regroupant les paires de (ai, bi)
	for (int i = 0, j = 0; i < m; i++, j+=2)
	{
		pairs[i].push_back(_sequence[j]);
		pairs[i].push_back(_sequence[j + 1]);
		std::sort(pairs[i].begin(), pairs[i].end()); 
	}
	
	// ------------- STEP 2 
	std::vector<int> sorted; // les (ai) triés
	std::vector<int> pairComplements; // les (bi), aux indices correspondants à ceux de leurs (ai) respectifs
	vecRecInsertSort(pairs, pairs.size());

	for (size_t i = 0; i < pairs.size(); i++)
	{
		sorted.push_back(pairs[i][1]);
		pairComplements.push_back(pairs[i][0]);
	}

	// attention au cas ou pairComplement est vide ! ca segfault pr l'instant
	sorted.insert(sorted.begin(), pairComplements.front()); 
	pairComplements.erase(pairComplements.begin());
	// rajoute dans la liste des bi le potentiel élément non apparié de la liste de départ (ie si la taille de la liste était impaire)
	if (_sequence.size() % 2)
		pairComplements.push_back(_sequence.back());

	// Determines the insertion order
	std::vector<int> insertionOrder;
	std::vector<int> boundsIndexes;
	vecInsertionOrder(insertionOrder, boundsIndexes, _sequence.size(), sorted.size());

	// ------------- STEP 3
	vecBinaryInsertion(sorted, pairComplements, insertionOrder, boundsIndexes);
	_sequence = sorted;
}






// ----------------- DEQUE ---------------------

// faire une fonction template ?
void dequeInsertionOrder(std::deque<int> &insertionOrder, std::deque<int> &boundsIndexes,
	size_t sequenceSize, size_t currDequeSize)
{
	size_t tk = 1;
	size_t prev_tk = 1;
	int isOdd = (sequenceSize % 2);
	
	for (size_t k = 2; tk < currDequeSize + isOdd; k++)
	{
			prev_tk = tk;
			tk = (pow(2, k + 1) + pow(-1, k)) / 3;
			for (size_t t = (tk < currDequeSize + isOdd) ? tk : currDequeSize -1 + isOdd ; t > prev_tk; t--)
				insertionOrder.push_back(t);	
	}
	for (size_t i = 0; i < insertionOrder.size(); i++)
		boundsIndexes.push_back(insertionOrder[i]);
}


void dequeBinaryInsertion(std::deque<int> &main, std::deque<int> &pending,
	std::deque<int> &insertionOrder, std::deque<int> &boundsIndexes)
{
	int addedCount = 0;
	
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		std::deque<int>::iterator insertingBefore;
		if (boundsIndexes[i] + addedCount >= main.size())
			insertingBefore = (std::lower_bound(main.begin(), main.end(), pending[insertionOrder[i] - 2]));
		else
			insertingBefore = (std::lower_bound(main.begin(), main.begin() + boundsIndexes[i] + addedCount, pending[insertionOrder[i] - 2]));
		// std::deque<int>::iterator insertingBefore = (std::lower_bound(main.begin(), main.end(), pending[insertionOrder[i] - 2]));
		
		// int insertIndex = vecBinarySearch(main, main.front(), main.back(), pending[insertionOrder[i] - 2]);
		// std::vector<int>::iterator insertBefore = main.begin() + insertIndex;
		
		main.insert(insertingBefore, pending[insertionOrder[i] - 2]);
		addedCount++;

		/* int insertIndex = insertingBefore - main.begin();
		// std::cout << "Vector : elem : " << pending[insertionOrder[i] - 2] << ", insertIndex = " << insertIndex << std::endl;
		for (int i = 0; i < (int)boundsIndexes.size(); i++)
		{
			if (boundsIndexes[i] >= insertIndex)
				boundsIndexes[i]++;
		}		 */
	}
}

void dequeRecInsertSort(std::deque< std::deque<int> > &pairs, size_t size)
{
	if (size <= 1)
		return ;
	
	dequeRecInsertSort(pairs, size - 1);

	int last = pairs[size - 1][1];
	int lastComplement = pairs[size - 1][0];
	int j = size - 2;

	for (; j >= 0 && pairs[j][1] > last; j--)
	{
		pairs[j + 1][1] = pairs[j][1];
		pairs[j + 1][0] = pairs[j][0];
	}
	pairs[j + 1][1] = last;
	pairs[j + 1][0] = lastComplement;
}

void PmergeMe::dequeSort()
{
	int pairsCount = _dequeSequence.size() / 2;
	if (!pairsCount)
		return ;
	bool isOdd = (_dequeSequence.size() % 2);
	
	std::deque< std::deque<int> > pairs(pairsCount);

		for (int i = 0, j = 0; i < pairsCount; i++, j+=2)
	{
		pairs[i].push_back(_dequeSequence[j]);
		pairs[i].push_back(_dequeSequence[j + 1]);
		std::sort(pairs[i].begin(), pairs[i].end()); 
	}

	// ------------- STEP 2 
	std::deque<int> mainChain;
	std::deque<int> pending;
	dequeRecInsertSort(pairs, pairs.size());
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i][1]);
		pending.push_back(pairs[i][0]);
	}
	
	mainChain.push_front(pending.front());
	pending.pop_front();
	
	if (isOdd)
		pending.push_back(_dequeSequence.back());

	/* std::cout << " main chain : ";
	for (size_t i = 0; i < mainChain.size(); i++)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;

	std::cout << " pending : ";
	for (size_t i = 0; i < pending.size(); i++)
		std::cout << pending[i] << " ";
	std::cout << std::endl; */
	
	std::deque<int> insertionOrder;
	std::deque<int> boundsIndexes;
	dequeInsertionOrder(insertionOrder, boundsIndexes, _dequeSequence.size(), mainChain.size());

	
	dequeBinaryInsertion(mainChain, pending, insertionOrder, boundsIndexes);
	_dequeSequence = mainChain; 
	
}

















// ---------------- LIST --------------

// retourne un itérateur provenant du déplacement de it de *steps*, sans modifier it
std::list<int>::iterator getMovedIterator(std::list<int>::iterator it, int steps)
{
	std::list<int>::iterator itt = it;
	std::advance(itt, steps);
	return (itt);
}

// returns a list iterator to the n-th list element
std::list<int>::iterator getSteppedIterator(std::list<int> list, int steps)
{
	std::list<int>::iterator it = list.begin();
	std::advance(it, steps);
	return (it);
}

int getValueAtIndex(std::list<int> list, int index)
{
	if (index >= list.size())
		; // ?
	std::list<int>::iterator it = list.begin();
	std::advance(it, index);
	return *it;
}

void listRecInsertSort(std::list<int> &smallest, std::list<int> &largest, int size)
{
	if (size <= 1)
		return ;
	
	listRecInsertSort(smallest, largest, size - 1);

	int last = getValueAtIndex(largest, size - 1);
	int lastComplement = getValueAtIndex(smallest, size - 1);

	// std::list<int>::iterator itComplement = getItAtIndex(smallest, size - 2);
	// std::list<int>::iterator it = getItAtIndex(largest, size - 2);
	// std::cout << " *it = " << *it << ", *itComplement = " << *itComplement << std::endl;
	
	std::list<int>::iterator pos = largest.begin();
	std::advance(pos, size - 2);
	std::list<int>::iterator posComp = smallest.begin();
	std::advance(posComp, size - 2);

	int j = size - 2;

	// parse tous les elements, commençant à partir de celui précédant l'élément à insérer, jusqu'au premier
	while (j >= 0 && *pos > last) //(pos != largest.begin() && *pos > last)
	{
		// décale vers la droite : la valeur de l'élément à la position 'pos' devient celle de l'élément à la position 'pos + 1'
		
		std::list<int>::iterator next = pos;
		std::list<int>::iterator nextComp = posComp;
		next++;
		nextComp++;
		
		*next = *pos;
		*nextComp = *posComp;
		if (pos == largest.begin())
		{
			*pos = last;
			*posComp = lastComplement;
		}
		pos--;
		posComp--;
		j--;
	}
	std::list<int>::iterator next = pos;
	std::list<int>::iterator nextComp = posComp;
	next++;
	nextComp++;

	*next = last;
	*nextComp = lastComplement;	
}


void listInsertionOrder(std::list<int> &largest,
std::list<int> &insertionOrder, std::list<int> &boundsIndexes, size_t sequenceSize) {
	size_t tk = 1;
	size_t prev_tk = 1;
	int isOdd = (sequenceSize % 2);
	
	for (size_t k = 2; tk < largest.size() + isOdd; k++)
	{
			prev_tk = tk;
			tk = (pow(2, k + 1) + pow(-1, k)) / 3;
			// std::cout << "k = " << k << ", prev_tk = " << prev_tk << ", tk = " << tk << std::endl;
			for (size_t t = (tk < largest.size() + isOdd) ? tk : largest.size() -1 + isOdd ; t > prev_tk; t--)
				insertionOrder.push_back(t);	
	}

	for (std::list<int>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); it++)
		boundsIndexes.push_back(*it);
}

void listBinaryInsertion(std::list<int> &largest, std::list<int> &smallest,
std::list<int> &insertionOrder, std::list<int> &boundsIndexes)
{
	for (std::list<int>::iterator it = insertionOrder.begin(), it_bounds = boundsIndexes.begin() ; it != insertionOrder.end(); it++, it_bounds++)
	{

		/* // code test
		std::list<int>::iterator insertingBefore = std::lower_bound(largest.begin(), largest.end(), *(getMovedIterator(smallest.begin(), *it - 2)));
		largest.insert(insertingBefore, *(getMovedIterator(smallest.begin(), *it - 2))); */


		size_t valueToInsert = *(getMovedIterator(smallest.begin(), *it - 2));
		size_t upperBoundValue = *getMovedIterator(largest.begin(), *it_bounds);
		
		std::list<int>::iterator insertingBefore;
		if (*it_bounds >= largest.size())
		{
			std::cout << "in \"if (*it_bounds >= largest.size())\", inserting in the whole list" << std::endl;
			insertingBefore = std::lower_bound(largest.begin(), largest.end(), valueToInsert);
		}
		else
			insertingBefore = std::lower_bound(largest.begin(), getMovedIterator(largest.begin(), *it_bounds), valueToInsert);
		
		std::cout << "elem a inserer : " << valueToInsert << ", index borne superieure = " << *it_bounds << ", borne supérieure = " << upperBoundValue << std::endl;

		/* // dans le cas ou lower_bound(first, last, value) retourne last, on verifie si l element est a inserer avant ou apres last
		if (insertingBefore == getMovedIterator(largest.begin(), *it_bounds) && valueToInsert > *getMovedIterator(largest.begin(), *it_bounds))
		{
			if (insertingBefore != largest.end())
			{
				insertingBefore++;
				insertingBefore++; // a supprimeeeeeeer
				std::cout << "=====coucou======" << std::endl;
			}
			std::cout << "LOLLLLLLL, elem a inserer : " << valueToInsert << ", borne supérieure = " << *getMovedIterator(largest.begin(), *it_bounds) << ", insertingBefore++ = " << *insertingBefore << ", insertingBefore + 2 = " << *getMovedIterator(insertingBefore, 1) << std::endl;
			
		} */
		
		largest.insert(insertingBefore, valueToInsert);
		// std::cout << "List : insertingBefore = " << *insertingBefore << std::endl;

		// int insertIndex = std::distance(largest.begin(), insertingBefore);
		int insertIndex = distInList(largest.begin(), insertingBefore);
		// std::cout << "List : elem : " << valueToInsert << ", insertIndex = " << insertIndex << std::endl;
		for (std::list<int>::iterator it = boundsIndexes.begin(); it != boundsIndexes.end(); it++)
		{
			// std::cout << "*it = " << *it << ", insertIndex = " << insertIndex << ", ";
			if (*it >= insertIndex)
				(*it)++;
		}
	}
}

void PmergeMe::listSort() {
	std::list<int> smallest;
	std::list<int> largest;

	int x = 0;
	int y = 0;

	for (std::list<int>::iterator it = _listSequence.begin(); it != _listSequence.end() && getMovedIterator(it, 1) != _listSequence.end(); it++)
	{
		x = *it;
		y = *(++it);
		x < y ? (smallest.push_back(x), largest.push_back(y)) : (smallest.push_back(y), largest.push_back(x));
	}

	// ------------- STEP 2 
	listRecInsertSort(smallest, largest, largest.size());
	
	largest.push_front(smallest.front());
	smallest.pop_front();
	if (_listSequence.size() % 2)
		smallest.push_back(_listSequence.back());

	std::list<int> insertionOrder;
	std::list<int> boundsIndexes;
	listInsertionOrder(largest, insertionOrder, boundsIndexes, _listSequence.size());

	// ------------- STEP 3
	listBinaryInsertion(largest, smallest, insertionOrder, boundsIndexes);
	_listSequence = largest;
}


