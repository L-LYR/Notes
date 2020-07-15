# Effective系列读书笔记

# Effective C++

## View C++ as a federation of languages

- multiparadigm
  - procedural
  - object-oriented
  - functional
  - generic
  - metaprogramming
- sublanguages
  - pure C 
    - no templates
    - no excaptions
    - no overloading
    - ...
  - object-oriented C++
    - classes
    - encapsulation
    - inheritance
    - polymorphism
    - virtual functions(dynamic binding)
    - ...
  - template C++
    - template metaprogramming
  - STL
    - containers
    - iterators
    - algorithms
    - function objects

Rules for effective C++ programming vary, depending on the part of C++ you are using.

## Prefer `const`, `enum`, and `inline` to `#define`

In other words, prefer the compiler to the preprocessor.

- For simple constants, prefer `const` objects or `enum` to `#define`.

```C++
#define ASPECT_RATIO 1.653 			// No
const double AspectRatio = 1.653 	// Yes
    
class GamePlayer{
    private:
    	static const int NumTurns;
    	int scores[NumTurns];
    ......
}
const GamePlayer::NumTurns = 5; 	// Initialize

class GamePlayer{
	private:
    	enum { NumTurns = 5 };		// I prefer
    	int scores[NumTurns];
    ......
}
```

- For function-like macros, prefer `inline` functions to `#define`

## Use `const` whenever possible

- If the word `const` appears to the left of the asterisk, what's pointed to is constant; if the word `const` appears to the right of the asterisk, the pointer itself is constant; if `const` appears on both sides, both are constant.

```C++
char greeting[] = "Hello";
char *p = greeting; 				// non-const pointer,
									// non-const data
const char *p = greeting; 			// non-const pointer,
									// const data
char * const p = greeting; 			// const pointer,
									// non-const data
const char * const p = greeting; 	// const pointer,
									// const data
```

- Having a function return a constant value often makes it possible to reduce the incidence of client errors without giving up safety or efficiency.

```c++
class Rational { ... };

const Rational operator*(const Rational& lhs, const Rational&rhs);

if((a * b) = c) { ... } // avoid this case
```

- `const` member functions: make the interface of a class easier to understand and make it possible to work with `const` objects.There are two prevailing notions: bitwise constness (also known as physical constness) and logical constness.

  - The bitwise `const` camp believes that a member function is const if and only if it doesn't modify any of the object's data members (excluding those that are static), i.e., if it doesn't modify any of the bits inside the object. 

  - The logical `const` camp believes that a const member function might modify some of the bits in the object on which it's invoked, but only in ways that clients cannot detect.

  - In fact, bitwise constness is C++'s definition of constness, and a `const` member function isn't allowed to modify any of the non-static data members of the object on which it is invoked.

  - Trap in C++ `const` member function:

    - ```c++
      class CTextBlock {
      	public:
      		...
      		char& operator[](std::size_t position) const { return pText[position]; }
      						// inappropriate (but bitwise const)declaration of operator[]
          					// pay attention to the type of return value
      	private:
      		char *pText;	// not string because it needs to communicate through a C API
      };
      
      const CTextBlock greeting("Hello");
      
      char *pc = &greeting[0];
      *pc = 'J';					// greeting now has the value "Jello"
      ```

  - How to implement a logical `const` member function?

    - CTextBlock class might want to cache the length of the textblock whenever it's requested:
      ```C++
      class CTextBlock {
          public:
          	...
              std::size_t length() const;
          private:
          	char *pText;
          	std::size_t testLength;	// last calculated length of textblock
          	bool lengthIsValid;		// whether length is currently valid
      };
      
      std::size_t CTextBlock::length() const {
      	if (!lengthIsValid) {
      		textLength = std::strlen(pText); 	// error! can't assign to textLength
      		lengthIsValid = true; 				// and lengthIsValid in a const
      	} 										// member function
      	return textLength;
      }
      ```

    - The solution is simple: take advantage of C++'s `const`-related wiggle room known as `mutable`. `mutable` frees non-static data members from the constraints of bitwise constness:
    
      ```c++
      class CTextBlock {
          public:
          	...
              std::size_t length() const;
          private:
          	char *pText;
          	mutable std::size_t testLength;	// last calculated length of textblock
          	mutable bool lengthIsValid;		// whether length is currently valid
          	// mutable data member may always be modified, even in const member functions
      };
      
      std::size_t CTextBlock::length() const {
      	if (!lengthIsValid) {
      		textLength = std::strlen(pText);
      		lengthIsValid = true;
      	}
      	return textLength;
      }
      ```
    
  - Avoiding duplication in `const` and non-`const` member functions. For example, when implementing the `const` and non-`const` `operator[]`, you need to make the same bounds checking. So it's suggested that you could implement bounds checking in a `private` function. There exists a very extreme method. When `const` and non-`const` member functions have essentially identical implementations, code duplication can be avoided by having the non-`const` version call the `const` version.
  
    ```c++
    class TextBlock {
    	public:
    		...
    		const char& operator[](std::size_t position) const{
    			...		// bounds checking
    			...
    			...
    			return text[position];
    		}
    		char& operator[](std::size_t position) // now just calls const op[]
    		{
    			return const_cast<char&>( // cast away const on op[]'s return type;
    				static_cast<const TextBlock&>(*this)[position]
    			); // add const to *this's type and call const version of op[]
    		}
    		...
    };
    ```
  
    It seems a little bit confusing, but it works well. One more thing to note is that the other way around ------ avoiding duplication by having the `const` version call the non-`const` vetsion ------ is not something you want to do.

