#pragma once
#include <stdexcept>
#include "TreeVisitor.h"
template<class T, int N>
class NTree
{
private:
	const T* fKey; // 0 for empty NTree
	NTree<T, N>* fNodes[N]; // N subtrees of degree N
	NTree(); // sentinel constructor
public:
	static NTree<T, N> NIL; // sentinel
	NTree(const T& aKey); // a simple NTree with key and N subtrees


	bool isEmpty() const; // is tree empty
	const T& key() const; // get key (node value)
						  // indexer (allow for result modification by client - no const in result)
	NTree& operator[](unsigned int aIndex) const;
	// tree manipulators (using constant references)
	void attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree); // attach a new subtree
	const NTree& detachNTree(unsigned int aIndex);

	// depth-first traversal
	void traverseDepthFirst(const TreeVisitor<T>& aVisitor) const; //lslide 337 for this 
	// copy control
	NTree(const NTree& aOtherNTree);
	~NTree();
	NTree& operator=(const NTree& aOtherNTree);

	// breadth-first traversal
	void traverseBreadthFirst(const TreeVisitor<T>& aVisitor) const;
};
//implementation of PS7
template<class T, int N>
NTree<T, N>::NTree(const T& aKey) // not sure about the constructor
{

}
template<class T, int N>
NTree<T, N>::~NTree() // may be missing the :(fKey)
{
	for (int i = 0; i < N; i++) // n is our degree of the tree
	{
		if (fNodes[i] != &NIL) // if they are populated we delete them else we leave them
			delete fNodes[i]; //slide 314
	}
}
template<class T, int N>
NTree& NTree<T, N>::operator[](unsigned int aIndex) const
{

}
template<class T, int N>
bool NTree<T, N>::isEmpty() const
{
	return this == &NIL;
}
template <class T, int N>
const T& NTree<T, N>::key() const // we check if it is empty  first and out of bounds (this is our get key function)
{
	if (isEmpty())
	{
		throw std::domain_error("Empty NTree!");
	}
	return *fKey;
}
template<class T, int N>
void NTree<T, N>::attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree) // find out what aIndex is and why we say 0> and < n
{
	if (isEmpty())
	{
		throw std::domain_error("Empty NTree!");
	}
	if ((aIndex >= 0) && (aindex < N)) // within parametres
	{
		if (fNodes[aIndex] != &NIL) // Checking it is not null
		{
			throw std::domain_error("Non-Empty subtree present!");

			return[aIndex] = aNTree; // why?
		}
		else
			throw std::out_of_range("Illegal subtree index!");
	}
}
template<class T, int N>
const NTree& NTree<T, N>::detachNTree(unsigned int aIndex)
{
	if (isEmpty())
	{
		throw std::domain_error("Empty NTree!";)
	}
	if ((aIndex >= 0) && (aIndex < N))
	{
		NTree<T, N>* Result = fNode[aIndex]; // ??? make an instance...
		fNodes[aIndex] = &NIL;
		return Result; // this is a subtree
	}
	else
		throw std::out_of_bounds("Illegal subtree index!");
}
template<class T, int N>
void NTree<T, N>::traverseDepthFirst(const TreeVisitor<T>& aVisitor) const
{
	if (!isEmpty())
	{
		aVisitor.preVisit(key());
		left().traverseDepthFirst(aVisitor);
		aVisitor.inVisit(key());
		right().traversalDepthFirst(aVisitor);
		aVisitor.postVisit(key());
	}
}
template<class T, int N>
void NTree<T, N>::traverseBreadthFirst(const TreeVisitor<T>& aVisitor) const
{
	DynamicQueue <const bTree<T>* > lQueue;
	if (!isEmpty())
	{
		lQueue.enqueue(this);
	}
	while (!lQueue.isEmpty())
	{
		const BTreee<T>& head = *lQueue.top();
		lQueue.dequeue();

		if (!head.isEmpty())
		{
			aVisitor.visit(head.key());
		}
		if (!head.left().isEmpty())
		{
			lQueue.enqueue(&head.left());
		}
		if (!head.right().isEmpty())
		{
			lQueue.enqueue(&head.right());
		}
	}
}