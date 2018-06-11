# libmd5

Implementation from scratch of the MD5 cryptographic function in C

This implementation doesn't support entry longer than 55 chars (this might be an
update for later).

## Getting Started

### Prerequisites 

This library is only built with the standard C libraries.

A C compiler is obviously needed, such as `gcc` or `clang`.

The built is handled by `cmake`, but an `autotools` dependencies might be added
in a more or less near future.


### Documentation Prerequisites

Even though there is no doc up to now, it will be likely generated with
`doxygen`.

## Installation 

### Building from source

Follow the instruction below to build the library + the CLI from source : 

```
git clone https://www.github.com/SiwonP/MD5_C 
mkdir build
cd build
cmake ..
make
```

### Binaries

The binaries of the CLI and the dynamic library are not yet available.

### Packages

No packages so far either.

## Running the tests

No tests implemented yet.

## Building the doc

No doc yet.

## Authors

- Simon Petit - initial contributer

## License

This project is under the GNU General Public License v3. See
[LICENSE](https://www.github.com/SiwonP/libmd5/blob/master/LICENSE) for details.
