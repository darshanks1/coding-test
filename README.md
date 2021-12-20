# coding-test
coding test MCA


1) Take one character stack to store the starting chuncks or brackets.
2) Traverse through the given input string characters
  a) push it to the stack if the character is starting chuncks. (,<,{ 
  b) pop the stack if the current char is closing chuncks ),>,],} and check the current char and popped char from stack for the syntax error and update the error count value.
3) At the end after complete traversal if there is some starting chuncks char left out in the stack calculate error count for each and update it.
