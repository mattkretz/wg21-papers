[![Build Status](https://travis-ci.org/mattkretz/vector-types-paper.svg?branch=master)](https://travis-ci.org/mattkretz/vector-types-paper)
# vector-types-paper

This repository holds the LuaLaTeX sources for the “Data-Parallel Vector Types &amp; Operations” paper
to be submitted to the C++ committee. It incorporates the work presented in N4184, N4185, and N4395.
While the previous papers described the API as implemented originally in the Vc library, this paper focuses
on getting it ready for LEWG.

To build the paper you need make, LuaLaTeX (only tested with a recent TeXLive distribution), and Biber.
Simply run

    make final

to build the paper. You can find a recent upload at https://web-docs.gsi.de/~mkretz/datapar.pdf
