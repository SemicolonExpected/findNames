#ifndef QUADHASH_H
#define QUADHASH_H

#include <vector>
#include <math.h>

template<typename HashedObj>
class HashTable
{
    public:
        explicit HashTable(int size); //err are you sure I don't want to just use a constructor without size?
        
        bool contains(const HashedObj &x) const; //done
        
        void makeEmpty(); //done
        bool insert(const HashedObj &x);
        bool insert(const HashedObj &x, int akey); 
        bool remove(const HashedObj &x); 
        
        int findPos(const HashedObj &x) const; 
        
        enum EntryType{ACTIVE, EMPTY, DELETED};
        
        void updateVal(int x, int pos);
        
        int size() const{
            return array.size();
        }
        
        HashedObj operator[](int i) const{
            return array[i].element;
        }
    private:
        struct HashEntry
        {
            HashedObj element;  // uid
            int value;          // position I know this is backwards
            EntryType info;
            
            HashEntry(const HashedObj &e = HashedObj(), EntryType i = EMPTY):element{e},info{i}{}
        };
        
        std::vector<HashEntry> array;
        int currentSize;
        bool isActive(int currentPos) const; //done
        
        void rehash();
        size_t myhash(const HashedObj &x) const; //hash function =_=
        
        int nextPrime(int thisPrime);
        bool isPrime(int x);
};

template<typename HashedObj> 
void HashTable<HashedObj>::updateVal(int x, int pos)
{
    array[pos].value = x;
}
/*******************************
 * Prime
 * Arithmetics
 * I know I spelled that wrong
 * *****************************/
template<typename HashedObj> 
bool HashTable<HashedObj>::isPrime(int x){
    if(x%2 == 0)
        return false;
    for(int i = 3; i<sqrt(x); i+=2)
        if(x%i == 0)
            return false;
    return true;
}

template<typename HashedObj> 
int HashTable<HashedObj>::nextPrime(int thisPrime){
    int x = thisPrime;
    while(isPrime(x)==false)
        x++;
    return x;
}

//A constructor zzzzzzzzzzzz
template<typename HashedObj> HashTable<HashedObj>::HashTable(int size):array(nextPrime(size)){makeEmpty();}

//EMPTY THE PITS XXBBBB
template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    currentSize = 0;
    for(auto &entry:array)
        entry.info = EMPTY;
}

template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const
{
    return isActive(findPos(x));
}

template<typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
    return array[currentPos].info == ACTIVE;
}

/*****************************************
 * 
 * Where in the world is my hashed object?
 * 
 * ***************************************/
template<typename HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj &x) const
{
    int offset = 1;
    int currentPos = myhash(x);
    
    while(array[currentPos].info != EMPTY && array[currentPos].element != x)
    {
        currentPos+=offset;
        offset+=2;
        
        if(currentPos >= array.size())
            currentPos-=array.size();
    }
    
    return currentPos;
}
/******************************
 * 
 * LETS INSERT THINGS
 * ALL THE THINGS
 * 
 * ****************************/

template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x, int akey)
{
    int currentPos = findPos(x);
    if(isActive(currentPos))
        return false; //if the element is already there or empty then return false
    
    array[currentPos].element = x;
    array[currentPos].info = ACTIVE;
    array[currentPos].value = akey;
    
    if(++currentSize > array.size()/2)
        rehash();
        
    return true;
}

template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x)
{
    int currentPos = findPos(x);
    if(isActive(currentPos))
        return false; //if the element is already there or empty then return false
    
    array[currentPos].element = x;
    array[currentPos].info = ACTIVE;
    
    if(++currentSize > array.size()/2)
        rehash();
        
    return true;
}

template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x)
{
    int currentPos = findPos(x);
    if(!isActive(currentPos))
        return false; //if cannot be deleted because already is deleted return false
    
    array[currentPos].info = DELETED;
    return true;
}

//Hashy things
template<typename HashedObj>
void HashTable<HashedObj>::rehash()
{
    std::vector<HashTable<HashedObj>::HashEntry> oldArray = array;
    
    array.resize(nextPrime(2*oldArray.size()));
    
    for(auto &entry:array)
        entry.info = EMPTY;
        
    currentSize = 0;
    
    for(auto &entry:oldArray)
        if(entry.info == ACTIVE)
            insert(std::move(entry.element));
}

template<typename HashedObj>
size_t HashTable<HashedObj>::myhash(const HashedObj &x) const
{
    int ans = x % array.size();
    return ans; //I couldn't think of a function
}


#endif
