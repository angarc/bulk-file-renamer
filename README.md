# Bulk File Renamer

It opens up a vim buffer with all of the names of the files in the directory in which you called the program. 

Then you make your edits in Vim. Once you're done, write and quit with `:wq` and all your files will be change accordingly

---

## todo
- [x] Write a quick script to get the idea across
- [ ] Write a Makefile
- [ ] Ensure it only works for files and not directories (for now)
- [ ] Add a random hash to generated files just incase a file already exists in the directory with the name `new_directory.txt` and `original_directory.txt`
- [ ] Create brew formulae and call tool `bfr`. You should be able to write `bfr .` to start the tool in the current directory
