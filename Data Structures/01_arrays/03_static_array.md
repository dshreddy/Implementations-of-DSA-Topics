## Arrays: The Simplest Data Structure

An array is a collection of elements stored in **contiguous** memory locations. This means there is no gap between the elements in RAM.

### Key Storage Differences:
The amount of memory an element occupies depends on its **data type**:
* **Integers (32-bit):** Typically take up **4 bytes** each. If the first element is at address `$0`, the next will be at `$4`.
* **Characters (ASCII):** Typically take up **1 byte** each. If the first character is at address `$0`, the next will be at `$1`.

### Properties of Arrays:
* **Efficiency:** Because they are contiguous, accessing any element is O(1).

Static Arrays and Memory Management
Core Concepts
• Definition: A collection of elements stored in contiguous (back-to-back) memory addresses in RAM.



• RAM Property: Known as Random Access Memory, meaning any individual location can be accessed instantly if the address is known.



Memory Structure
• Address vs. Value: Every entry in RAM has a unique address (hexadecimal) and an associated value.



• Contiguity: Elements are stored sequentially without gaps, allowing for rapid navigation using indexing.



Data Type Spacing
The memory gap between elements depends on the data type:



• 32-bit Integers: Occupy 4 bytes. Addresses increment by 4 ().



• Characters (ASCII): Occupy 1 byte. Addresses increment by 1 ().



Common Operations & Complexity
Operations are measured in Big-O Notation based on the number of elements ($n$).



Key Limitation
• Fixed Size: Static arrays have a set capacity upon creation.



• Resizing: You cannot simply "add" space to a static array if the adjacent memory is already occupied by other data.



• Static vs. Dynamic: While languages like Python/JavaScript use dynamic arrays by default, the underlying primitive structure is the static array.



[Image of an array being stored in RAM memory blocks] [Image of an array shift operation for element insertion]
