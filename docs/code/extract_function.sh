#!/bin/bash
#
# this script extracts a function from an ELF file
# <http://arighi.blogspot.it/2013/08/how-to-extract-single-function-from-elf.html>
#
# If you want to create code from gcc use -fno-stack-protector otherwise
# extra code will be created

[[ "$#" -lt 2 ]] && {
    echo 'usage: '$0' <function name> <filename>'
    exit 1
}

SECTION=$1
IN=$2

i=`nm -S --size-sort $IN | grep "\<$SECTION\>" |
        awk '{print toupper($1),toupper($2)}'`
echo "$i" | while read line; do
        start=${line%% *}
        size=${line##* }
        end=`echo "obase=16; ibase=16; $start + $size" | bc -l`
        objdump -d --section=.text \
                   --start-address="0x$start" \
                   --stop-address="0x$end" $IN | \
                grep '[0-9a-f]:' | \
                cut -f2 -d: | \
                cut -f1-7 -d' ' | \
                tr -s ' ' | \
                tr '\t' ' ' | \
                sed 's/ $//g' | \
                sed 's/ /\\x/g' | \
                paste -d '' -s | \
                sed 's/^/"/' | \
                sed 's/$/"/g' | \
                sed 's:.*:echo -ne &:' | /bin/bash
done
