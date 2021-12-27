printf "\ec\n\e[44;36m\n"
cat $1 | ./txt2broken 60 | sed y/'('/'['/ | sed y/')'/']'/ > out.txt
./text2pdf out.txt out.pdf

