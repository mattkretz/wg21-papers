### From [Standard Library Guidelines](https://github.com/cplusplus/LEWG/blob/master/library-design-guidelines.md):
* [ ] Names are all lower case separating words by underscores
* [ ] Avoid abbreviations except for common words: `_ptr`, `std`, etc. (apply common sense).
* [ ] Official names don't start with an underscore (only hidden names); exception: `_1`, `_2`, etc.
* [ ] No trailing underscores on names.

### General rules
* [ ] Uses words taken from a detailed description.
* Consistent:
  * [ ] within the proposal
  * [ ] with similar types
  * [ ] with the rest of the standard library
  * [ ] with other C++ libs
  * [ ] with the rest of the world
* [ ] Avoids misunderstandings / name collisions.
  Prefer a term that is not understood over a term that is misunderstood.
* [ ] When spoken, is the name unambiguous?
* [ ] use verbs for actions, adjectives for queries, nouns for types (try to avoid ambiguities)
