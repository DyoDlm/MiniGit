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
	./$cmd.sh
done
