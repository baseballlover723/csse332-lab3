Usage instructions

This program copies the files in the given file with "_out" appended to the file name

"./processes #children delay_in_micro_seconds file_names"
#children is the number of child threads you want to create
delay_in_micro_seconds is the delay factor for each child process
file_names is the path to a file containing file_names, which get passed to the child processes.

example:
"./processes 4 100000 Files.txt"
