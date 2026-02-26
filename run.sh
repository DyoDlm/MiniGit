#!/bin/bash

cmds="\
	"add"\
	"commit"\
	"push"\
	"branch"\
	"checkout"\
	"pull"\
"
make fclean
make
./run_server "DyoDlm" "foo123" "file1 : content file2 : content file3 : content" "add (cmd)" "(option)" ". (argument)"

exit
for cmd in $cmds
do
	echo $cmd
	#./$cmd.sh > $cmd.log 
	#mv $cmd.log logs
done

