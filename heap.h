#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  void print()const;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void trickleUp(std::size_t index);
  void trickleDown(std::size_t index);

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m_ary;
  PComparator c_m;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  m_ary = m;
  c_m = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

//DELETE LATER
/*
template<typename T, typename PComparator>
void Heap<T,PComparator>::print()const
{
  for(unsigned int i = 0; i < data.size(); i++){
      std::cout << data[i] << " ";

  }
  std::cout << std::endl;
}
*/

template<typename T, typename PComparator>
bool Heap<T,PComparator>::empty()const{
  return data.empty();
}

template<typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("Heap is Empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //print();
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("Heap is Empty");

  }
  //grab the root node and pop it out
  std::size_t index = data.size()-1;
  std::swap(data[0],data[index]);
  data.pop_back();

  //resort the misplaced node
  trickleDown(0);
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  //put the new item at the bottom
  data.push_back(item);
  std::size_t index = data.size()-1;
  //resort the heap
  trickleUp(index);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(std::size_t index){
  std::size_t child = (index*m_ary) + 1;
  //if the node is already correct, don't change anything
  if(child>=data.size()){
    return;
  }
  //new variable to hold the "best" child
  std::size_t bestChild = child;
  for(int i = 1; i < m_ary; i++){ //loop through all children
    if((child + i < data.size()) && (c_m(data[child+i], data[bestChild]))){ //compare the current best child to the next child
      bestChild = child+i; //make next child best child if better than current bestchild
    }
  }
  if(c_m(data[bestChild], data[index])){ //compare the bestchild to the index we wanna check, swap if child is better
    std::swap(data[index],data[bestChild]);
    trickleDown(bestChild); //continue to trickledown until base case is hit or child is not better
  }
  else{
    return;
  }
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(std::size_t index){
  if(index == 0){ //if already a head, stop
    return;
  }
  while(index!=0){ //continue while not a head
    std::size_t parent = (index - 1)/m_ary;
    if(c_m(data[index],data[parent])){ //compare parent to current index, swap if better
      std::swap(data[index], data[parent]);
      index = parent;
      trickleUp(index); //trickle up until base case is hit or index is not better
    }
    else{
      return;
    }
  }
}


#endif

