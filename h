h() {
    declare -A HMAP
    while read line
    do
        INDEX=$(echo $line | cut -d' ' -f 1)
        ENTRY=$(echo $line | cut -d' ' -f 2-)
        HMAP[$ENTRY]=$INDEX
    done < <(history | grep "$*" )
    for ENTRY in "${!HMAP[@]}"
    do
        printf "%4s %s\n"  "${HMAP[$ENTRY]}" "$ENTRY"
    done | sort -n
}
