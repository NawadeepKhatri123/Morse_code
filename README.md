
# Morse Code Translator (Binary Tree Implementation)

## 📌 Overview

This program implements a Morse Code Translator using a Binary Tree in C++

- **Encodes text** into Mores Code
- **Decodes** Mores code back into text
- **Reads Mores mapping form a file** and builds a binary tree

## 🛠️ Features

✅ Reads Morse codes from **mores.txt** and builds a **Morse code binary tree**

✅ Encodes text input to Morse code

✅ Decodes Morse code input back to text

✅ Uses **object-oriented programming**(OOP) principles

✅ **User-friendly menu to choose encoding or decoding

## 📂 Files
| File | Description|
| ------------ | ---------- |
| BTNode.h| Defines a binary tree node structure |
| Binary_Tree.h| Implements a binary tree and Morse code functions|
| main.cpp| Driver program for encoding & decoding messages|
| morse.txt|Contains Morse code mappings for letters|

## ⚙️ How It Works

1️⃣ **Morse Code Binary Tree

- The root node is empty (*)
- Each letter is inserted based on its Morse pattern:

    - (dot) → Left child
    - (dash) → Right child

2️⃣ Encoding (Text → Morse)

- Finds the Morse code for each letter by searching the tree
- Outputs the Morse equivalent of the message

3️⃣ Decoding (Morse → Text)

- Reads Morse symbols and traverses the tree
- Converts Morse sequences into letters














## 🚀 Usage

1️⃣ **Compile the program**

```bash
 g++ -o morse main.cpp
```

2️⃣ **Run the program**

```bash
 ./morse
```

3️⃣ **Enter your Choice**

```bash
 1. Encode a message
 2. Decode a Morse code message
 3. Exit
 Choose an option: _
```

5️⃣ **Decoding Example**

```bash
 Enter Morse code to decode: .... . .-.. .-.. ---
 Decoded message: hello

```

## 📜 Morse Code File Format(morse.txt)

```bash
 A .-
 B -...
 C -.-.
 D -..
 E .
 F ..-.
 G --.
 H ....
 I ..
 J .---
 K -.-
 L .-..
 M --
 N -.
 O ---
 P .--.
 Q --.-
 R .-.
 S ...
 T -
 U ..-
 V ...-
 W .--
 X -..-
 Y -.-- 
 Z --..
```
Make sure this file is in the **same folder** as your executable
