/*
Write a program to find the longest compound word (LCW) from a list of words

For example, given string list, "hello" and "ball", "world", 
"helloworld", "morning", "helloball", the LCW is helloworld. 
In the below solution we use trie, though there are other ways 
to solve. Follow this C++ Tries to understand more about implementing Tries.
Approach to find the LCW

Traverse the Trie to find initial set of words which have 
valid substrings (from the word beginning) and create pair 
(main word:foundpart) and append the pair to a queue. For 
example in the above list, hello does not make it to the list 
but helloball makes it to the list with the pair "helloball":"hello"

Now process one by one pairs. See if the remaining part of the 
main word (that is by removing the found part) has any valid words 
in the list. If found add the new pair to the queue.

Whenever the found part is same as the main word, we found a 
compound word. Keep track of the best found compound word from 
their length point of view

Above we have assumed that the full list of words was not 
available and we have to extract them from the given trie. If 
the list was available then we could have avoided the first 
step (below function fillInitialCWs) and instead we could have 
added all the list words to the queue with a pair as word:"". 
That is empty string as foundpart. 

Also note that in fillInitialCWs, instead of preparing the 
list of words, we have advanced by one step to prepare the 
potential compound words directly!
*/