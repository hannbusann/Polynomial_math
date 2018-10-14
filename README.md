# Polynomial_math
An useful math tool to deal with polynomial problems.

## Prerequisite

These tools depend on Eigen modules. You'd better install Eigen3 in advance. 

``sudo apt-get install libeigen3-dev``

## Functions

- additon **+**

- substraction **-**

- multiplication *****

- evaluaiton **eval()**

- rooting **findRoots()**


## Test

- Download the source code by `git clone `in your terminal

  ```shell
  git clone http://github.com/hannbusann/Polynomial_math
  ```

- Compile the testpolynomial.cpp using cmake

  ```
  mkdir build
  cd build
  cmake ..
  make
  ```

- Execute the executable file, and view the outputs.

  ```
  ./testpolynomial
  	*** Polynomial algebra test ***
  	a: [1 2 3 4 5 6]
  	b: [1 2 3 4 5]
  	a+b: [ 1  3  5  7  9 11]
  	a-b: [1 1 1 1 1 1]
  	Degree elevation happens!
  	a*b: [ 1  4 10 20 35 50 58 58 49 30]
  	a(5): 4881
  
  	*** Polynomial roots test ***
  	c: [-0.8049  -0.443  0.0938   0.915  0.9298]
  	roots using sturm sequences:
  	c(-0.88849): 8.71792e-08
  	c(1.15442): 2.30762e-07
  ```




