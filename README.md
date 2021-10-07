# c101
A dump for all of my noob C codes, let see if I can code like what I do in other languages.

## initial setup
NOTE: Windows 10 (Administrator)
1. Download [CodeBlocks](https://www.codeblocks.org/downloads/binaries/) with MinGW setup.
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
gcc %1.c -o %1
%1
```
2. Add the Batch file's directory to Path (System variables)
3. Launch Command Prompt application
 - Locate your code directory
 - Run command: `build <filename>` (without the **.c**)
