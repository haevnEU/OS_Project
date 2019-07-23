#!/bin/bash
echo "Compiler script for OS_Project"
echo "Version 1 created by Nils Milewski at July 23 2019"
echo "This version is not usable, it will be improved over time"
PS3='Please enter your choice: '
options=("All" "Single file" "Quit")
include="./include/"
src="./src/"

select opt in "${options[@]}"
do
    case $opt in
        "All")
            echo "Compile all"
            break
            ;;
        "Single file")
            select FILENAME in ./src/* ./include/* "quit" "finish";
            do 
                echo "$FILENAME $REPLY"
                if [ "$FILENAME" = "quit" ]; then break; 
                else if [ "$FILENAME" = "finish" ]; then break; 
                else echo "COMPILING"; fi;  
            done
            break
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
