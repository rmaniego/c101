# c101
A dump for all of my noob C codes, let see if I can code like what I do in other languages.

## initial setup
NOTE: This was my actual Windows 10 (Administrator) setup
1. Download [CodeBlocks](https://www.codeblocks.org/downloads/binaries/) with MinGW setup.
 - I downloaded CodeBlocks, but thought, I still prefer Notepad++ and Command Prompt
2. Once downloaded, run and complete the setup.
3. Add **MinGW/bin** to System PATH:
 - Locate and copy the full path of `C:\...\CodeBlocks\MinGW\bin`
 - Search for "Edit the system environment variables" (under System Properties > Advanced)
 - Click the **Environment Variables...** button
 - Under the System variables, edit **Path**
 - Add **MinGW/bin** to Path
4. Launch command prompt, then run `gcc -v` to verify if setup is OK.
5. Done, you can now start coding in C!

## Using GCC
```cmd
gcc <filename>.c -o <appname>
<appname>
```

## Build, Run Faster
1. Create a new CMD/Batch file, e.g. `build.cmd`
```cmd
cls
setlocal ENABLEDELAYEDEXPANSION
set f=%1
set f=%f:.c=%
cls
gcc %f%.c -o %f%
%f%
```
2. Add the Batch file's directory to Path (System variables)
3. Launch Command Prompt application
 - Locate your code directory
 - Run command: `build <filename>` (without the **.c**)

## disclaimer
1. Codes might be too bookish and not simplified, teach me senpai!
2. Some time complexity calculations may be wrong, but will be corrected as I learn how to do it properly.
3. Other things might have been overlooked, I will work on that.
