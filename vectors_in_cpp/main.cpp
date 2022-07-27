//
//  main.cpp
//  vectors_in_cpp
//
//  Created by AK on 7/17/22.
//
// What?
// std::vector is a sequence container that is also known as a dynamic array
// size and capacity can grow/shrink at runtime
//
// How?
// Declaration :
// - std::vector<int> vec1 = {1,2,3}; // initialiser list
// - std::vector<int> vec2 {1,2,3}; // uniform initialisation
// Access :
// at(), [], front(), back(), data() ...
// Modify :
// insert(), emplace(), push_back(), emplace_back(), pop_back()
// clear(), erase(), resize(), reserve(), swap() ...

#include <iostream>
#include <vector>


int main(int argc, const char * argv[]) {
  
  // assign()
  std::vector<int> first_assign;
  std::vector<int> second_assign;
  std::vector<int> third_assign;
  first_assign.assign (7,100); // 7 ints with a value of 100
  std::vector<int>::iterator vec_assign_it; // vector iterator pointing to nothing (not yet initialised with a value)
  vec_assign_it = first_assign.begin()+1;
  second_assign.assign(vec_assign_it,first_assign.end()-1); // the 5 central values of first
  int int_array[] = {1776,7,4};
  third_assign.assign(int_array,int_array+3);   // assigning from array
  std::cout << "Size of first: " << int (first_assign.size()) << '\n';
  std::cout << "Size of second: " << int (second_assign.size()) << '\n';
  std::cout << "Size of third: " << int (third_assign.size()) << '\n';
  
  
  // at() - perform operation at this index
  std::vector<int> vec_at (10);   // 10 zero-initialized ints
  // assign some values:
  for (unsigned i=0; i<vec_at.size(); i++)
    vec_at.at(i)=i;
  std::cout << "vec_at contains:";
  for (unsigned i=0; i<vec_at.size(); i++)
    std::cout << ' ' << vec_at.at(i);
  std::cout << '\n';

    
  // back() - returns a direct reference to the last element (value)
  std::vector<int> vec_back;
  vec_back.push_back(10);
  while (vec_back.back() != 0)
  {
    vec_back.push_back (vec_back.back()-1);
  }
  std::cout << "vec_back contains:";
  for (unsigned i=0; i<vec_back.size() ; i++)
    std::cout << ' ' << vec_back[i];
  std::cout << '\n';
  
  // begin()/end() -  returns pointer to first/last element
  std::vector<int> vec_begin;
  for (int i=1; i<=5; i++) vec_begin.push_back(i);
  std::cout << "vec_begin contains:";
  for (std::vector<int>::iterator it = vec_begin.begin() ; it != vec_begin.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  
  // front() - returns a reference to the first element in the vector.
  //  Calling this function on an empty container causes undefined behavior.
  std::vector<int> vec_front;
  vec_front.push_back(78);
  vec_front.push_back(16);
  // now front equals 78, and back 16
  vec_front.front() -= vec_front.back();
  std::cout << "vec_front.front() is now " << vec_front.front() << '\n';

  
  // capacity()
  //  Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
  //
  //  Capacity is not necessarily equal to the vector size.
  //  It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
  //
  //  When capacity is exhausted and more is needed, it is automatically expanded by the container (reallocating storage space).
  //
  //  The theoretical limit on the size of a vector is given by the member max_size().
  //
  //  Capacity of a vector can be explicitly altered by calling member vector::reserve.
  std::vector<int> vec_capacity;
  // set some content in the vector:
  for (int i=0; i<100; i++) vec_capacity.push_back(i);
  std::cout << "size: " << (int) vec_capacity.size() << '\n';
  std::cout << "capacity: " << vec_capacity.capacity() << '\n';
  std::cout << "max_size: " << vec_capacity.max_size() << '\n';
  
  
  // cbegin()/cend()
  //  Return const_iterator to beginning/ending
  //  Returns a const_iterator pointing to the first/last element in the container.
  //
  //  A const_iterator is an iterator that points to const content. This iterator can be increased and decreased (unless it is itself also const), just like the iterator returned by vector::begin, but it cannot be used to modify the contents it points to, even if the vector object is not itself const.
  //
  //  If the container is empty, the returned iterator value shall not be dereferenced.
  std::vector<int> vec_cbegin_cend = {10,20,30,40,50};
  std::cout << "vec_cbegin_cend contains:";
  for (auto it = vec_cbegin_cend.cbegin(); it != vec_cbegin_cend.cend(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  // clear()
  //  Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
  //
  //  A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function.
  //
  // A typical alternative that forces a reallocation is to use swap:
  //  vector<T>().swap(x);   // clear x reallocating
  std::vector<int> vec_clear;
  vec_clear.push_back (100);
  vec_clear.push_back (200);
  vec_clear.push_back (300);
  std::cout << "vec_clear contains:";
  for (unsigned i=0; i<vec_clear.size(); i++)
    std::cout << ' ' << vec_clear[i];
  std::cout << '\n';
  vec_clear.clear();
  vec_clear.push_back (1101);
  vec_clear.push_back (2202);
  std::cout << "vec_clear contains:";
  for (unsigned i=0; i<vec_clear.size(); i++)
    std::cout << ' ' << vec_clear[i];
  std::cout << '\n';
  
  
  // crbegin()/crend()
  //  const_reverse_iterator crbegin() const noexcept;
  //  Return const_reverse_iterator to reverse beginning
  //  Returns a const_reverse_iterator pointing to the last element in the container (i.e., its reverse beginning).
  std::vector<int> vec_crbegin_crend = {1,2,3,4,5};
  std::cout << "vec_crbegin_crend backwards:";
  for (auto rit = vec_crbegin_crend.crbegin(); rit != vec_crbegin_crend.crend(); ++rit)
    std::cout << ' ' << *rit;
  std::cout << '\n';
  
  // data()
  //  Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
  //
  //  Because elements in the vector are guaranteed to be stored in contiguous storage locations in the same order as represented by the vector, the pointer retrieved can be offset to access any element in the array.
  std::vector<int> vec_data (5);
  int* p = vec_data.data();
  *p = 10;
  ++p;
  *p = 20;
  p[2] = 100;
  std::cout << "vec_data contains:";
  for (unsigned i=0; i<vec_data.size(); ++i)
    std::cout << ' ' << vec_data[i];
  std::cout << '\n';
  
  
  // emplace()
  //  Construct and insert element
  //  The container is extended by inserting a new element at position. This new element is constructed in place using args as the arguments for its construction.
  //
  //  This effectively increases the container size by one.
  //
  //  An automatic reallocation of the allocated storage space happens if -and only if- the new vector size surpasses the current vector CAPACITY.
  //
  //  Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to shift all the elements that were after position by one to their new positions. This is generally an inefficient operation compared to the one performed by other kinds of sequence containers (such as list or forward_list). See emplace_back for a member function that extends the container directly at the end.
  //
  //  The element is constructed in-place by calling allocator_traits::construct with args forwarded.
  //
  //  A similar member function exists, insert, which either copies or moves existing objects into the container.
  std::vector<int> vec_emplace = {10,20,30};

  auto vec_emplace_it = vec_emplace.emplace ( vec_emplace.begin()+1, 100 );
  vec_emplace.emplace ( vec_emplace_it, 200 );
  vec_emplace.emplace ( vec_emplace.end(), 300 );

  std::cout << "vec_emplace contains:";
  for (auto& x: vec_emplace)
    std::cout << ' ' << x;
  std::cout << '\n';
  // 10 200 100 20 30 300
  
  // emplace_back()
  //  Construct and insert element at the end
  //  Inserts a new element at the end of the vector, right after its current last element. This new element is constructed in place using args as the arguments for its constructor.
  //
  //  This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector CAPACITY.
  //
  //  The element is constructed in-place by calling allocator_traits::construct with args forwarded.
  //
  //  A similar member function exists, push_back, which either copies or moves an existing object into the container.
  std::vector<int> vec_emplace_back = {10,20,30};
  vec_emplace_back.emplace_back (100);
  vec_emplace_back.emplace_back (200);
  std::cout << "vec_emplace_back contains:";
  for (auto& x: vec_emplace_back)
    std::cout << ' ' << x;
  std::cout << '\n';
  
  
  // empty()
  //  Returns whether the vector is empty (i.e. whether its size is 0).
  //
  //  This function does not modify the container in any way. To clear the content of a vector, see vector::clear.
  std::vector<int> vec_empty;
  int sum (0);
  for (int i=1;i<=10;i++) vec_empty.push_back(i);
  while (!vec_empty.empty())
  {
    sum += vec_empty.back();
    vec_empty.pop_back();
  }
  std::cout << "total: " << sum << '\n';

  
  // erase()
  //  Return iterator to end
  //  Returns an iterator referring to the past-the-end element in the vector container.
  //
  //  The past-the-end element is the theoretical element that would follow the last element in the vector. It does not point to any element, and thus shall not be dereferenced.
  //
  //  Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with vector::begin to specify a range including all the elements in the container.
  //
  //  If the container is empty, this function returns the same as vector::begin.
  std::vector<int> vec_erase;
  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) vec_erase.push_back(i);
  // erase the 6th element
  vec_erase.erase (vec_erase.begin()+5);
  // erase the first 3 elements:
  vec_erase.erase (vec_erase.begin(),vec_erase.begin()+3);
  std::cout << "vec_erase contains:";
  for (unsigned i=0; i<vec_erase.size(); ++i)
    std::cout << ' ' << vec_erase[i];
  std::cout << '\n';

  
  // insert()
  //  Insert elements
  //  The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
  //
  //  This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
  //
  //  Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to relocate all the elements that were after position to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
  //
  //  The parameters determine how many elements are inserted and to which values they are initialized:
  std::vector<int> vec_insert (3,100);
  std::vector<int>::iterator vec_insert_it;
  vec_insert_it = vec_insert.begin();
  vec_insert_it = vec_insert.insert ( vec_insert_it , 200 );
  vec_insert.insert (vec_insert_it,2,300);
  // "vec_insert_it" no longer valid, get a new one:
  vec_insert_it = vec_insert.begin();
  std::vector<int> vec_insert_2 (2,400);
  vec_insert.insert (vec_insert_it+2,vec_insert_2.begin(),vec_insert_2.end());
  int data_array [] = { 501,502,503 };
  vec_insert.insert (vec_insert.begin(), data_array, data_array+3);
  std::cout << "vec_insert contains:";
  for (vec_insert_it=vec_insert.begin(); vec_insert_it<vec_insert.end(); vec_insert_it++)
    std::cout << ' ' << *vec_insert_it;
  std::cout << '\n';
  
  // operator=
  //  Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
  std::vector<int> vec_1_equal_op (3,0);
  std::vector<int> vec_2_equal_op (5,0);
  vec_2_equal_op = vec_1_equal_op;
  vec_1_equal_op = std::vector<int>();
  std::cout << "Size of foo: " << int(vec_1_equal_op.size()) << '\n';
  std::cout << "Size of bar: " << int(vec_2_equal_op.size()) << '\n';

  // operator[]
  //  Access element
  //  Returns a reference to the element at position n in the vector container.
  //
  //  A similar member function, vector::at, has the same behavior as this operator function, except that vector::at is BOUND-CHECKED and signals if the requested position is out of range by throwing an out_of_range exception.
  //
  //  Portable programs should never call this function with an argument n that is out of range, since this causes undefined behavior.
  std::vector<int> vec_at_op (10);   // 10 zero-initialized elements
  std::vector<int>::size_type sz = vec_at_op.size();
  // assign some values:
  for (unsigned i=0; i<sz; i++) vec_at_op[i]=i;
  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = vec_at_op[sz-1-i];
    vec_at_op[sz-1-i] = vec_at_op[i];
    vec_at_op[i] = temp;
  }

  std::cout << "vec_at_op contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << vec_at_op[i];
  std::cout << '\n';

  
  // pop_back()
  //  Removes the last element in the vector, effectively reducing the container size by one.
  //
  //  This destroys the removed element.
  std::vector<int> vec_pop_back;
  int vec_pop_back_sum (0);
  vec_pop_back.push_back (100);
  vec_pop_back.push_back (200);
  vec_pop_back.push_back (300);
  while (!vec_pop_back.empty())
  {
    vec_pop_back_sum+=vec_pop_back.back();
    vec_pop_back.pop_back();
  }
  std::cout << "The elements of vec_pop_back add up to " << vec_pop_back_sum << '\n';
  
  //push_back()
  //  Add element at the end
  //  Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
  //
  //  This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
  std::vector<int> vec_push_back;
  int x = 420;
  vec_push_back.push_back (x);
  std::cout << "vec_push_back stores " << int(vec_push_back.size()) << " numbers.\n";
  
  
  // resize()
  //  Change size
  //  Resizes the container so that it contains n elements.
  //
  //  If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
  //
  //  If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
  //
  //  If n is also greater than the current container capacity, an AUTOMATIC REALLOCATION of the allocated storage space takes place.
  //
  //  Notice that this function changes the actual content of the container by inserting or erasing elements from it.
  std::vector<int> vec_resize;
  // set some initial content:
  for (int i=1;i<10;i++) vec_resize.push_back(i);
  vec_resize.resize(5);
  vec_resize.resize(8,100);
  vec_resize.resize(12);
  std::cout << "vec_resize contains:";
  for (int i=0;i<vec_resize.size();i++)
    std::cout << ' ' << vec_resize[i];
  std::cout << '\n';
  
  // shrink_to_fit()
  //  Shrink to fit
  //  Requests the container to reduce its capacity to fit its size.
  //
  //  The request is non-binding, and the container implementation is free to optimize otherwise and leave the vector with a capacity greater than its size.
  //
  //  This may cause a reallocation, but has no effect on the vector size and cannot alter its elements.
  std::vector<int> vec_shrink_to_fit (100);
  std::cout << "1. capacity of vec_shrink_to_fit: " << vec_shrink_to_fit.capacity() << '\n';

  vec_shrink_to_fit.resize(10);
  std::cout << "2. capacity of vec_shrink_to_fit: " << vec_shrink_to_fit.capacity() << '\n';

  vec_shrink_to_fit.shrink_to_fit();
  std::cout << "3. capacity of vec_shrink_to_fit: " << vec_shrink_to_fit.capacity() << '\n';

    
  // size()
  //  Return size
  //  Returns the number of elements in the vector.
  //
  //  This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
  std::vector<int> vec_size;
  std::cout << "0. size: " << vec_size.size() << '\n';
  for (int i=0; i<10; i++) vec_size.push_back(i);
  std::cout << "1. size: " << vec_size.size() << '\n';
  vec_size.insert (vec_size.end(),10,100);
  std::cout << "2. size: " << vec_size.size() << '\n';
  vec_size.pop_back();
  std::cout << "3. size: " << vec_size.size() << '\n';
  
  
  // relational operators
  //  Relational operators for vector
  //  Performs the appropriate comparison operation between the vector containers lhs and rhs.
  //
  //  The equality comparison (operator==) is performed by first comparing sizes, and if they match, the elements are compared sequentially using operator==, stopping at the first mismatch (as if using algorithm equal).
  //
  //  The less-than comparison (operator<) behaves as if using algorithm lexico\-graphical_compare, which compares the elements sequentially using operator< in a reciprocal manner (i.e., checking both a<b and b<a) and stopping at the first occurrence.
  //
  //  The other operations also use the operators == and < internally to compare the elements, behaving as if the following equivalent operations were performed:
  //  operation   equivalent operation
  //  a!=b  - >   !(a==b)
  //  a>b   - >   b<a
  //  a<=b  - >   !(b<a)
  //  a>=b  - >   !(a<b)
  //
  //  These operators are overloaded in header <vector>.
  std::vector<int> vec_1_relational_op (3,100);   // three ints with a value of 100
  std::vector<int> vec_2_relational_op (2,200);   // two ints with a value of 200

  if (vec_1_relational_op==vec_2_relational_op) std::cout << "vecs are equal\n";
  if (vec_1_relational_op!=vec_2_relational_op) std::cout << "vecs are not equal\n";
  if (vec_1_relational_op< vec_2_relational_op) std::cout << "vec_1 is less than vec_2\n";
  if (vec_1_relational_op> vec_2_relational_op) std::cout << "vec_1 is greater than vec_2\n";
  if (vec_1_relational_op<=vec_2_relational_op) std::cout << "vec_1 is less than or equal to vec_2\n";
  if (vec_1_relational_op>=vec_2_relational_op) std::cout << "vec_1 is greater than or equal to vec_2\n";
  
  
  // swap(vector)
  //  Exchange contents of vectors
  //  The contents of container x are exchanged with those of y.
  //  Both container objects must be of the same type (same template parameters), although sizes may differ.
  //
  //  After the call to this member function, the elements in x are those which were in y before the call, and the elements of y are those which were in x.
  //  All iterators, references and pointers remain valid for the swapped objects.
  //
  //  The containers exchange references to their data, without actually performing any element copy or movement): It behaves as if x.swap(y) was called.
  std::vector<int> vec_1_swap_vec (3,100);   // three ints with a value of 100
  std::vector<int> vec_2_swap_vec (5,200);   // five ints with a value of 200
  std::swap(vec_1_swap_vec, vec_2_swap_vec);
  std::cout << "vec_1_swap_vec contains:";
  for (std::vector<int>::iterator it = vec_1_swap_vec.begin(); it!=vec_1_swap_vec.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout << "vec_2_swap_vec contains:";
  for (std::vector<int>::iterator it = vec_2_swap_vec.begin(); it!=vec_2_swap_vec.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  vec_1_swap_vec.swap(vec_2_swap_vec);
  std::cout << "vec_1_swap_vec contains:";
  for (std::vector<int>::iterator it = vec_1_swap_vec.begin(); it!=vec_1_swap_vec.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout << "vec_2_swap_vec contains:";
  for (std::vector<int>::iterator it = vec_2_swap_vec.begin(); it!=vec_2_swap_vec.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  return 0;
}
