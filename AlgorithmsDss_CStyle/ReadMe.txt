The main goal is to make the code as clear as possible (mostly, to use as a reference).

Thus, the project:
    - doesn't strive to use generic code. E.g. graph implementations may have just enough features to make the algorithms work;
making the algorithm generic can be omitted.
    - avoids some error checks. Input for data structures creation is assumed to be always correct:
no attempts to insert a duplicate vertex or edge to a graph, etc.
    - mixes features of C++ and C, sacrificing data encapsulation to simplify the algorithms logic.
    - avoids optimizations: here, clarity is more important than speed.
    - using STL is perfectly acceptable if the STL approach looks more simple: e.g. an STL collection 
can be an auxiliary tool for data structure implementation (e.g. an STL vector can be used to store vertex data in a graph).
	- each source module should be as self-contained as possible. In particular, having a separate swap() function 
for each sorting algorithm is OK.

Date: October 2, 2018

////////////////////////////////////////////////////////////
