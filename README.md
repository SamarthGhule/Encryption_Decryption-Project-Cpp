# Encryption_Decryption-Project-Cpp

Statistics of Algorithm

• Private Phrase Generation - Algorithm can generate (2660)^54 number of unique Private Phrases.

• Algorithm can generate 1.6*(10)^16 number of unique Encryption codes for a single character of a message.


An overview of the encryption-decryption project implemented in C++ through the Encryption.cpp and Decryption.cpp files:

### Encryption Process (Encryption.cpp):

1. **File Reading:**
   - The program reads a specific line from a file named "filename.txt" (specified by `line_number`) and extracts words from that line.

2. **Word Rotation:**
   - The words extracted are rotated anticlockwise in an array (`pp`) based on a calculation involving the ASCII values of characters in the last word of the line.

3. **Character Mapping:**
   - A mapping (`m`) is created between characters (`charcater`) and strings (`pp`), forming a substitution cipher.

4. **File Reading (Again):**
   - Another line is read from the same file ("filename.txt") to extract a string (`ep`), presumably the message to be encrypted.

5. **Shift Calculation:**
   - Shift values are calculated based on the first character of specific mappings in the map (`m`).

6. **Array Rotation:**
   - Arrays of characters (`messagechar` and `charcater`) are rotated to the left using the calculated shift values.

7. **String to Integer Conversion:**
   - Characters are converted to strings and stored in an array (`encrypt`).

8. **Mapping Creation:**
   - Mappings (`apl` and `aplm`) are created between characters in the alphabet and the corresponding strings in the `encrypt` array.

9. **Random Position Calculation:**
   - A random position (`rp`) is calculated based on the ASCII values of characters associated with a specific key ('F') in the map (`m`).

10. **Sorted Keywords Generation:**
    - For each character in the alphabet, a string is created by changing, rotating, and combining substrings, using the mappings (`apl` and `aplm`), and the random position (`rp`).

### Decryption Process (Decryption.cpp):

1. **File Reading (Same as Encryption):**
   - Reads a specific line from a file ("filename.txt") and extracts words from that line.

2. **Word Rotation (Same as Encryption):**
   - Rotates the words anticlockwise based on a calculation involving the ASCII values of characters in the last word of the line.

3. **Character Mapping (Same as Encryption):**
   - Creates a mapping (`m`) between characters and strings.

4. **File Reading (Again, Same as Encryption):**
   - Reads another line from the same file to extract a string (`ep`), presumably the encrypted message.

5. **Shift Calculation (Same as Encryption):**
   - Calculates shift values based on the first character of specific mappings in the map (`m`).

6. **Array Rotation (Same as Encryption):**
   - Rotates arrays of characters (`messagechar` and `charcater`) using the calculated shift values.

7. **String to Integer Conversion (Same as Encryption):**
   - Converts characters to strings and stores them in an array (`encrypt`).

8. **Mapping Creation (Same as Encryption):**
   - Creates mappings (`apl` and `aplm`) between characters in the alphabet and the corresponding strings in the `encrypt` array.

9. **Random Position Calculation (Same as Encryption):**
   - Calculates a random position (`rp`) based on the ASCII values of characters associated with a specific key ('F') in the map (`m`).

10. **Sorted Keywords Generation (Same as Encryption):**
    - Generates sorted keywords based on the map (`m`) and the random position (`rp`).

11. **Decryption:**
    - Matches substrings of the encrypted message (`ep`) with the sorted keywords and prints the corresponding characters.

### Notes:
- The code uses rotation and substitution techniques for encryption and decryption.
- The security and effectiveness of this encryption method depend on the details of the algorithm, which are not fully revealed in the provided code.
- The code appears to be more of an educational or exercise nature rather than a secure encryption scheme suitable for real-world use.
