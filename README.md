# Polynomial_math
An useful math tool to deal with polynomial problems.

## Prerequisites

These tools depend on Eigen modules. You'd better install Eigen3 in advance. 

``sudo apt-get install libeigen3-dev``

The namespace is polynomial now, change it if necessary.

## Functions

- overload additon **+**
- overload substraction **-**
- overload multiplication *
- overload equal **=**
- overload **==**
- get the cofficients **coefficients**
- evaluaiton **eval()**
- rooting **findRoots()**
- get the degree **getDegree**


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
  	They are the same!
      5
      5
      *** Polynomial algebra test ***
      a: [1 2 3 4 5 6]
      b: [1 2 3 4 5]
      a+b: [ 1  3  5  7  9 11]
      a-b: [1 1 1 1 1 1]
      a*b: [ 1  4 10 20 35 50 58 58 49 30]
      a(5): 4881
  
      *** Polynomial roots test ***
      c: [-0.8049  -0.443  0.0938   0.915  0.9298]
      roots using sturm sequences:
      c(-0.88849): 8.71792e-08
  
  ```




