# 深入理解C++对象模型读书笔记

> 学习OO编程思想

## Object Lessons

### 1.1 The C++ Object Model

#### A Simple Object Model

- an object is a **sequence** of slots, where each slot points to a member
- members assigned a slot **in order of** their declarations

```c++
class Point
{
public:
	Point( float xval );
	virtual ~Point();
	float x() const;
	static int PointCount();
protected:
	virtual ostream& print( ostream &os ) const;
	float _x;
	static int _point_count;
};
```

按上述描述，当实例化一个对象时，该对象将会是一个指针的顺序表，其中每一个指针指向一个成员，并以定义中的顺序存储，对象的大小即为成员个数乘上指针大小。

#### A Table-driven Object Model

- two slots, which pointed to member data table & function member table
- The member function table is a sequence of slots, with each slot addressing a member. The data member table directly holds the data.

这种模型也就是多加了一层分类，这一层可以弥补以下模型的缺点，但是付出了额外的空间和执行效率。

#### The C++ Object Model

- **Non-static data members** are allocated **directly within** each class object.
- **Static data members** are stored **outside** the individual class object.
- Static and non-static function members are also hoisted **outside** the class object.
- A table of pointers to virtual functions is generated for each class. This is called the virtual table.
- A single pointer to the associated virtual table is inserted within each class object. This has been called the *vptr*. The setting, resetting, and *not* setting of the vptr is handled automatically through code generated within each class constructor, destructor, and copy assignment operator. The type_info object associated with each class in support of runtime type identification (RTTI) is also addressed within the virtual table, usually within the table's first slot.

该模型的优点在于空间和存取时间的效率，缺点在于非静态数据部分的增减会导致整个程序需要重新编译.

#### About Inheritance

