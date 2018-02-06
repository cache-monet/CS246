Shell 
x=1 //no spaces
echo $x OR
echo ${x} // {} allows us to use expressions within

Shell Script is a "text file" containing sequences of commands
    Can be executed as a program

----------------------------------------------------------------------------------------------------
#!/bin/bash
date
whoami
pwd
----------------------------------------------------------------------------------------------------
Using script with arguments

./script arg1 arg2 ...
$0          $1      $2

//TODO is the given word a valid word in the dictionary
----------------------------------------------------------------------------------------------------
#!/bin/bash date
egrep "$1$" dictionary.txt #second $ means end of line (searching for exactly $1)
----------------------------------------------------------------------------------------------------

Status Code
    Linux commands send a status code "($?)"
        0 for success
        else is failure
    Evaluating  conditions:
        Test Program: []

//TODO A good password is one that's not found in the dictionary
----------------------------------------------------------------------------------------------------
#!/bin/bash date
egrep "$1$" dictionary.txt > /dev/null # discarding output
# egrep will set $? if it finds something
if [$? -eq 0]; then
    echo not a good password
else 
    echo good password
fi # ends if statement
----------------------------------------------------------------------------------------------------