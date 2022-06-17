if [ $# -lt 1 ] ; then
    echo Error: Need at lease one param.
    return
fi
if [ ! -f $1 ] ; then
    echo The file $1 do not exist.
    return
fi
for file in `objdump -x $1 | grep NEEDED | sed 's/NEEDED//g' | tr -d ' '`
do
    #locate $file > /dev/null
    ldconfig -p | grep $file > /dev/null
    if [ $? -ne 0 ] ; then
        if [ ! -f $file ] ; then
            echo Can not find $file
        else
            echo $file is met.
        fi
    else
        echo $file is met.
    fi
done
