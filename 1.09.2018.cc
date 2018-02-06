////////////////////////////////////////////////////////////////////////////////
                                        1.09.2018
////////////////////////////////////////////////////////////////////////////////

//! Bash Commands
    "ls" - list contents of directory
    "cd" - change directory
    "pwd" - print working (current) directory
    "cat" - concatentation
        Can be used to "display contents of file"
            //? cat file.txt  
    "CTRL-C" - //! KILLS THE PROGRAM
    "CTRL-D" - Signifies the end of file (ends program that runs on user input)
    "wc" - counts the words, lines, and characters of 
        wc sample.txt === wc < sample.txt
        Shell opens the file
    "cp" - copy

//! Output/Input Redirection
    //? command arg1 arg2 > destination.txt
        Direct output from command into a file
    cat sample.txt === cat < sample.txt
        In the former sample is the argument, in the latter, it is fed as an input to cat ("input redirect")
       In the latter case
            The shell opens the sample.txt and sends the contents to cat
    
General Case
    cmd arg1 arg2 ... < input > output
        input and output redirection can be used together
        //? cat < input.txt > output.txt 
        //? cat input.txt > output.txt
            both copy the contents of from input to output 
    
//! Streams

Each linux process has "3 streams" associated with it 
    Standard input (stdin)
        By default, the input is the keyboard
        Input redirection allows a file to be the input ("<")
    Standard output (stdout)
        Default output is the screen 
        Output redirection allows a file to become the ouptut (">")
    Standard error (stderr)
        Default errors are displayed on screen
        Error redirection ("2>") allows us to prevent errors from cluttering the screen
            2> as stderr is the second output 
            Standard errors is not buferred
            //TODO Look up buffered
    Buffer
        Collects tasks/command, once enough is collected the buffer "flushes" its contents (executes in blocks which is faster) 

">>" vs ">"
    ">" overwrites 
    ">>" append to end
//!Order Matters
//? cmd < input 1> out 2>&1 (&1 is the error destination)
vs
//? cmd < input 2>&1 1>output 
latter actually directs stderr to screen

//! Wildcards
    * - globbing pattern (can be anything)
        "ls *.txt"will list files that start with ANYTHING and ends with ".txt"
        The shell "intercepts" "*.txt" before it reaches "ls" and finds the files that match the pattern and places these files where "*.txt" once was 
            ls a.txt b.txt ... what actually happens
        Globbing patterns can be used with other commands
            cat *.txt (display contents of all txt files)
            echo *.txt (echo back the names of all txt files)
            rm *.txt (delete all text files)
    "" - Literals (suppress globbing patterns)
        ...except for egrep
            egrep "*d"
        //? echo "*.txt"
            will display *.txt 
    \ - escape characters
    | - pipeline
        We can send the output to the input of a nother program using Pipe
        //? cmd1 | cmd2
    ^ 
    $ - end of line
    

//TODO How many words occure in the first 20 lines of sample.txt?
    "head -20 sample.txt | wc -w"

// TODO words*.txt contains lists words (one per line) Print a duplicate free list of words in all files
    "cat words*.txt | sort | uniq"

//? What if we want to embed commands with another command?
Use $(cmd)
Note: Single quotes SUPPRESSES embedded commands
    //* Use double quotes when you need to embed commands 

//! EGREP
    returns "lines" that contain a string that matches the searched pattern
    egrep "A|B" searches for "A" or "B"
        Without the "" Shell will think we are piping A to B
    // USE "" when using characters with special meanings

//! 1.11.2018
list file names in the current directory whose name contains exactly one a
ls | egrep "^[^a]*a*[^a]*$"

file permissions:
user(owner)|group(non admins)|others

Only the owner can change file permissions
Change permissions 
"chmod mode file(s)"
//! Mode
    ownership class (u/g/o/a) operator (+/-) and permissions (rwx)
//? /chmod a - x file.txt
    removes execution priviledge for all users 