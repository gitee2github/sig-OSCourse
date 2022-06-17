gcc -E main1.c -o main1.i
gcc -E main2.c -o main2.i
diff main1.i main2.i
if [ $? -eq 0 ] ; then
    echo Same
else
    echo Different

fi
