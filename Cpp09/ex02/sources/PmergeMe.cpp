/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:49:50 by Helene            #+#    #+#             */
/*   Updated: 2024/05/12 01:33:39 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::cout << "PmergeMe: Default constructor" << std::endl;
	
	
	for (int i = 1; i <argc; i++)
	{
		_sequence.push_back(atoi(argv[i]));
		_listSequence.push_back(atoi(argv[i]));
		// std::cout << argv[i] << " ";
	}
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

void PmergeMe::vectorSort() {
	
	int m = _sequence.size() / 2;
	std::vector< std::vector<int> > pairs(m);

	// ------------- STEP 1
	// crée un tableau bidimensionnel regroupant les paires de (ai, bi)
	for (int i = 0, j = 0; i < m; i++, j+=2)
	{
		pairs[i].push_back(_sequence[j]);
		pairs[i].push_back(_sequence[j + 1]);
		// vérifier que ca trie bien par ordre croissant 
		std::sort(pairs[i].begin(), pairs[i].end()); 
	}

	// std::cout << "Initial (ai, bi) pairs : " << std::endl;
	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << "( ";
	// 	for (size_t j = 0; j < pairs[i].size(); j++)
	// 		std::cout << pairs[i][j] << " ";
	// 	std::cout << ") ";
	// }
	// std::cout << std::endl << std::endl;
	
	

	
	// ------------- STEP 2 
	std::vector<int> sorted; // les (ai) triés
	std::vector<int> pairComplements; // les (bi), aux indices correspondants à ceux de leurs (ai) respectifs
	bool stopSearch = false;
	
	// pour le tri récursif par insertion : créer une fonction template pour vector et list ?

	for (size_t i = 0; i < pairs.size(); i++)
	{
		stopSearch = false;

		int jsp = 0;
		
		for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end() && stopSearch == false; it++, jsp++)
		{
			// std::cout << "*it = " << *it << ", sorted.begin() = " << *(sorted.begin()) << std::endl;
			if (pairs[i][1] < *it)
			{
				stopSearch = true;
				sorted.insert(it, pairs[i][1]);
				
				// std::cout << "attention ca va peter" << std::endl;
				// std::cout << "avant ça : ";
				// std::cout << "*it = " << *it << ", sorted.begin() = " << *(sorted.begin()) << std::endl;
				// std::cout << "distance = " << std::distance(sorted.begin(), it) << std::endl;
				
				
				// modifie en conséquence l'indice du bi correspondant 
				// std::cout << "index : " << std::distance(sorted.begin(), it) << std::endl;
				pairComplements.insert(pairComplements.begin() + jsp, pairs[i][0]);
				// pairComplements.insert(pairComplements.begin() + 
				// 	std::distance(sorted.begin(), it), pairs[i][0]);
				
				// std::cout << "ah non en fait" << std::endl;
			}
		}

		// std::cout << "LKJHFELKJHFKELJHFK" << std::endl;
			
		if (!stopSearch)
		{
			sorted.push_back(pairs[i][1]);
			pairComplements.push_back(pairs[i][0]);
		}
		
		// std::cout << "sorted ( i = "<< i << ") : ( ";
		// for (size_t j = 0; j < sorted.size(); j++)
		// 	std::cout << sorted[j] << " ";
		// std::cout << ")" << std::endl << std::endl;
		
	}


	// std::cout << std::endl << "in-sorting-process vector : ( ";
	// for (size_t i = 0; i < sorted.size(); i++)
	// 	std::cout << sorted[i] << " ";
	// std::cout << ")" << std::endl;

	// std::cout << "pairsComplements : ( ";
	// for (size_t i = 0; i < pairComplements.size(); i++)
	// 	std::cout << pairComplements[i] << " ";
	// std::cout << ")" << std::endl;

	// attention au cas ou pairComplement est vide ! ca segfault pr l'instant
	sorted.insert(sorted.begin(), pairComplements.front()); 
	pairComplements.erase(pairComplements.begin());
	
	// rajoute dans la liste des bi le potentiel élément non apparié de la liste de départ (ie si la taille de la liste était impaire)
	if (_sequence.size() % 2)
		pairComplements.push_back(_sequence.back());
	
	// std::cout << "pairsComplements after deleting front() and adding potential non-paired value: ( ";
	// for (size_t i = 0; i < pairComplements.size(); i++)
	// 	std::cout << pairComplements[i] << " ";
	// std::cout << ")" << std::endl;


	// Determines the insertion order
	std::vector<int> insertionOrder;
	size_t tk = 1;
	size_t prev_tk = 1;
	int isOdd = (_sequence.size() % 2);
	
	for (size_t k = 2; tk < sorted.size() + isOdd; k++)
	{
			prev_tk = tk;
			tk = (pow(2, k + 1) + pow(-1, k)) / 3;
			// std::cout << "k = " << k << ", prev_tk = " << prev_tk << ", tk = " << tk << std::endl;
			for (size_t t = (tk < sorted.size() + isOdd) ? tk : sorted.size() -1 + isOdd ; t > prev_tk; t--)
				insertionOrder.push_back(t);	
	}


	// ------------- STEP 3


	// std::cout << std::endl << "-------- Step 3, initial state : " << std::endl;
	// std::cout << "sorted : ( ";
	// for (size_t j = 0; j < sorted.size(); j++)
	// 	std::cout << sorted[j] << " ";
	// std::cout << ")" << std::endl;
	// std::cout << std::endl << "To be inserted : ";
	// for (size_t i = 0; i < pairComplements.size(); i++)
	// 	std::cout << pairComplements[i] << " ";
	// std::cout << std::endl;
	// std::cout << std::endl << "Insertion order : ";
	// for (size_t i = 0; i < insertionOrder.size(); i++)
	// 	std::cout << insertionOrder[i] << " ";
	// std::cout << std::endl << std::endl;
	

	
	// depuis begin() up to xi not included
	// et on s'interesse, pour un yi, a bj avec j = i - 2
	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		// insertionOrder[i] va nous donner l'index de la paire d'éléments à insérer 
		// std::cout << "Step 3 : orderedPairComplements to be inserted : " << pairComplements[insertionOrder[i] - 2] << std::endl;
		sorted.insert(std::lower_bound(sorted.begin(), sorted.begin() + insertionOrder[i], pairComplements[insertionOrder[i] - 2]), pairComplements[insertionOrder[i] - 2]);
	}
	
	std::cout << std::endl << "After Pmerge sort : ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
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

void PmergeMe::listSort() {
	
	// int m = _listSequence.size() / 2;
	// bool isOdd = _listSequence.size() % 2;
	
	
	std::list<int> smallest;
	std::list<int> largest;

	int x = 0;
	int y = 0;

	
	for (std::list<int>::iterator it = _listSequence.begin(); it != _listSequence.end() && getMovedIterator(it, 1) != _listSequence.end(); it++)
	{
		// pairs[i].push_back(_sequence[j]);
		// pairs[i].push_back(_sequence[j + 1]);
		// std::sort(pairs[i].begin(), pairs[i].end()); 
		// std::cout << "coucou" << std::endl;
		x = *it;
		y = *(++it);
		x < y ? (smallest.push_back(x), largest.push_back(y)) : (smallest.push_back(y), largest.push_back(x));
	}

	// std::cout << "After creating two sub-lists : " << std::endl;
	// std::cout << "smallest list : " ;
	// for (std::list<int>::iterator it = smallest.begin(); it != smallest.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "largest list : " ;
	// for (std::list<int>::iterator it = largest.begin(); it != largest.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;







	// ------------- STEP 2 

	bool stopSearch = false;
	
	for (size_t i = 0; i < largest.size(); i++)
	{
		std::list<int>::iterator it = getMovedIterator(largest.begin(), i);
		
		stopSearch = false;
		// std::cout << "smallest list : " ;
		// for (std::list<int>::iterator it = smallest.begin(); it != smallest.end(); it++)
		// 	std::cout << *it << " ";
		// std::cout << std::endl;
		// std::cout << "largest list : " ;
		// for (std::list<int>::iterator it = largest.begin(); it != largest.end(); it++)
		// 	std::cout << *it << " ";
		// std::cout << std::endl;
		// std::cout << "element a inserer = " << *it << std::endl;
		
		for (std::list<int>::iterator it_sublist = largest.begin(); it_sublist != it && stopSearch == false; it_sublist++)
		{
			
			// std::cout << "*it_sublist = " << *it_sublist << ", *it = " << *it << std::endl;
			if (*it_sublist > *it)
			{
				stopSearch = true;
				std::list<int>::iterator it_equivalent = getMovedIterator(smallest.begin(), std::distance(largest.begin(), it));
				if (it_sublist == largest.begin())
				{
					int x = *it, y = *it_equivalent;
					largest.erase(it);
					largest.push_front(x);
					smallest.erase(it_equivalent);
					smallest.push_front(y);
				}
				else
				{
					// std::cout << "*it_equivalent = " << *it_equivalent << std::endl;
					// std::cout << "associated index = " << std::distance(largest.begin(), it_sublist) << std::endl;
					
					// std::move(it_equivalent, it_equivalent, 
					// getMovedIterator(smallest.begin(), std::distance(largest.begin(), it_sublist) - 1));
					smallest.splice(getMovedIterator(smallest.begin(), std::distance(largest.begin(), it_sublist)), smallest, it_equivalent);
					
					largest.splice(it_sublist, largest, it);
					std::move(it, it, it_sublist);
				}
			}
		}
		// std::cout << std::endl;
	}

	// std::cout << "smallest list : " ;
	// for (std::list<int>::iterator it = smallest.begin(); it != smallest.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "largest list : " ;
	// for (std::list<int>::iterator it = largest.begin(); it != largest.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	largest.push_front(smallest.front());
	smallest.pop_front();

	if (_listSequence.size() % 2)
		smallest.push_back(_listSequence.back());
	
	std::cout << std::endl << "After sorting one and rearranging the other : " << std::endl;
	std::cout << "smallest list : " ;
	for (std::list<int>::iterator it = smallest.begin(); it != smallest.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "largest list : " ;
	for (std::list<int>::iterator it = largest.begin(); it != largest.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;


	// Determines the insertion order
	std::list<int> insertionOrder;
	size_t tk = 1;
	size_t prev_tk = 1;
	int isOdd = (_sequence.size() % 2);
	
	for (size_t k = 2; tk < largest.size() + isOdd; k++)
	{
			prev_tk = tk;
			tk = (pow(2, k + 1) + pow(-1, k)) / 3;
			// std::cout << "k = " << k << ", prev_tk = " << prev_tk << ", tk = " << tk << std::endl;
			for (size_t t = (tk < largest.size() + isOdd) ? tk : largest.size() -1 + isOdd ; t > prev_tk; t--)
				insertionOrder.push_back(t);	
	}



	// ------------- STEP 3
	
	// depuis begin() up to xi not included
	// et on s'interesse, pour un yi, a bj avec j = i - 2
	
	// for (size_t i = 0; i < insertionOrder.size(); i++)
	// {
		// insertionOrder[i] va nous donner l'index de la paire d'éléments à insérer 
		// std::cout << "Step 3 : orderedPairComplements to be inserted : " << pairComplements[insertionOrder[i] - 2] << std::endl;
		// sorted.insert(std::lower_bound(sorted.begin(), sorted.begin() + insertionOrder[i], pairComplements[insertionOrder[i] - 2]), pairComplements[insertionOrder[i] - 2]);
	// }
	for (std::list<int>::iterator it = insertionOrder.begin(); it != insertionOrder.end(); it++)
	{
		largest.insert(std::lower_bound(largest.begin(), getMovedIterator(largest.begin(), *it), *(getMovedIterator(smallest.begin(), *it - 2))), *(getMovedIterator(smallest.begin(), *it - 2)));
	}
	
	
	
	std::cout << std::endl << "After Pmerge sort : ";
	for (std::list<int>::iterator it = largest.begin(); it != largest.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
}
