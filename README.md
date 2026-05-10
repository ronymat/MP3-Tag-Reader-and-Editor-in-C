# MP3-Tag-Reader-and-Editor-in-C

A command-line based MP3 Tag Editor developed in C that allows users to view and edit metadata information of MP3 files. This project demonstrates concepts of file handling, structures, string manipulation, command-line argument processing, and modular programming in C.

## Overview

MP3 files contain metadata called ID3 tags, which store information such as:

- Song Title
- Artist Name
- Album Name
- Year
- Genre
- Comments

This project enables users to read and modify these metadata fields directly from the command line while preserving the integrity of the original MP3 file through safe file editing techniques.

---

## Features

### View MP3 Metadata
Display metadata information from an MP3 file including:

- Title
- Artist
- Album
- Year
- Genre
- Comment

### Edit Metadata
Modify specific metadata fields such as:

- Song Title
- Artist Name
- Album Name
- Year
- Genre
- Comment

### Safe File Update
Instead of modifying the original file directly:

- Creates a duplicate temporary file
- Copies existing MP3 data
- Updates only the selected metadata field
- Deletes the old file
- Renames the updated file to the original file name

This ensures better reliability and prevents corruption.

### Command Line Interface
Supports execution through terminal commands for easy usage.

---

## Technologies Used

- C Programming
- File Handling
- Structures
- Command Line Arguments
- String Functions
- Standard C Libraries

---

## How It Works

### Viewing Metadata
The program:

1. Opens the MP3 file in binary mode
2. Reads ID3 tag frames
3. Extracts metadata values
4. Displays them to the user

### Editing Metadata
The editing workflow:

1. Open original MP3 file
2. Create a duplicate temporary file
3. Copy contents frame by frame
4. Detect selected metadata frame
5. Replace old value with new user input
6. Copy remaining data
7. Close both files
8. Delete original file
9. Rename duplicate file to original file name

---

## Supported Metadata Frames

Common ID3 frames handled in this project:

| Frame ID | Description |
|--------|-------------|
| TIT2 | Title |
| TPE1 | Artist |
| TALB | Album |
| TYER / TDRC | Year |
| TCON | Genre |
| COMM | Comment |

---

## Build Instructions

Compile using GCC:

```bash
gcc main.c view.c edit.c utils.c -o mp3_editor
```

Or using Makefile:

```bash
make
```

## Key Concepts Demonstrated

This project demonstrates:

- Binary file handling
- Metadata parsing
- File pointer operations
- Temporary file handling
- String manipulation
- Command-line parsing
- Structures in C
- Modular programming
- Error handling

---

## Challenges Faced

During development, key challenges included:

- Understanding MP3 file structure
- Parsing ID3 metadata correctly
- Handling variable-length metadata fields
- Preventing file corruption during editing
- Managing temporary file replacement safely

---

## Future Improvements

Potential enhancements:

- Add support for album artwork editing
- Add batch editing for multiple files
- GUI version using GTK or Qt
- Support for more ID3 versions
- Better error validation
- Undo functionality

---

## Author

**Rony Mathew**  
Electronics and Communication Engineering Graduate  
Embedded Systems Engineer


