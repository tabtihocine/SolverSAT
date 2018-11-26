if [ $# -ne 1 ]; then 
echo " le solver a besoin d'un fichier CNF "
exit 1
fi 
make  
./SAT $1
make clean
echo "End of solver "
