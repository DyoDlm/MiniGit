#!/bin/bash

cmds = "\
	"add"\
	"commit"\
	"push"\
	"branch"\
	"checkout"\
	"pull"\
	"

for cmd in $cmds
do
	./$cmd.sh > $cmd.log 
	mv $cmd.log logs
done
