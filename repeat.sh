for (( i=0; i<100000; i++ ))
do
    xmacroplay -d 100 "$DISPLAY" < script.txt
done
