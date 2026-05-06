# Reversed Symbol Substitution Decoder

A C++ implementation for decoding an alien-style message encoded with reversed symbol patterns.

This is not a Caesar cipher. The message is reversed, split by a repeated separator symbol, and each symbolic token is mapped back to an English character.

## Approach

1. Reverse the encoded message.
2. Count character frequency to identify the separator symbol.
3. Split the reversed message into tokens.
4. Convert each token into an English character using a lookup table.

## Key Concepts

- String reversal
- Hash maps with `unordered_map`
- Frequency counting
- Token parsing
- Symbol-to-character substitution

## Complexity

- Time: `O(n)`
- Space: `O(n)`

Where `n` is the length of the encoded message.

## File

- [solution.cpp](solution.cpp)
