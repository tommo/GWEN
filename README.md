# About this fork

This is a fork of Garry Newman's excellent GWEN game UI toolkit. 
The main purpose of this fork is to modify GWEN so that it fits better with
embedded or console game development by:

* Trimming some of the memory usage and temporary memory allocations
* Supporting custom memory allocation schemes
* Abstracting the C++ features that are not well supported in console environments 
  (eg. iostreams, wide-char support)

while maintaining source-level compatibility as much as possible.

The intention is to submit all of these modifications for merging with the 
official GWEN repository.

