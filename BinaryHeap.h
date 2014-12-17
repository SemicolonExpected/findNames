#ifndef BINARYHEAP_H 
#define BINARYHEAP_H

#include <vector>
#include <utility>
#include <iostream>

template<typename Datatype>
class BinaryHeap
{
    public:
        //explicit BinaryHeap(int capacity = 100);
        explicit BinaryHeap(const std::vector<Datatype> &items);
        
        bool isEmpty() const;
        void makeEmpty();
        
        const Datatype &findMin() const;
        
        void insert(const Datatype &x);
        void deleteMin();
        void deleteMin(Datatype &minItem); //the one to use
        
        //void decreaseKey(Datatype item, int delta);
        //void increaseKey(Datatype item, int delta);
        void decreaseKey(int pos, int delta);
        void increaseKey(int pos, int delta);
        void remove(Datatype item);
        
        Datatype getItem(int pos){
            return array[pos];
        }
        void getItems(std::vector<Datatype> &items);
        
    private:
        long unsigned int currentSize;
        std::vector<Datatype> array;
        
        void buildHeap();
        void percolateDown(int hole);
};

template<typename Datatype> void BinaryHeap<Datatype>::getItems(std::vector<Datatype> &items)
{
    items = array;
}

/**********************************
 *************Construct ***********
 **********************************/
template<typename Datatype>
/*explicit */BinaryHeap<Datatype>::BinaryHeap(const std::vector<Datatype> &items):
    array(items.size()+1), currentSize{items.size()}
{
    for(int i = 0; i<items.size(); i++)
        array[i+1] = items[i];
    buildHeap();
}

/**********************************
 ************The Empties***********
 **********************************/
template<typename Datatype>
bool BinaryHeap<Datatype>::isEmpty() const
{
    if(array.size()<2)
        return true;
    else
        return false;
}

template<typename Datatype>
void BinaryHeap<Datatype>::makeEmpty()
{
    while(!isEmpty())
    {
        deleteMin();
    }
    array.clear();
}

/**********************************
 ************The Min Min***********
 **********************************/
template<typename Datatype>
const Datatype &BinaryHeap<Datatype>::findMin() const //this looks so weird
{
    return array[1];
}

/**********************************
 ************  Ins|Del  ***********
 **********************************/
 template<typename Datatype>
 void BinaryHeap<Datatype>::insert(const Datatype &x)
 {
    if(currentSize == array.size() - 1)
        array.resize(array.size()*2);
        
    int hole = ++currentSize;
    Datatype copy = x;
    
    array[0] = std::move(copy);
    
    while(x < array[hole/2] && hole!= 1)
    {
        array[hole] = std::move(array[hole/2]);
        hole/=2;
    }
    array[hole] = std::move(array[0]);
    
 }

//Delete Mins 
 template<typename Datatype>
 void BinaryHeap<Datatype>::deleteMin()
 {
    if(isEmpty())
        //throw UnderflowException();
        std::cout<<"Delete failed:Heap is empty."<<std::endl;
    
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
 }
 
 template<typename Datatype>
 void BinaryHeap<Datatype>::deleteMin(Datatype &minItem)
 {
    if(isEmpty())
        std::cout<<"Delete failed:Heap is empty"<<std::endl;
        
    minItem = std::move(array[1]);
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
 }
 
 /**********************************
  ************  Private  ***********
  **********************************/
 template<typename Datatype>
 void BinaryHeap<Datatype>::buildHeap()
 {
    for(int i = currentSize/2; i>0; --i)
        percolateDown(i);
 }
 
 template <typename Datatype>
 void BinaryHeap<Datatype>::percolateDown(int hole)
 {
    int child;
    Datatype tmp = std::move(array[hole]);
    
    while(hole*2<= currentSize)
    {
        child =  hole*2;
        if(child != currentSize && array[child + 1] < array[child])
            ++child;
        if(array[child]<tmp)
            array[hole] = std::move(array[child]);
        else
        {
            hole = child;
            break;
        }
        hole = child;
    }
 }
/***************
 * Inc/Dec Key *
 ***************/ 
template<typename Datatype>
void BinaryHeap<Datatype>::decreaseKey(int pos, int delta){
    while(delta!=0 && (pos-1)>0)
    {
        std::swap(array[pos],array[pos-1]);
        pos--;
        delta--;
    }
}

template<typename Datatype>
void BinaryHeap<Datatype>::increaseKey(int pos, int delta){
    while(delta!=0 && (pos-1)<array.size())
    {
        std::swap(array[pos],array[pos+1]);
        pos++;
        delta--;
    }
}

template<typename Datatype>
void BinaryHeap<Datatype>::remove(Datatype item){
    for(int i = 1; i<array.size(); i++)
    {
        if(array[i] == item)
        {
            decreaseKey(i,100000);//TODO: USE LIMITS LIB
	        deleteMin();
            break;
        }
        
    }
}

#endif
