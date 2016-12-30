# The Shift-And algorithm

The shift-and algorithm is a string matching algorithm. There are two versions of this algorithm: the first one is for the exact matching problem, which is what i tried to implement in this program and the second one is for the fuzzy searching problem which means finding a string that is *similar* to a given pattern(see [Levenshtein distance](https://en.wikipedia.org/wiki/Levenshtein_distance)).
The algorithm consists of 2 phases: preprocessing and searching.  
1. The preprocessing is done on the *pattern* and not on the text, hence this algorithm performs better on patterns of limited length. Preprocessing consists in creating as much arrays as the symbols in the alphabet of the context. The size of the arrays is equal to the size of the pattern and each array tells us if a given symbol appears at a given position in the pattern.  
2. The actual matching process is done by building an array through bitwise operations (shift-and). Specific values in the array indicate wether or not a match was found.

Although the Shift-And method is very simple, and in worst case the number of bit operation is ![](Shift-And complexity.jpg) (where n is the pattern size and m the text size), the method is very efficient if n is less than the size of a single computer word (because in this case bitwise operation have a one-to-one correspondence with machine operation)

