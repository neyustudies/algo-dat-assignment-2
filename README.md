# Binary Search Tree C++

### Sample output: insert

```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
1

Option 1 selected: Enter the keys to be inserted, seperated by spaces
To terminate the input, press any alphabet [Enter]
1 2 3 4 5 6 7 8 9 1 22 3 467 k
1 is already existing
3 is already existing
The size of the tree now is 11
```

### Sample output: remove
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
2

Option 2 selected: Which node do you want to remove?
6
6 has been removed
The size of the tree now is 10
```

### Sample output: print
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
3

Option 3 selected: Printing the tree in in-order
1  2  3  4  5  7  8  9  22  467  
```

### Sample output: find
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
4

Option 4 selected: Which node do you want to search?
22
Key 22 has been found, its address is 0x7f9877d041a0
```

### Sample output: successor
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
5

Option 5 selected: Whose successor are you looking for?
9
Successor to node 9 is 22
```

### Sample output: predecessor
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
6

Option 6 selected: Whose predecessor are you looking for?
2
Predecessor to node 2 is 1
```

### Sample output: maximum
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
7

Option 7 selected: Searching for the rightmost key..
467 is the maximum key
```


### Sample output: minimum
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
8

Option 8 selected: Searching for the leftmost key..
1 is the minimum key
```

### Sample output: quit
```
▶︎ Select an action: 
1. INSERT, 2. REMOVE, 3. PRINT, 4. FIND, 5. SUCC, 6. PRED, 7. MAX, 8. MIN, 9. QUIT
9

Option 9 selected: Goodbye! Exiting the program
```