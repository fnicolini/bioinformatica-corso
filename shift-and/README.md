# The shift-and algorithm

The shift-and algorithm is a **string matching** algorithm.

Two versions of this algorithm exists: the first, presented here, implements the **exact searching** and the second implements the **fuzzy searching** (finding a string that is *similar* to a given pattern, see [Levenshtein distance](https://en.wikipedia.org/wiki/Levenshtein_distance)).

The algorithm consists of these two phases:
- **Preprocessing**

  This phase operates on the *pattern* and not on the text, hence this algorithm performs better on patterns of limited length. 

  Preprocessing consists in creating as much arrays as the symbols in the alphabet of the context. The size of the arrays is equal to the size of the pattern and each array tells us if a given symbol appears at a given position in the pattern.

 
- **Searching**

  The actual matching process is done by building an array through bitwise operations (shift-and). Specific values in the array indicate wether or not a match was found.

Although this method is very simple, and in worst case scenario the number of bit operations is `Θ(n * m)`, with `n` as the pattern size and `m` as the text size, the method is very efficient if `n` is less than the size of a single computer word, since in this case bitwise operation have a one-to-one correspondence with machine operation.

##### References
- [*Bitap Algorithm* - Wikipedia](https://en.wikipedia.org/wiki/Bitap_algorithm) 
- *Algorithm on Strings, Trees and Sequences* - D.Gusfield