## Make sure that objects are initialized before they're used

- It's hard to remember rules which describe when objects initialization is guaranteed to take place and when it isn't. But remembering to initialize them is convenient.

- Not to confuse assignment with initialization.

  ```c++
  class PhoneNumber { ... };
  class ABEntry { // ABEntry = "Address Book Entry"
  	public:
  		ABEntry(const std::string& name, const std::string& address,
  				const std::list<PhoneNumber>& phones);
  	private:
  		std::string theName;
  		std::string theAddress;
  		std::list<PhoneNumber> thePhones;
  		int numTimesConsulted;
  };
  
  
  ABEntry::ABEntry(const std::string& name, const std::string& address,
  				 const std::list<PhoneNumber>& phones) {
  	theName = name; // these are all assignments,
  	theAddress = address; // not initializations
  	thePhones = phones;
  	numTimesConsulted = 0;
  }
  
  ABEntry::ABEntry(const std::string& name, const std::string& address,
  				 const std::list<PhoneNumber>& phones) :
  				theName(name), theAddress(address), 
  				thePhones(phones), numTimesConsulted(0) // these are now all initializations
                  {} // the ctor body is now empty
  ```

- One aspect of C++ that isn't fickle is the order in which an object's data is initialized. This order is always the same: base classes are initialized before derived classes, and within a class, data members are initialized in the order in which they are declared. 

- The order of initialization of non-local static objects defined in different translation units. 

  - The relative order of initialization of non-local static objects defined in different translation units is undefined.

  - For example:

    ```c++
    // FileSystem.h
    class FileSystem { // from your library’sheader file public:
    		...
    		std::size_t numDisks() const; // one of many member functions
    		...
    };
    extern FileSystem tfs; 	// declare object for clients to use
    						// ("tfs" = "the filesystem");
    						// definition is in some .cpp file in your library
    
    // Directory.h
    class Directory { // created by library client
    	public:
    		Directory( params );
    	...
    };
    
    Directory::Directory( params ){
    	...
    	std::size_t disks = tfs.numDisks(); // use the tfs object
    	...
    }
    
    // main.cpp
    Directory tempDir( params ); // directory for temporary files
    ```

    Unless `tfs` is initialized before `tempDir`, `tempDir`'s constructor will attempt to use `tfs` before it's been initialized.

  - Solution: **Singleton pattern.**

    All that has to be done is to move each non-local static object into its own function, where it's declared static . These functions return references to the objects they contain. Clients then call the functions instead of referring to the objects. In other words, non-local static objects are replaced with local static objects.

    ```c++
    class FileSystem { ... }; 				// as before
    FileSystem& tfs() 						// this replaces the tfsobject; it could be
    { 										// static in the FileSystem class
    	static FileSystem fs; 				// define and initialize a local static object
    	return fs; 							// return a reference to it
    }
    
    class Directory { ... }; 				// as before
    Directory::Directory( params ) 			// as before, except references to tfs are
    { 										// now to tfs()
    	...
    	std::size_t disks = tfs().numDisks();
    	...
    }
    Directory& tempDir() 					// this replaces theTempDir object; it
    { 										// could be static in the Directory class
    	static Directory td( params ); 		// define/initialize local static object
    	return td; 							// return reference to it
    }
    ```

    On the other hand, the fact that these functions contain `static` objects makes them problematic in **multithreaded** systems. Then again, any kind of non-`const` `static` object — local or non-local — is trouble waiting to happen in the presence of multiple threads. One way to deal with such trouble is to **manually invoke** all the reference-returning functions during the **single-threaded startup portion of the program**. This eliminates initialization-related race conditions.

## Know what functions C++ silently writes and calls

