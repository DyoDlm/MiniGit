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
./bin_server "DyoDlm" "foo123" "repo/dir/file : content \nrepo/file2 : content \nrepo/file3 : content" "add (cmd)" "(option)" ". (argument)"

exit
for cmd in $cmds
do
	echo $cmd
	#./tests/cmds/$cmd.sh > $cmd.log 
	#mv $cmd.log tests/logs
done

