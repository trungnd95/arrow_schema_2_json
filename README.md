## Schema2Json

> Helper project that help convert Apache arrow schema to Json string and vice vesa. 

----------------

1. Features
  - `jsonStr2Schema`: convert json string to apache arrow schema
  - `schema2JsonStr`: convert arrow schema to json string 

2. Todo

	- [x] Using mordern cpp language
	- [x] [Build script using cmake or qmake](./CMakeLists.txt)
	- [x] [Write Unit test using Google Test](./test)
	- [x] [Follow consistent coding style](./coding-styles)
	- [x] [Documentation](./doc)

3. Install package and build project
- Install Package: 
	Run `sh ./install.sh` to:
	- Install apache arrow 
	- Install cmake 
	- Install gtest
	- Install json lib

- Build project: 
	- Create build folder: `mkdir build && cd build` 
	- Run cmake:  `cmake ..`
	- Run make: `make`

4. Test 
	Run: `./Schema2Json`


----------------------
Trung Nguyen
    
