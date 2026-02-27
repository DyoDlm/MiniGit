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
./bin_server \
	"DyoDlm" \
	"foo123" \
	"repo/dir/file : content repo/file2 : content" \
	"branchA" \
	"add (cmd)"\
	"(option)" \
	". (argument)"

exit
for cmd in $cmds
do
	echo $cmd
	#./tests/cmds/$cmd.sh > $cmd.log 
	#mv $cmd.log tests/logs
done

