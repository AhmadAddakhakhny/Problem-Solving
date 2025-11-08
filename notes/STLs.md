# STLs

## Vector:
> It is implemented as a dynamic array (contiguous memory block).

```C++
    // Declare a vector
    vector <int> myVector; // O(1)

    // Declare with a specific size
    vector <int> myVector(7); // O(n)

    // Declare iwth initial values
    vector <int> myVector = {5, 2, 8, 1};  // O(n)

    // append
    myVector.push_back(5); // O(1), Occasional reallocation → O(n) in that rare case.

    // remove from end
    myVector.pop_back(); // O(n)

    // size of a vector
    myVector.size(); // O(1)

    // access
    myVector[5]; // O(1)

    // is empty
    myVector.empty(); // O(1)

    // access first element
    myVector.front(); // O(1)

    // acess last element
    myVector.back(); // O(1)

    // clear a vector
    myVector.clear();  // O(n)

    // iterator for the first element
    myVector.begin();  // O(1)

    // iterator for the after last element
    myVector.end(); // O(1)

    // those iterators are mainly for manipulating with functions
    sort(myVector.begin(), myVector.end());  // O(n log n)

    // normal for-loop with index
    for(int i=0; i<myVector.size(); i++) {} // O(n)

    // range based for-loop
    for(int val : myVector) {} // O(n)
```

## Queue:
> It is a container adaptor providing FIFO (first-in-first-out) access.
```C++
    // Decleare
    queue <int> myQueue; // O(1)

    // Enqueue
    myQueue.push(5); // O(1)

    // Dequeue
    myQueue.pop(); // O(1)

    // Access the first element
    myQueue.front(); // O(1)

    // Acess the last element
    myQueue.back(); // O(1)

    // size
    myQueue.size(); // O(1)

    // is empty
    myQueue.empty(); // O(1)
```

## Stack:
> It is a container adaptor providing LIFO (last-in-first-out) access.
```C++
    // Decleare
    stack <int> myStack; // O(1)

    // Enqueue
    myStack.push(5); // O(1)

    // Dequeue
    myStack.pop(); // O(1)

    // Access the first element
    myStack.top(); // O(1)

    // size
    myStack.size(); // O(1)

    // is empty
    myStack.empty(); // O(1)
```

## Deque:
> It’s a Double-Ended Queue that provide the same
functionality as vectors in addition to insertion and deletion
from the beginning
```C++
    // Decleare
    deque <int> myDeque; // O(1)

    // Enqueue
    myDeque.push_front(5); // O(1)

    // Dequeue
    myDeque.pop_front(); // O(1)
```
---

## Priority Queue
A container for elements based on binary heap with three main operations:  
> 1 .Insert/push an element  
> 2. Get the element with the highest priority  
> 3. Remove the element with the highest priority  
```C++
    // Declare a pq
    priority_queue<int> mypq;  // O(1)

    // size
    mypq.size();  // O(1)

    // is empty
    mypq.empty();  // O(1)

    // push into pq
    mypq.push(5);  // O(log n)

    // Get highest priority
    mypq.top();  // O(1)

    // pop/remove the highest priority element
    mypq.pop();  // O(log n)

    // Nice trick with numbers to make it smallest priority:
    mypq.push(-5) ;
    -mypq.top();

    //Nice trick with any data type to make it smallest priority:
    priority_queue<int, vector<int>, greater<int>> mypq;
```

## Set
A container for elements with two main operations:  
> set => sorted, unique, logarithmic access time, based on red-black tree  
> unordered_set => unsorted, unique, constant access time, based on hash table
```C++
    // Declare
    // set => O(1)
    // unordered_set => O(1)
    set<int> mySet;

    // size 
    // set => O(1)
    // unordered_set => O(1)
    mySet.size();

    // is empty
    // set => O(1)
    // unordered_set => O(1)
    mySet.empty();

    // insert
    // set => O(log n)
    // unordered_set => O(1)
    mySet.insert(5);

    // erase
    // set => O(log n)
    // unordered_set => O(1)
    mySet.erase(7);

    // count no. of instances for a value
    // set => O(log n)
    // unordered_set => O(1)
    mySet.count(2); 

    // Check if a value exists
    // set => O(log n)
    // unordered_set => O(1)
    mySet.find(5) != mySet.end();
    mySet.count(5) != 0

    // traverse
    for(auto it : mySet) {}
```

## Map
A container for key/value elements  
> map => sorted, unique, logarithmic access time, based on red-black tree    
> unordered_map => unsorted, unique, constant access time, based on hash table
```C++
    // Declare a map
    // map => O(log n)
    // unordered_map => O(1)
    map <string,int> myMap ;

    // Size
    // map => O(log n)
    // unordered_map => O(1)
    myMap.size() ;

    // is empty
    // map => O(log n)
    // unordered_map => O(1)
    myMap.empty() ;

    // Insert a key/value element in a map
    // map => O(log n)
    // unordered_map => O(1)
    myMap.insert({“Ahmed”,5}) ;

    // Insert/access/change a key/value element in non-multi maps
    // map => O(log n)
    // unordered_map => O(1)
    myMap[“Ahmed”]=6 ;

    // Remove all instances of a key
    // map => O(log n)
    // unordered_map => O(1)
    mySet.erase(“Ahmed”) ;

    // Count the number of instances for a key
    // map => O(log n)
    // unordered_map => O(1)
    myMap.count(“Ahmed”) ;

    // Check if a key exists
    // map => O(log n)
    // unordered_map => O(1)
    myMap.find(“Ahmed”)!=myMap.end() ;
    myMap.count(“Ahmed”)!=0

    // Traverse
    for(auto keyValuePair : myMap){}
```
