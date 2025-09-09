📌 Trie Data Structure Implementation
📖 Overview

This project implements a Trie (Prefix Tree) data structure in C++.
The Trie allows:

✅ Inserting words

✅ Searching for complete words

✅ Checking if a prefix exists

✅ Autocomplete suggestions for a given prefix

It also includes a test program (main) that demonstrates and validates all functionalities.

🛠 Features

Insert(word) → Add a new word to the Trie.

Search(word) → Check if a complete word exists.

StartsWith(prefix) → Verify if a prefix exists in the Trie.

Autocomplete(prefix) → Suggest all words that start with the given prefix.

Edge Cases → Tests for empty strings and case sensitivity.

               ┌──────────────────┐
               │   Start Program   │
               └───────┬──────────┘
                       │
                       ▼
             ┌──────────────────────┐
             │   Create Trie Root   │
             └───────┬─────────────┘
                     │
                     ▼
        ┌─────────────────────────────┐
        │ Insert Words into the Trie  │
        └───────┬────────────────────┘
                │
                ▼
    ┌─────────────────────────────┐
    │ Perform Operations (Menu)   │
    │ 1. Insert                   │
    │ 2. Search                   │
    │ 3. StartsWith (Prefix)      │
    │ 4. Autocomplete             │
    └─────────────┬───────────────┘
                  │
     ┌────────────┼────────────┐
     ▼            ▼            ▼
    ┌────────┐  ┌────────┐  ┌────────────┐
    │ Search │  │ Prefix │  │Autocomplete│
    └───┬────┘  └───┬────┘  └─────┬──────┘
     │           │             │
     ▼           ▼             ▼
    Result:     Result:       Result:
    FOUND/      EXISTS/       List of words
    NOT FOUND   NOT EXISTS    with prefix
     │           │             │
     └───────────┴─────────────┘
                  │
                  ▼
         ┌───────────────────┐
         │ Continue or Exit? │
         └───────┬───────────┘
                 │
                 ▼
          ┌────────────┐
          │    End     │
          └────────────┘
