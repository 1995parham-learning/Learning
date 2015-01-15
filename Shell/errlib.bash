#!/bin/bash

function err(){
	echo
	echo "*********************************************************"
	echo
	echo -en "error: Line $1 in function ${FUNCNAME[1]}"
	echo "which is in the file ${BASH_SOURCE[1]}"
	shift
	echo "error: Message was: $@"
	echo "*********************************************************"
	echo
}
