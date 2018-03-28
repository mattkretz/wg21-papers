# WG21 Papers

This repository holds the LuaLaTeX sources for my papers to the C++ committee.

| Paper Number                     | Latest Draft                                       | Title                                   |
| -------------------------------- | -------------------------------------------------- | --------------------------------------- |
| [P0214](https://wg21.link/p0214) |                                                    | Data-Parallel Vector Types & Operations |
| [P0349](https://wg21.link/p0349) |                                                    | Assumptions about the size of datapar   |
| [P0350](https://wg21.link/p0350) | [D0350](https://web-docs.gsi.de/~mkretz/D0350.pdf) | Integrating datapar with parallel algorithms and executors |
| [P0851](https://wg21.link/p0851) |                                                    | `simd<T>` is neither a product type nor a container type |
| [P0916](https://wg21.link/p0916) |                                                    | Naming implementation-defined `simd_abi` tag types |
| [P0917](https://wg21.link/p0917) | [D0917](https://web-docs.gsi.de/~mkretz/D0917.pdf) | Making operator?: overloadable          |
| [P0964](https://wg21.link/p0964) | [D0964](https://web-docs.gsi.de/~mkretz/D0964.pdf) | Finding the right set of traits for `simd<T>` |

To build the papers you need make, LuaLaTeX (only tested with a recent TeXLive distribution), and Biber.
Simply run

    make final

to build the paper.
