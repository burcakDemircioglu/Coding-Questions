/*
Implement LRU cache with O(1) operations
LRU --> Least Recently Used cache is method where in when 
cache size is full to accommodate for new page, it will 
unload least recently used page.
The approach

To access the pages in the LRU cache, to have O(1) operation, 
good to go for hash table.

How do we maintain the time-stamp information. One way is 
to keep them ordered with latest used to previously used 
pages in a time decreasing order. So let us create a linked 
list with nodes to the page pointers and whenever a page in 
the cache is touched or a page is loaded that page node is 
made head of the list. And that way the tail is always least 
recently used and when cache size is full and we can delete 
the page pointed by the tail.
Creating a new node as head is O(1). Deleting form the tail 
would be O(1), if we maintain tail info, but however, updating 
tail is not. And when a touched page needs to be moved to the 
head position, we need to do 2 things 1. access it and 2 de-link 
to move to head. First is solved by the hash table, which keeps 
the pointers to the nodes as the values. And for second, to de-link 
the node from the middle to the front, we need to do in O(1). For 
this, instead of single linked list we use doubly linked list. 
This gives O(1) operation for de-linking as well as updating the tail.

*/