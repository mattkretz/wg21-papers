[![Build Status](https://travis-ci.org/mattkretz/wg21-papers.svg?branch=master)](https://travis-ci.org/mattkretz/wg21-papers)
# WG21 Papers

This repository holds the LuaLaTeX sources for my papers to the C++ committee.

| Paper Number | Title |
| ------------ | ----- |
| P0214 | Data-Parallel Vector Types & Operations |
| P0349 | Assumptions about the size of datapar |
| P0350 | Integrating datapar with parallel algorithms and executors |

To build the papers you need make, LuaLaTeX (only tested with a recent TeXLive distribution), and Biber.
Simply run

    make final

to build the paper. You can find a recent upload of P0214 at https://web-docs.gsi.de/~mkretz/datapar.pdf
